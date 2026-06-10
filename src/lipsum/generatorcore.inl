/**
 * @file lipsum/generatorcore.inl
 *
 * @brief Definition of core lipsum::Generator functions
 *
 * This defines core and internal functions in lipsum::Generator. This file is
 * under the BSD Zero-Clause License.
 *
 * @copyright Copyright (c) 2026 LambBread
 *
 * @author LambBread from github.com
 */

#pragma once

#ifndef LIPSUM_GENERATORCORE_INL
#    define LIPSUM_GENERATORCORE_INL

#    include "core/internal.hpp"

#    define LPSM_ASSIGN_CHECK(name)                                            \
        isChecked = !isChecked ? assignSetting(#name, name) : true

namespace lipsum
{
    void GeneratorSettings::change_setting(const std::string& setting,
                                           const ArgVec2&     value)
    {
        auto assignSetting = [&](const char* name, ArgVec2& target) -> bool
        {
            if (setting == name)
            {
                target = value;
                return true;
            }
            return false;
        };
        bool isChecked = false;

        LPSM_ASSIGN_CHECK(word);
        LPSM_ASSIGN_CHECK(frag);
        LPSM_ASSIGN_CHECK(sent);
        LPSM_ASSIGN_CHECK(para);
        LPSM_ASSIGN_CHECK(point);
        LPSM_ASSIGN_CHECK(wordFmt);
        LPSM_ASSIGN_CHECK(fragFmt);
        LPSM_ASSIGN_CHECK(wordURL);
        LPSM_ASSIGN_CHECK(level);
        LPSM_ASSIGN_CHECK(jsonLength);
        if (!isChecked)
        {
            internal::LogWarn("lpsm::GeneratorSettings::change_setting(): "
                              "unknown "
                              "setting ",
                              setting,
                              ", ignoring");
        }
    }

    /*
     * SETUP
     */

    Generator::Generator()
    {
        m_Gen.seed(std::random_device{}());
    }

    Generator::Generator(int seed)
    {
        m_Gen.seed(seed);
    }

    Generator::Generator(const std::string& path)
    {
        load_source(path);
    }

    Generator::Generator(const std::string& path, int seed)
    {
        load_source(path);
        m_Gen.seed(seed);
    }

    void Generator::load_source(const std::string& path)
    {
        m_Source.load(path);
    }

    void Generator::load_seed(int seed)
    {
        m_Gen.seed(seed);
    }

    void Generator::change_setting(const std::string& setting,
                                   const ArgVec2&     value)
    {
        m_Settings.change_setting(setting, value);
    }

    void Generator::change_setting(const std::string& setting,
                                   int                minValue,
                                   int                maxValue)
    {
        change_setting(setting, ArgVec2(minValue, maxValue));
    }

    /*
     * PRIVATE
     */

    char Generator::random_number(char min, char max)
    {
        return static_cast<char>(
                random_number(static_cast<int>(min), static_cast<int>(max)));
    }

    bool Generator::random_number(bool min, bool max)
    {
        int choice = random_number(0, 1);
        return choice == 0 ? min : max;
    }

    int Generator::weighted_random_idx(const std::vector<int>& weights)
    {
        std::discrete_distribution<> dist(weights.begin(), weights.end());
        return dist(m_Gen);
    }

    std::string Generator::tld()
    {
        std::vector<std::string>      tlds    = {{".com"},
                                                 {".org"},
                                                 {".net"},
                                                 {".edu"},
                                                 {".io"},
                                                 {".ca"},
                                                 {".co.uk"}};
        static const std::vector<int> weights = {70, 10, 7, 5, 5, 2, 1};
        int                           idx     = weighted_random_idx(weights);
        return tlds.at(idx);
    }

    std::string Generator::single_sentence(const ArgVec2& wordArg,
                                           const ArgVec2& frag)
    {
        static const std::vector<int>         weights        = {88, 7, 3, 2};
        static const std::vector<int>         weightsEndMark = {80, 15, 5};
        static const std::vector<std::string> mapped         = {", ",
                                                                "; ",
                                                                ": ",
                                                                " - "};
        static const std::vector<std::string> mappedEndMark  = {".", "?", "!"};
        std::string                           result;
        int                                   words;
        int                                   frags = frag.roll(m_Gen);
        for (int i = 0; i < frags; ++i)
        {
            words = wordArg.roll(m_Gen);
            result += word(words);
            int check = weighted_random_idx(weights);
            // don't do if only one fragment
            if (i != frags - 1)
            {
                result += mapped.at(check);
            }
        }
        result += mappedEndMark.at(weighted_random_idx(weightsEndMark));
        result.at(0) = LPSM_SAFE_CCTYPE(char, std::toupper, result.at(0));
        return result;
    }

    std::string Generator::single_paragraph(bool useLipsum)
    {
        std::string result = "\t";
        int         sents  = m_Settings.sent.roll(m_Gen);
        for (int i = 0; i < sents; ++i)
        {
            if (i == 0 && useLipsum)
            {
                result += GenerateDefaultLipsumSentence() += " ";
            }
            else
            {
                result += single_sentence(m_Settings.word, m_Settings.frag) +=
                        " ";
            }
        }

        if (!result.empty())
        {
            // remove trailing space
            result.pop_back();
        }
        result += "\n";
        return result;
    }

    std::string Generator::single_fmt_paragraph(bool useLipsum, bool useHtml)
    {
        std::string ret;
        int         sents = m_Settings.sent.roll(m_Gen);
        int         fmtRoll;
        bool        addLink;
        bool        isBold;
        if (useHtml)
        {
            ret += "<p>";
        }
        for (int i = 0; i < sents; ++i)
        {
            fmtRoll = m_Settings.sent.roll(m_Gen);
            addLink = LPSM_FLIP_COIN;
            isBold  = LPSM_FLIP_COIN;
            if (i == 0 && useLipsum)
            {
                ret += GenerateDefaultLipsumSentence();
            }
            else if ((fmtRoll == m_Settings.sent.min) && addLink)
            {
                ret += fmt_link(useHtml);
            }
            else if ((fmtRoll == m_Settings.sent.min) && !addLink)
            {
                ret += fmt_emphasis(isBold, useHtml);
            }
            else
            {
                ret += single_sentence(m_Settings.word, m_Settings.frag);
            }
            ret += " ";
        }
        if (useHtml)
        {
            ret += "</p>";
        }
        ret += "\n\n";
        return ret;
    }

    std::string Generator::json_string()
    {
        return std::string("\"") + m_Source.random_word(m_Gen) + "\"";
    }

    std::string Generator::json_number()
    {
        constexpr int JSON_NUMBER_MIN = -1000;
        constexpr int JSON_NUMBER_MAX = 1000;
        return internal::ToString(
                random_number(JSON_NUMBER_MIN, JSON_NUMBER_MAX));
    }
} // namespace lipsum
#endif

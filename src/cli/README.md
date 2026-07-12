# lipsum-cpp CLI

This is a CLI tool for lipsum-cpp. It contains subcommands for every `lpsm::Generator` function.
For more info, type `lpsmcpp-cli help`. There is also an interactive CLI tool, `lpsmcpp-interactive`.

```
Usage: lpsmcpp-cli <subcommand> [<arguments>] [<options>]

Options include:
  --help, -h - Show this help
  --version, -v - Show the current version of lipsum-cpp.
  --seed=<seed>, -E - Load specified seed.
  --output=<file>, -o - Output to the specified file.
  --source=<source>, -S - Load specified source.
      <source> may be a path to a file or a built-in source.
      Built in sources include: default/lorem, cat, dog/doggo, corpo/corporate.

  --bulk - Separate bulk operations.
      Example: lpsmcpp-cli paragraph 2 --bulk sentence 4

  --word=<min,max>, -w - The min and max words per sentence fragment.
  --frag=<min,max>, -f - The min and max sentence fragments per sentence.
  --sent=<min,max>, -s - The min and max sentences per paragraph.
  --para=<min,max>, -p - The min and max paragraphs per text.
  --point=<min,max>, -P - The min and max points per list.
  --wordURL=<min,max>, -u - The min and max words in headings, in slugs, and at the end of URLs.
  --wordFmt=<min,max>, -W - The min and max words per formatted sentence fragment.
  --fragFmt=<min,max>, -F - The min and max sentence fragments per formatted sentence.
  --level=<min,max>, -l - The min and max levels of headings.
  --jsonLength=<min,max>, -j - The min and max amount of items in JSON objects.
  --csvRows=<min,max>, -R - The min and max number of rows in CSV documents.
  --csvCols=<min,max>, -C - The min and max number of columns in CSV documents.
Subcommands include:
  help, word, fragment, sentence, paragraph, text,
  url, plain_url, email, slug, scramble, case_slug, code, 
  fmt_paragraph, fmt_text, fmt_header, fmt_emphasis, fmt_link, fmt_list, 
  xml, json, json_value, csv

For more information, type lpsmcpp-cli help <subcommand>.
```

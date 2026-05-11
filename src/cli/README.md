# lipsum-cpp CLI

This is a CLI tool for lipsum-cpp. It contains subcommands for every `lpsm::Generator` function.
For more info, type `lpsmcpp-cli help`.
```
Usage: lpsmcpp-cli <subcommand> [<arguments>] [<options>]

Valid options include:
  --help, -h - Show this help
  --version, -v - Show the current version of lipsum-cpp.
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
  --source=<source>, -S - Load specified source.
      <source> may be a filepath to a file or a built-in source.
      Built in sources include: default/lorem, cat, dog/doggo, corpo/corporate.

Valid subcommands include:
  help - Show this help.

  word <num = 1> - Generate words.
    num - The number of words.

  fragment - Generate a sentence fragment.

  sentence <num = 1> <useLipsum = true> - Generate sentences.
    num - The number of sentences.
    useLipsum - Whether 'Lorem ipsum...' should start the sentences.

  paragraph <num = 1> <useLipsum = true> - Generate paragraphs.
    num - The number of paragraphs.
    useLipsum - Whether 'Lorem ipsum...' should start the first sentence.

  text <useLipsum = true> - Generate a text.
    useLipsum - Whether 'Lorem ipsum...' should start the first sentence.

  scramble <length = 16> <minChar = 32> <maxChar = 126> - Generate a character scramble.
    length - The number of characters.
    minChar - The lowest ASCII value possible.
    maxChar - The highest ASCII value possible.

  url - Generate a URL.

  plain_url - Generate a plain URL.

  slug <separator = '-'> - Generate a slug.
    separator - The separator to use.

  md_paragraph <num = 1> <useLipsum = true> <useHtml = false> - Generate Markdown paragraphs.
    num - The number of paragraphs.
    useLipsum - Whether 'Lorem ipsum...' should start the first sentence.
    useHtml - Whether HTML should be outputted instead of Markdown.

  md_text <numElements = 15> <useHtml = false> - Generate a Markdown document
    numElements - The number of elements.
    useHtml - Whether HTML should be outputted instead of Markdown.

  md_header <level = 1> <useHtml = false> - Generate a Markdown header.
    level - The level of the heading.
    useHtml - Whether HTML should be outputted instead of Markdown.

  md_emphasis <isBold = true> <useHtml = false> - Generate an emphasized Markdown sentence.
    isBold - Whether the sentence is bold or italic.
    useHtml - Whether HTML should be outputted instead of Markdown.

  md_link <useHtml = false> - Generate a Markdown link.
    useHtml - Whether HTML should be outputted instead of Markdown.

  md_list <ordered = false> <useHtml = false> - Generate a Markdown list.
    ordered - Whether the list is ordered.
    useHtml - Whether HTML should be outputted instead of Markdown.

  xml <choices = 30> - Generate an XML document.
    choices - The number of 'choices' to make.

  json <maxDepth = 3> <isObject = true> - Generate a JSON object or array.
    maxDepth - The maximum recursion depth.
    isObject - Whether the output is an object or an array.
```

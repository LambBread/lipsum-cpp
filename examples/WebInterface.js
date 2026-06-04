const $ = e => document.querySelector(e);
createLipsumCpp().then(Module => 
{
    const funcSelect = $("#func");
    const selectButton = $("#generate");
    const output = $("#output");
    const gen = new Module.lpsm_Generator();
    //console.log(gen.slug("-"));
    $("#version").textContent = 
        `lipsum-cpp version ${Module.LIPSUM_CPP_VERSION_FULL}`;
    output.value = gen.paragraph(1);
    
    selectButton.addEventListener("click", function()
    {
        const num = $("#num").value;
        const separator = $("#separator").value.charCodeAt(0);
        const maxChar = $("#maxChar").value.charCodeAt(0);
        const useLipsum = $("#useLipsum").checked;
        const useHtml = $("#useHtml").checked;
        console.log(useLipsum)
        if(funcSelect.value === "slug")
        {
            output.value = gen.slug(separator);
        }
        else if(funcSelect.value === "scramble")
        {
            output.value = gen.scramble(num, separator, maxChar);
        }
        else if(funcSelect.value === "md_paragraph")
        {
            output.value = gen.md_paragraph(num, useLipsum, useHtml);
        }
        else if(funcSelect.value === "md_link")
        {
            output.value = gen.md_link(useHtml);
        }
        else if(funcSelect.value === "text")
        {
            output.value = gen.text(useLipsum);
        }
        else if(["json", "json_value"].includes(funcSelect.value))
        {
            output.value = gen[funcSelect.value](0, num, useLipsum);
        }
        else if(["word", "fragment", "sentence",
            "paragraph", "url", "plain_url", "xml"].includes(funcSelect.value))
        {
            //console.log(funcSelect.value);
            output.value = gen[funcSelect.value](num, useLipsum);
        }
        else if(["md_text", "md_header"].includes(funcSelect.value))
        {
            output.value = gen[funcSelect.value](num, useHtml);
        }
        else if(["md_emphasis", "md_list"].includes(funcSelect.value))
        {
            output.value = gen[funcSelect.value](useLipsum, useHtml);
        }
    })
})

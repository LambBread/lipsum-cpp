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
        //console.log(useLipsum)
        if(funcSelect.value === "slug")
        {
            output.value = gen.slug(separator);
        }
        else if(funcSelect.value === "scramble")
        {
            output.value = gen.scramble(num, separator, maxChar);
        }
        else if(funcSelect.value === "fmt_paragraph")
        {
            output.value = gen.fmt_paragraph(num, useLipsum, useHtml);
        }
        else if(funcSelect.value === "fmt_link")
        {
            output.value = gen.fmt_link(useHtml);
        }
        else if(funcSelect.value === "text")
        {
            output.value = gen.text(useLipsum);
        }
        else if(["json", "json_value"].includes(funcSelect.value))
        {
            output.value = gen[funcSelect.value](num, useLipsum);
        }
        else if(funcSelect.value == "code")
        {
            //console.log(num)
            //console.log(num === "1")
            let val = Module.lpsm_CodeLanguage.Cpp;
            switch(num)
            {
                case "1":
                {
                    val = Module.lpsm_CodeLanguage.Python;
                    break;
                }
                case "2":
                {
                    val = Module.lpsm_CodeLanguage.Rust;
                    break;
                }
                case "3":
                {
                    val = Module.lpsm_CodeLanguage.C;
                    break;
                }
                case "4":
                {
                    val = Module.lpsm_CodeLanguage.JavaScript;
                    break;
                }
            }
            //console.log(val);
            output.value = gen.code(val);
        }
        else if(funcSelect.value == "case_slug")
        {
            let asEnum = Module.lpsm_CaseSlugCase.CamelCase;
        
            switch(num)
            {
                case "0":
                {
                    asEnum = Module.lpsm_CaseSlugCase.CamelCase;
                    break;
                }
                case "1":
                {
                    asEnum = Module.lpsm_CaseSlugCase.PascalCase;
                    break;
                }
                case "2":
                {
                    asEnum = Module.lpsm_CaseSlugCase.SnakeCase;
                    break;
                }
                case "3":
                {
                    asEnum = Module.lpsm_CaseSlugCase.ShoutyCase;
                    break;
                }
                case "4":
                {
                    asEnum = Module.lpsm_CaseSlugCase.KebabCase;
                    break;
                }
                case "5":
                {
                    asEnum = Module.lpsm_CaseSlugCase.TrainCase;
                    break;
                }
            }
            output.value = gen.case_slug(asEnum);
        }
        else if(["word", "fragment", "sentence",
            "paragraph", "url", "plain_url", "xml", 
            "email", "csv"].includes(funcSelect.value))
        {
            //console.log(funcSelect.value);
            output.value = gen[funcSelect.value](num, useLipsum);
        }
        else if(["fmt_text", "fmt_header"].includes(funcSelect.value))
        {
            output.value = gen[funcSelect.value](num, useHtml);
        }
        else if(["fmt_emphasis", "fmt_list"].includes(funcSelect.value))
        {
            output.value = gen[funcSelect.value](useLipsum, useHtml);
        }
    })
})

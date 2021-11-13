var C;
var g_niceEditors;
var g_inpTextAreaControl = [];
var g_outTextAreaControl = [];
var STD_TEXTAREA_CTL_CONST = 0;
var NICE_TEXTAREA_CTL_CONST = 1;
var TEXTAREA_INP_CONST = 0;
var TEXTAREA_OUT_CONST = 1;
var g_currentTextAreaCtlShown = [];
var g_currentTextAreaCtlShown_locator = [];
var g_paddingChar_preserveText = "\v"; // vertical character... to be removed later. This is needed so that regexp can detect it later...
var g_textArea_NicEditorMap = [
    // input control details
    {textAreaCtlStr:"ip-file-content",
    stdTextAreaCtlLoc:STD_TEXTAREA_CTL_CONST,
    niceTextAreaCtlLoc:NICE_TEXTAREA_CTL_CONST,
    inpTextAreaArrLoc:TEXTAREA_INP_CONST,
    outTextAreaArrLoc:TEXTAREA_OUT_CONST,
    nicEditiorCtlStr:"",
    },
    //output control details
    {textAreaCtlStr:"Tool_Execute_Result",
    stdTextAreaCtlLoc:STD_TEXTAREA_CTL_CONST,
    niceTextAreaCtlLoc:NICE_TEXTAREA_CTL_CONST,
    inpTextAreaArrLoc:TEXTAREA_INP_CONST,
    outTextAreaArrLoc:TEXTAREA_OUT_CONST,
    nicEditiorCtlStr:"",
    },

];

bkLib.onDomLoaded(function() { 
    g_niceEditors = nicEditors.allTextAreas(C,g_textArea_NicEditorMap[TEXTAREA_INP_CONST].textAreaCtlStr,g_textArea_NicEditorMap[TEXTAREA_OUT_CONST].textAreaCtlStr);
    var tempCtl = null;
    tempCtl = nicEditors.findEditor(g_textArea_NicEditorMap[TEXTAREA_INP_CONST].textAreaCtlStr);
    g_inpTextAreaControl[STD_TEXTAREA_CTL_CONST] = tempCtl.e;
    g_inpTextAreaControl[NICE_TEXTAREA_CTL_CONST] = tempCtl.elm;
    g_inpTextAreaControl[NICE_TEXTAREA_CTL_CONST].style.maxHeight= tempCtl.elm.style.minHeight;
    g_inpTextAreaControl[NICE_TEXTAREA_CTL_CONST].style.overflow = "auto";

    tempCtl = nicEditors.findEditor(g_textArea_NicEditorMap[TEXTAREA_OUT_CONST].textAreaCtlStr);
    g_outTextAreaControl[STD_TEXTAREA_CTL_CONST] = tempCtl.e;
    g_outTextAreaControl[NICE_TEXTAREA_CTL_CONST] = tempCtl.elm;
    g_outTextAreaControl[NICE_TEXTAREA_CTL_CONST].style.maxHeight= tempCtl.elm.style.minHeight;
    g_outTextAreaControl[NICE_TEXTAREA_CTL_CONST].style.overflow = "auto";
    switchTextAreaControls (g_inpTextAreaControl[NICE_TEXTAREA_CTL_CONST], true, g_inpTextAreaControl[STD_TEXTAREA_CTL_CONST], false, TEXTAREA_INP_CONST);
    switchTextAreaControls (g_outTextAreaControl[NICE_TEXTAREA_CTL_CONST], true, g_outTextAreaControl[STD_TEXTAREA_CTL_CONST], false, TEXTAREA_OUT_CONST);
    createModalWindow("windowGroup", "window", false, 1);

});
       
var g_processButtonCtlsArr_fontMapper = [];
var g_processButtonCtlsArr_fontConv = [];
var g_childCtlObjArr = [];

function resetAllGlobalData () {
    var i = 0, j=0;
    while (g_childCtlObjArr.length>0) {
        g_childCtlObjArr.pop();
        }
}
function switchTextAreaControls (niceTextAreaCtl, bShow1, stdTextAreaCtl, bShow2, arrLoc) {
    if (stdTextAreaCtl == null || niceTextAreaCtl == null) return;
    niceTextAreaCtl.style.display = bShow1?"block":"none";
    stdTextAreaCtl.style.display = bShow2?"block":"none";
    // both bShow1 and bShow 2 cannot be true, as only standard or nice edits are shown.    
    if (bShow1 == true) {
        g_currentTextAreaCtlShown[arrLoc] = niceTextAreaCtl; 
        g_currentTextAreaCtlShown_locator[arrLoc] = NICE_TEXTAREA_CTL_CONST;
    }
    if (bShow2 == true) {
        g_currentTextAreaCtlShown[arrLoc] = stdTextAreaCtl;
        g_currentTextAreaCtlShown_locator[arrLoc] =  STD_TEXTAREA_CTL_CONST;
    }
}
function getSetContent_TextAreas_Adv (textAreaCtl, bGetText, contentsToUpdate, bUseCtlForContents=false, inputCtl=null) {
    var textAreaChild_CtlObjArr = [];
    if (bGetText){
        resetAllGlobalData ();
        if(textAreaCtl.nodeName.toLowerCase() == "textarea") {
            var tempObj = getNewTextAreaChildObj();
            tempObj.childCtl = textAreaCtl;
            tempObj.orjText = textAreaCtl.innerText || textAreaCtl.contents || textAreaCtl.value || textAreaCtl.textContent ;
            tempObj.innerHTML = textAreaCtl.innerHTML;        
            textAreaChild_CtlObjArr.push(tempObj);
            } else {
                textAreaChild_CtlObjArr = getAllDescendant (textAreaCtl);
            }
    } else {
        var l_contentsToUpdate = contentsToUpdate;
        if (textAreaCtl.nodeName.toLowerCase() == "textarea"){
            if (inputCtl!=null && bUseCtlForContents) 
                l_contentsToUpdate = inputCtl.value || inputCtl.textContent ;
            textAreaCtl.textContent = textAreaCtl.value = l_contentsToUpdate;
        } else {
            if (inputCtl!=null && bUseCtlForContents) 
                l_contentsToUpdate = inputCtl.innerHTML;
            textAreaCtl.innerHTML = l_contentsToUpdate;            
        }
    }
    return textAreaChild_CtlObjArr;
}
function getAllDescendant (node) {
    var tempObj;
    if (node.childNodes.length ==0) {
        tempObj = getNewTextAreaChildObj ();
        tempObj.childCtl = node;
        tempObj.orjText = node.innerText || node.contents || node.value || node.textContent ;
        tempObj.innerHTML = node.innerHTML;        
        g_childCtlObjArr.push(tempObj); 
        return g_childCtlObjArr;
    }
    for (var i = 0; i < node.childNodes.length; i++) {
      var child = node.childNodes[i];
      getAllDescendant(child);
    }
    return g_childCtlObjArr;
}
function getNewTextAreaChildObj (){
    var objToReturn = {
            childCtl:null,
            orjText:"",
            newText:"",
            innerHTML:"",
            };
    return objToReturn;
}
function getSetContent_TextAreas (textAreaCtl, bGetText, contentsToUpdate) {
    var textToreturn = "";
    if (bGetText){
        return textToreturn = (textAreaCtl.nodeName.toLowerCase() == "textarea")?textAreaCtl.value:textAreaCtl.innerHTML;
    } else {
        if (textAreaCtl.nodeName.toLowerCase() == "textarea"){
            textAreaCtl.value = contentsToUpdate;
        } else {
            textAreaCtl.innerText = contentsToUpdate;            
        }
        return "";
    }
}
function onSwitchTextAreaCtl(switchTextAreaCtlStr, labelCtlStr, preserveTextFormatCtlStr, preserveTextFormatLabelStr) {
    var switchTextAreaCtl = document.getElementById(switchTextAreaCtlStr);
    var labelCtl = document.getElementById(labelCtlStr);
    var preserveTextFormatCtl = document.getElementById(preserveTextFormatCtlStr);
    var preserveTextFormatLabel = document.getElementById(preserveTextFormatLabelStr);


    var textAreaCtlState_Show, textAreaCtlState_Hide;
    if (switchTextAreaCtl.checked) {
        labelCtl.innerHTML = "Uncheck: To use Nice Textarea";
        textAreaCtlState_Show = STD_TEXTAREA_CTL_CONST;
        textAreaCtlState_Hide = NICE_TEXTAREA_CTL_CONST;
        preserveTextFormatCtl.style.display = "none";
        //preserveTextFormatCtl.checked = true; // set to true for now
        preserveTextFormatLabel.style.display = "none";        

    }else {
        labelCtl.innerHTML = "Check: To use Std. Textarea";
        textAreaCtlState_Show = NICE_TEXTAREA_CTL_CONST;
        textAreaCtlState_Hide = STD_TEXTAREA_CTL_CONST;
        preserveTextFormatCtl.style.display = "block";
        //preserveTextFormatCtl.checked = true;
        preserveTextFormatLabel.style.display = "block";        
    }
    onCheckPreserveTextFormat(preserveTextFormatCtlStr);
    switchTextAreaControls (g_inpTextAreaControl[textAreaCtlState_Show], true, g_inpTextAreaControl[textAreaCtlState_Hide], false, TEXTAREA_INP_CONST);
    switchTextAreaControls (g_outTextAreaControl[textAreaCtlState_Show], true, g_outTextAreaControl[textAreaCtlState_Hide], false, TEXTAREA_OUT_CONST);

}
function onCheckPreserveTextFormat(preserveTextFormatCtlStr) {
    var preserveTextFormatCtl = document.getElementById(preserveTextFormatCtlStr);
    g_preserveTextFormat = preserveTextFormatCtl.checked;
    var inpTextArea = g_currentTextAreaCtlShown[TEXTAREA_INP_CONST];
//    if (inpTextArea.style.color == "red") inpTextArea.style.color = "Green";else {inpTextArea.style.color = "red";}
    var inpHTML = cleanPaste(inpTextArea.innerHTML);
    inpTextArea.innerHTML = inpHTML;
    var contentsArr = getSetContent_TextAreas_Adv(inpTextArea, true, ""); // get the contents
    for (var i=0; i<contentsArr.length; i++) {
        if (contentsArr[i].orjText == null) continue;
        var contents = contentsArr[i].orjText;
        //contents = myTrim(contentsArr[i].orjText, true, true);
        if (contentsArr[i].childCtl != null && contents !="") {
            //contentsArr[i].childCtl.textContent = '&#0020;'+contents+'&#0020;';
            contentsArr[i].childCtl.textContent = g_paddingChar_preserveText+contents+g_paddingChar_preserveText;
            if ((contentsArr[i].childCtl.parentNode.nodeName.toLowerCase() != "b"&& contentsArr[i].childCtl.parentNode.nodeName.toLowerCase() != "strong")
            && (contentsArr[i].childCtl.parentNode.parentNode.nodeName.toLowerCase() != "b"&& contentsArr[i].childCtl.parentNode.parentNode.nodeName.toLowerCase() != "strong") ) {
                contentsArr[i].childCtl.parentNode.style.fontWeight="normal";
                if (contents.indexOf('\u00A0') !=-1 ) {
                    contents = contents.replace(/\u00A0/gi, " ");
                }
//                contentsArr[i].childCtl.innerHTML = "<span style=\"font-weight:normal;color=blue;\"&bsp;>"+(contentsArr[i].childCtl.textContent ||contentsArr[i].childCtl.value || contentsArr[i].newText)+"&bsp;</span>";
            } else {
                contentsArr[i].childCtl.parentNode.style.fontWeight="bold";
//                contentsArr[i].childCtl.innerHTML = "<span style=\"font-weight:bold;\">&bsp;"+(contentsArr[i].childCtl.textContent ||contentsArr[i].childCtl.value || contentsArr[i].newText)+"&bsp;</span>";
            }
        }
    }

    //getSetContent_TextAreas_Adv(inpTextArea, false, inpHTML); // place the contents of input into output area, to preserve format
    
}
//==============
var CleanWordHTML = function ( str )
{
str = str.replace(/<o:p>\s*<\/o:p>/g, "") ;
str = str.replace(/<o:p>.*?<\/o:p>/g, "&nbsp;") ;
str = str.replace( /\s*mso-[^:]+:[^;"]+;?/gi, "" ) ;
str = str.replace( /\s*MARGIN: 0cm 0cm 0pt\s*;/gi, "" ) ;
str = str.replace( /\s*MARGIN: 0cm 0cm 0pt\s*"/gi, "\"" ) ;
str = str.replace( /\s*TEXT-INDENT: 0cm\s*;/gi, "" ) ;
str = str.replace( /\s*TEXT-INDENT: 0cm\s*"/gi, "\"" ) ;
str = str.replace( /\s*TEXT-ALIGN: [^\s;]+;?"/gi, "\"" ) ;
str = str.replace( /\s*PAGE-BREAK-BEFORE: [^\s;]+;?"/gi, "\"" ) ;
str = str.replace( /\s*FONT-VARIANT: [^\s;]+;?"/gi, "\"" ) ;
str = str.replace( /\s*tab-stops:[^;"]*;?/gi, "" ) ;
str = str.replace( /\s*tab-stops:[^"]*/gi, "" ) ;
str = str.replace( /\s*face="[^"]*"/gi, "" ) ;
str = str.replace( /\s*face=[^ >]*/gi, "" ) ;
str = str.replace( /\s*FONT-FAMILY:[^;"]*;?/gi, "" ) ;
str = str.replace(/<(\w[^>]*) class=([^ |>]*)([^>]*)/gi, "<$1$3") ;
str = str.replace( /<(\w[^>]*) style="([^\"]*)"([^>]*)/gi, "<$1$3" ) ;
str = str.replace( /\s*style="\s*"/gi, '' ) ; 
str = str.replace( /<SPAN\s*[^>]*>\s*&nbsp;\s*<\/SPAN>/gi, '&nbsp;' ) ; 
str = str.replace( /<SPAN\s*[^>]*><\/SPAN>/gi, '' ) ; 
str = str.replace(/<(\w[^>]*) lang=([^ |>]*)([^>]*)/gi, "<$1$3") ; 
str = str.replace( /<SPAN\s*>(.*?)<\/SPAN>/gi, '$1' ) ; 
str = str.replace( /<FONT\s*>(.*?)<\/FONT>/gi, '$1' ) ;
str = str.replace(/<\\?\?xml[^>]*>/gi, "") ; 
str = str.replace(/<\/?\w+:[^>]*>/gi, "") ; 
str = str.replace( /<H\d>\s*<\/H\d>/gi, '' ) ;
str = str.replace( /<H1([^>]*)>/gi, '' ) ;
str = str.replace( /<H2([^>]*)>/gi, '' ) ;
str = str.replace( /<H3([^>]*)>/gi, '' ) ;
str = str.replace( /<H4([^>]*)>/gi, '' ) ;
str = str.replace( /<H5([^>]*)>/gi, '' ) ;
str = str.replace( /<H6([^>]*)>/gi, '' ) ;
str = str.replace( /<\/H\d>/gi, '<br>' ) ; //remove this to take out breaks where Heading tags were 
str = str.replace( /<(U|I|STRIKE)>&nbsp;<\/\1>/g, '&nbsp;' ) ;
str = str.replace( /<(B|b)>&nbsp;<\/\b|B>/g, '' ) ;
str = str.replace( /<([^\s>]+)[^>]*>\s*<\/\1>/g, '' ) ;
str = str.replace( /<([^\s>]+)[^>]*>\s*<\/\1>/g, '' ) ;
str = str.replace( /<([^\s>]+)[^>]*>\s*<\/\1>/g, '' ) ;
//some RegEx code for the picky browsers
var re = new RegExp("(<P)([^>]*>.*?)(<\/P>)","gi") ;
str = str.replace( re, "<div$2</div>" ) ;
var re2 = new RegExp("(<font|<FONT)([^*>]*>.*?)(<\/FONT>|<\/font>)","gi") ; 
str = str.replace( re2, "<div$2</div>") ;
str = str.replace( /size|SIZE = ([\d]{1})/g, '' ) ;
return str ;
}



var cleanPaste = function(html) {
    // Run the standard YUI cleanHTML method
    //html = this.Editor.cleanHTML(html);

    // Remove additional MS Word content
//    html = html.replace(/<(\/)*(\\?xml:|meta|link|span|font|del|ins|st1:|[ovwxp]:)((.|\s)*?)>/gi, ''); // Unwanted tags
    html = html.replace(/<(\/)*(\\?xml:|meta|link|font|del|ins|st1:|[ovwxp]:)((.|\s)*?)>/gi, ''); // keep span
//    html = html.replace(/(class|style|type|start)=("(.*?)"|(\w*))/gi, ''); // Unwanted sttributes
    html = html.replace(/(class|type|start)=("(.*?)"|(\w*))/gi, ''); // Unwanted sttributes; keep the style
    html = html.replace(/<style(.*?)style>/gi, '');   // Style tags
    html = html.replace(/<script(.*?)script>/gi, ''); // Script tags
    html = html.replace(/<!--(.*?)-->/gi, '');        // HTML comments
    if (html.indexOf('\u00A0')!=-1)
    html = html.replace(/[\u00A0]/gi, '\u0020');        // HTML spaces
    return html;
}





//===============
function enterDesignMode()
{
    var pwd="", pwd1="Govinda*108:show", pwd2="Govinda*108:hide";
    var ver =getVersionObject();

    var verStr = "Version:"+ ver.versionString +"\rHtml file Version: "+ver.htmlVersion+ "\rVersion Format: "+ver.versionStrDesc +"\r";
    pwd = prompt( verStr, "Govinda*108:show", "Enter Password");
    if (pwd != null && (pwd == pwd1 || pwd == pwd2))
    {
        //alert ("Password accepted - Some of the additional features will now be enabled!!!!");
        var controlsToShowHide = {'0':"confirm_translit_prmpt", '1':"Spell_check_options_group", '2':"more_tools_group", '3':"Bengali Verse", '4':"Tamil Pasuram", '5':"English2Devanagari", '6':"Tamil2Devanagari"};
        var bShowStr = "block", i, inp;
        if (pwd==pwd1) bShowStr="block";else bShowStr="none";
        //alert (bShowStr+controlsToShowHide.length);
        for (i = 0;  controlsToShowHide[i] != null; i++)
        {
            inp = document.getElementById(controlsToShowHide[i]);
            if (inp != null)            inp.style.display=bShowStr;
        }
 // enable all of the selections for the SELECT use_numbers
        var useNumSelection = document.getElementById ("use_numbers");
        for (i=0; i< useNumSelection.options.length; i++) {
            useNumSelection.options [i].style.display="block";
        }
    } else {
        alert ("Incorrect password \r Intensely Chant......... \rGovinda! Govinda! Govinda!.... 108 times! and then type:show or :hide \r                 .................and be happy!");
    }
}
function updateVersion (ver)
{
//alert("getVersion");
    var inp = document.getElementById('version_str');
    inp.disabled = true;
    inp.innerHTML= "T.Engine Ver: "+ver.versionString+" <BR> T.HTML Ver: "+ver.htmlVersion;
}
function onSlokaTypeChange()
{
    var i, opt2;
    var tObj = getTransliterationObject ();
    var showHideStr = ["display:none", "display:block"];
    var showHideIndex = 0;
    var ver =getVersionObject();
   
    var inp = document.getElementById('sloka_type');
    var inp2 = document.getElementById('TransOption');

    var optList = tObj.translitFuncList;
    var optItemListCount = 0;
    for (i = 0; i< optList.length; i++)
    {
        if (i== inp.selectedIndex && ver.slokaVerseTypeInst[i] != 0)
        {
//    alert (i);
            showHideIndex = 1;
        }
        else
        {
            showHideIndex = 0;
        }
        for (j=0; j< optList[i].length; j++)
        {
            opt2 = document.getElementById(optList[i][j]+"_"+String(optItemListCount++));
            opt2.setAttribute("style", showHideStr[showHideIndex]);
//            alert (i+","+j+","+opt2.id+",show = "+showHideIndex);
        }
    }

}
function setupPage ()
{
    var ver =getVersionObject();

    updateVersion(ver);
    var i, opt, textNode, opt2, textNode2, opt3, textNode3, opt4, textNode4;
    var tObj = getTransliterationObject ();
    var showHideStr = ["display:none", "display:block"];
    var showHideIndex = 0;
    
    var inp = document.getElementById('sloka_type');
    var inp2 = document.getElementById('TransOption');
    var inp3 = document.getElementById('wordSepList');
    var inp4 = document.getElementById('convert_unicode');


    for (i = 0; i< tObj.slokaTypeList.length; i++)
    {
        opt = document.createElement("option");
        opt.setAttribute("value", tObj.slokaTypeList[i]);
        opt.setAttribute("id", tObj.slokaTypeList[i]);
        opt.setAttribute("style", showHideStr[ver.slokaVerseTypeInst[i]]);
        textNode = document.createTextNode(tObj.slokaTypeList[i]);
        opt.appendChild(textNode);
        inp.appendChild(opt);
    }
    inp.selectedIndex = tObj.selSlokaTypeIndex;
    var optList = tObj.translitFuncList;
    var optItemListCount = 0;
    for (i = 0; i< optList.length; i++)
    {
        if (i== inp.selectedIndex && ver.slokaVerseTypeInst[i] != 0)
        {
            showHideIndex = 1;
        }
        else
        {
            showHideIndex = 0;
        }
        
        for (j=0; j< optList[i].length; j++)
        {
        opt2 = document.createElement("option");
        opt2.setAttribute("id", optList[i][j]+"_"+String(optItemListCount));
        opt2.setAttribute("style", showHideStr[showHideIndex]);
        opt2.setAttribute("value", String(j));
        textNode2 = document.createTextNode(optList[i][j]);
        opt2.appendChild(textNode2);
        inp2.appendChild(opt2);
        optItemListCount++;
        }
    }
    for (i = 0; i< tObj.wordSepLabel.length; i++)
    {
        opt3 = document.createElement("option");
        opt3.setAttribute("value", String(i));
        opt3.setAttribute("id", tObj.wordSepLabel[i]);
        opt3.setAttribute("style", "display:block");
        textNode3 = document.createTextNode(tObj.wordSepLabel[i]);
        opt3.appendChild(textNode3);
        inp3.appendChild(opt3);
    }
    for (i = 0; i< tObj.supportedConversionFontFamily_map.length; i++)
    {
        opt4 = document.createElement("option");
        opt4.setAttribute("value", tObj.supportedConversionFontFamily_map[i][1]);
        opt4.setAttribute("id", tObj.supportedConversionFontFamily_map[i][1]);
        opt4.setAttribute("style", "display:block");
        textNode4 = document.createTextNode(tObj.supportedConversionFontFamily_map[i][0]);
        opt4.appendChild(textNode4);
        inp4.appendChild(opt4);
    }

    var arrayControlsStr_fontMapper = [
        {ctl:"load_font_mapper_static", bEnable: true, bShow: true,},
        {ctl:"load_font_mapper_file",bEnable: true, bShow: true,},
        {ctl:"font_mapper_from_server_listCtl",bEnable: true, bShow: true,},
        ];
    var arrayControlsStr_fontConv = [
        {ctl:"convert_to_uni",bEnable: true, bShow: true,},
        {ctl:"convert_to_non_uni",bEnable: true, bShow: true,},
    ];
    
    loadGlobalControlsArray (arrayControlsStr_fontMapper, g_processButtonCtlsArr_fontMapper);
    loadGlobalControlsArray (arrayControlsStr_fontConv, g_processButtonCtlsArr_fontConv);
    inp4.selectedIndex = 0;
    inp4.dispatchEvent(new Event('change', { bubbles: true })); 
    
    var fontMapperFileExtStr =".csv", folder = "fontMappers_list.html";
    loadDataFileList_FromServer('font_mapper_from_server_listCtl', folder, fontMapperFileExtStr);
    
}
window.onload = function(){
    setupPage ();
}


function checkWordToWord (inpData, outputTextArea)
{
    var transliterateObj = getTransliterationObject ();
    var sel = document.getElementById('sloka_type');    
    transliterateObj.selSlokaTypeIndex = sel.selectedIndex;
    var trans = document.getElementById ('TransOption');
    transliterateObj.selTransFunction = trans.value;
    var useNum = document.getElementById ('use_numbers');
    transliterateObj.bUseNumbers = useNum.checked;
    var promptTrans = document.getElementById ('confirm_translit');
    transliterateObj.bSmartTranslit_Prompt = promptTrans.checked;
    var wordSep = document.getElementById('wordSepList');
    var bCheckEngForITRANS = document.getElementById('engITransCheck').checked;
    transliterateObj.bCheckEngForITRANS = bCheckEngForITRANS;
    transliterateObj.wordSeparator= transliterateObj.wordSep[wordSep.selectedIndex];  
    transliterateObj.selFunctionPtr = transliterateObj.funcPtr_2[transliterateObj.selSlokaTypeIndex][transliterateObj.selTransFunction];
    var langPartObj = getTranslitPatternSearchObj ();
    var meaningPartObj = getTranslitPatternSearchObj ();
    var delimitersObj = getSynonymsDelimitersObj ();
    langPartObj.transliterateObj = meaningPartObj.transliterateObj = transliterateObj;
    langPartObj.nSelActionID = 0;
    meaningPartObj.nSelActionID = 2;
    langPartObj.transliterateObj.selFontName_TranslitID = meaningPartObj.transliterateObj.selFontName_TranslitID = 1;


    var inpTextArea = g_currentTextAreaCtlShown[TEXTAREA_INP_CONST];
    var element = g_currentTextAreaCtlShown[TEXTAREA_OUT_CONST];
    if (element.style.color == "red") element.style.color = "Green";else {element.style.color = "red";}

    getSetContent_TextAreas_Adv(element, false, inpTextArea.innerHTML||inpTextArea.value); // place the contents of input into output area, to preserve format
    var contentsArr = getSetContent_TextAreas_Adv(element, true, ""); // get the contents
    for (var i=0; i<contentsArr.length; i++) {
        if (contentsArr[i].childCtl != null && contentsArr[i].orjText != null && contentsArr[i].orjText !="" && myTrim(contentsArr[i].orjText, true, true) !="") {
            contents = contentsArr[i].orjText;
            contentsArr[i].newText = extractAndProcessSynonyms (contents, langPartObj, meaningPartObj,delimitersObj);
            contentsArr[i].childCtl.textContent = contentsArr[i].childCtl.value = contentsArr[i].newText;
        }
    }
    if (inpTextArea.style.color != "Green") inpTextArea.style.color = "Green";else inpTextArea.style.color = "black";



    return;
}
function checkTamilGuide(inpData, csvData, outputTextArea, dictFunction){ 
//    readSingleFile (inp, true);
    var csvDataArea = document.getElementById(csvData); // no longer used since g_loadedTEXTFromFileArr [TAM_GUIDE_CSV_DATA_LOC] is used instead
    var dict_functions = document.getElementById(dictFunction);
    
    var dictCheckRes;
    var inpTextArea = g_currentTextAreaCtlShown[TEXTAREA_INP_CONST];
    var element = g_currentTextAreaCtlShown[TEXTAREA_OUT_CONST];

    dictCheckRes = checkAgainstTamilGuide (getSetContent_TextAreas (inpTextArea, true, ""), g_loadedTEXTFromFileArr[TAM_GUIDE_CSV_DATA_LOC], dict_functions.selectedIndex, false, g_paddingChar_preserveText);
    //alert (dictCheckRes.modifiedContentsStr);
    //getSetContent_TextAreas_Adv (element, false, dictCheckRes.modifiedContentsStr);
    doModal(1, dictCheckRes.modifiedContentsStr, dictCheckRes, element);
    //alert (dictCheckRes.report);


} 
function createGuideFromWordlist(){ 
    createCSVFromWordList(g_loadedTEXTFromFileArr[WORD_LIST_TO_ENTER_CSV]);
} 
function prepareToCheckDiacritics(checkDiac, check_diacritic_group_arg)
{
    var inp = document.getElementById(checkDiac);
    var inpG = document.getElementById(check_diacritic_group_arg);
    
    (inp.checked) ? inpG.style.display="block":inpG.style.display="none";

}
function checkDiacriticsNow(langSelCtl_arg)
{
    var inp = document.getElementById (langSelCtl_arg);


    var inpTextArea = g_currentTextAreaCtlShown[TEXTAREA_INP_CONST];
    var contents = getSetContent_TextAreas (inpTextArea, true, "");
    var element = g_currentTextAreaCtlShown[TEXTAREA_OUT_CONST];
    getSetContent_TextAreas (element, false, checkDiacritics (contents, inp.selectedIndex));
    alert ("Diacritic complete");

}
function readSingleFile(e, bProcess) {
  var file = e.files[0];
  var contents;
  if (!file) {
  alert ("invalid file");
    return;
  }
  var reader = new FileReader();
  reader.onload = function(e) {
    contents = e.target.result;
    if (bProcess == true) transliterateContents (file, contents, true);
  };
  reader.readAsText(file);
  return contents;
}
function convertToUnicode(controlUni, ip_file_content, load_font_mapper_file)
{
    var convertToUnicode_control = document.getElementById(controlUni);
    var inpTextArea = g_currentTextAreaCtlShown[TEXTAREA_INP_CONST];
    var inp = document.getElementById(load_font_mapper_file);
    var contents = "";
    var contentsArr = getSetContent_TextAreas_Adv(inpTextArea, true, ""); // get the contents
    for (var i=0; i<contentsArr.length; i++) {
        if (contentsArr[i].childCtl != null && contentsArr[i].orjText != null && contentsArr[i].orjText !="" && myTrim(contentsArr[i].orjText, true, true) !="") {
            contents = contentsArr[i].orjText;
            if (convertToUnicode_control.selectedIndex != 0) {
                contentsArr[i].newText = convertNon_unicodeToUnicode (convertToUnicode_control.value, contents);
                contentsArr[i].newText = contentsArr[i].newText.replace(/\t\t+/gi,'\t');
                inpTextArea.style.color = "red";
            } else {
                inpTextArea.style.color = "darkgreen";
                contentsArr[i].newText = convertFont_New (LOAD_CUSTOM_NON_UNICODE_UNICODE_MAPPER, contents, CONVERT_NONUNICODE_TO_UNICODE);
            }
            contentsArr[i].childCtl.textContent = contentsArr[i].childCtl.value = contentsArr[i].newText;
        }
    }
//    if (inpTextArea.style.color != "Green") inpTextArea.style.color = "Green";else inpTextArea.style.color = "black";

}
function convertITransToUni (ip_file_content){
    var inpTextArea = g_currentTextAreaCtlShown[TEXTAREA_INP_CONST];
    var contents = "";
    var transliterateObj = getTransliterationObject ();
    var trans = document.getElementById ('TransOption');
    transliterateObj.selTransFunction = trans.value;
    var contentsArr = getSetContent_TextAreas_Adv(inpTextArea, true, ""); // get the contents
    for (var i=0; i<contentsArr.length; i++) {
        if (contentsArr[i].childCtl != null && contentsArr[i].orjText != null && contentsArr[i].orjText !="" && myTrim(contentsArr[i].orjText, true, true) !="") {
            contents = contentsArr[i].orjText;
            contentsArr[i].newText = convertITransToUnicode (contents, transliterateObj);
            contentsArr[i].childCtl.textContent = contentsArr[i].childCtl.value = contentsArr[i].newText;
        }
    }
    inpTextArea.style.color = "red";
}
function convertToNonUnicode(controlNonUni, ip_file_content, load_font_mapper_file)
{
    var convertToNonUnicode_control = document.getElementById(controlNonUni);
    var contents;
    if (convertToNonUnicode_control.selectedIndex != 0 || convertToNonUnicode_control.value != 0) 
    {
        var inpTextArea = document.getElementById(ip_file_content);
        contents= convertUnicodeToNonUnicode (convertToNonUnicode_control.value, getSetContent_TextAreas (inpTextArea, true, ""));
        contents = contents.replace(/\t\t+/gi,'\t');
        getSetContent_TextAreas (inpTextArea, false, contents);
    }
    else
    {
        alert ("Invalid selection - "+ convertToNonUnicode_control.selectedIndex);
    }
}
function transliterateNow(){  
    var inp = document.getElementById('file-input');
//    readSingleFile (inp, true);
    var contents = "";
    var inpTextArea = g_currentTextAreaCtlShown[TEXTAREA_INP_CONST];
    var element = g_currentTextAreaCtlShown[TEXTAREA_OUT_CONST];
    getSetContent_TextAreas_Adv(element, false, inpTextArea.innerHTML||inpTextArea.value); // place the contents of input into output area, to preserve format
    var contentsArr = getSetContent_TextAreas_Adv(element, true, ""); // get the contents
    for (var i=0; i<contentsArr.length; i++) {
        if (contentsArr[i].childCtl != null && contentsArr[i].orjText != null && contentsArr[i].orjText !="" && myTrim(contentsArr[i].orjText, true, true) !="") {
            contents = contentsArr[i].orjText;
            contentsArr[i].newText = transliterateContents (inp.files[0], contents, false); // do not display
            contentsArr[i].childCtl.textContent = contentsArr[i].childCtl.value = contentsArr[i].newText;
        }
    }

}  
function transliterateContents (filePtr, contents, bDisplay)
{

    var transliterateObj = getTransliterationObject ();
    var sel = document.getElementById('sloka_type');    
    transliterateObj.selSlokaTypeIndex = sel.selectedIndex;
    var trans = document.getElementById ('TransOption');
    transliterateObj.selTransFunction = trans.value;
    var useNum = document.getElementById ('use_numbers');
    transliterateObj.bUseNumbers = useNum.selectedIndex!=0;
    transliterateObj.nUseDiacriticNumbersMoreInfo = useNum.selectedIndex;
    var promptTrans = document.getElementById ('confirm_translit');
    transliterateObj.bSmartTranslit_Prompt = promptTrans.checked;
    var wordSep = document.getElementById('wordSepList');

    transliterateObj.wordSeparator= transliterateObj.wordSep[wordSep.selectedIndex];  
    transliterateObj.selFunctionPtr = transliterateObj.funcPtr_2[transliterateObj.selSlokaTypeIndex][transliterateObj.selTransFunction];
    transliterateObj.selTransFunction_Text = trans.options[trans.selectedIndex].text;
    var outTransStr = transliterateTool (contents, transliterateObj);    
    //convertLanguage(outTransStr, -640);
    if (bDisplay)
        displayContents(outTransStr, filePtr);
    return outTransStr;

}
function displayContents(contents, inpFileControl) {
  var element = g_currentTextAreaCtlShown[TEXTAREA_OUT_CONST];
  element.style.color = "red";  
  getSetContent_TextAreas (element, false, contents);
  //alert (inpFileControl.name);
  var outFileName = "Agattiyar_DummyOut.txt";
  if (inpFileControl != null) outFileName = inpFileControl.name;
  var filename = outFileName.replace(".txt", "_outputFromBrowser.txt");
  var text = contents;
  var blob = new Blob([text], {encoding:"UTF-8",type:"UTF-8 Text"});
  var link = document.createElement("a");
  link.download = filename;
  link.innerHTML = "Click here to download the transliterated output as a text Download! <BR>";
  link.href = window.URL.createObjectURL(blob);
  document.body.appendChild(link);  
}
function useNumbersChecked(useNumbers_arg, confirmTranslit_arg, confirmTranslitPrmpt_arg)
{
return;
    var uN = useNumbers_arg;
    var cT = confirmTranslit_arg;
    var cT_p = confirmTranslitPrmpt_arg;
    
    var element_uN = document.getElementById(uN);
    var element_cT = document.getElementById(cT);
    var element_cT_p = document.getElementById(cT_p);
    
    if (element_uN.selectedIndex == 0)
    {
        element_cT.checked=false;
        //element_cT.style.display = "none";
        element_cT_p.style.display = "none";
    } else
    {
        //element_cT.style.display = "block";
        element_cT_p.style.display = "block";
    }
}
var TAM_GUIDE_CSV_DATA_LOC = 0;
var WORD_LIST_TO_ENTER_CSV = 1;
var g_loadedTEXTFromFileArr=[];

function loadTextArea (fc_arg,txtArea_arg, loadedTextArrLocator)
{
    var fc = fc_arg;
    var txtArea = txtArea_arg;

    var inp = document.getElementById(fc);

    //alert (inp.files[0].name);
    var file = inp.files[0];
    var contents;
    if (!file) {
        alert ("invalid file");
        return;
    }
    var reader = new FileReader();
    reader.onload = function(e) {
        var inpTextArea, bFound = false;
        contents = e.target.result;
        for (var i = 0; i<g_textArea_NicEditorMap.length; i++){
            if (g_textArea_NicEditorMap[i].textAreaCtlStr == txtArea_arg){
                inpTextArea = g_currentTextAreaCtlShown[TEXTAREA_INP_CONST];
                bFound = true;
                break;
            } else {
                bFound = false;
            }
        }
        if (bFound == false) {
            inpTextArea = document.getElementById (txtArea_arg);
        }
        getSetContent_TextAreas (inpTextArea, false, contents);
        g_loadedTEXTFromFileArr[Number(loadedTextArrLocator)]=contents;
      };
    reader.readAsText(file);
    
}
function loadDataFileList_FromServer (font_mapper_from_server_listCtlStr, dataFileFolderStr, fontMapperFileExtStr) {
    var font_mapper_from_server_listCtl = document.getElementById (font_mapper_from_server_listCtlStr);
    if (font_mapper_from_server_listCtl == null) return;
    if (dataFileFolderStr!=null && dataFileFolderStr!="") {
        var xhr = new XMLHttpRequest();
        xhr.onreadystatechange = function() {
            if (xhr.readyState == 4 && xhr.status == 200) {
                //document.getElementById('placeholder').innerHTML = xhr.responseText;
                var contents = xhr.responseText;
                var htmlDoc = parseHTMLTag_extractContent(contents, "body").htmlDoc;
                var optionsfont_mapper_from_server_listCtlStr  = "";
                var arrExtPartData = fontMapperFileExtStr.split("|");
                var i =0, j = 0, bProcessed = false;
                if (htmlDoc != null) {
                    var elementArr = null;
                    if (typeof htmlDoc ==="document" || (htmlDoc.nodeName.indexOf("document-fragment") == -1 && htmlDoc.nodeName.indexOf("document") != -1))
                        elementArr = htmlDoc.getElementsByTagName ("a");
                        else if (typeof htmlDoc === "document-fragment"|| htmlDoc.nodeName.indexOf("document-fragment") != -1)
                            elementArr = htmlDoc.querySelectorAll("a");
                    var elementText = "", elementTextLoc = "";
                    if (elementArr != null) {
                        for (i = 0; i < elementArr.length; i++) {
                            elementText = elementArr[i].innerText;
                            elementTextLoc = elementArr[i].href;
                            bProcessed = false;
                            for (j = 0 ; j<arrExtPartData.length; j++){
                                if ((elementText !=null || elementText != "" )&& elementText.indexOf(arrExtPartData[j]) != -1) {
                                    optionsfont_mapper_from_server_listCtlStr += "<option id="+String(i)+" value=\""+elementTextLoc+"\">"+elementText+"</option>";
                                    bProcessed = true;
                                    break; // no need to go any further
                                    }
                                }
                            if (bProcessed) continue;
                            }
                        font_mapper_from_server_listCtl.innerHTML = optionsfont_mapper_from_server_listCtlStr;
                        font_mapper_from_server_listCtl.selectedIndex = 0;
                        font_mapper_from_server_listCtl.dispatchEvent(new Event('change', { bubbles: true }));
                        }                    
                    }
            }
        };
        xhr.open('GET', dataFileFolderStr, true);
        xhr.send();
    }        
}
function onFontMapperFileFromServerChanged(font_mapper_from_server_listCtlStr, convert_to_uni_BtnCtlStr, convert_to_non_uni_BtnCtlStr) {
    var font_mapper_FileNameCtl = document.getElementById(font_mapper_from_server_listCtlStr);
    var fileToDownload = "", csvContentsFromServer = "";
    var conv_uni_btlCtl = document.getElementById(convert_to_uni_BtnCtlStr);
    var conv_nonuni_btlCtl = document.getElementById(convert_to_non_uni_BtnCtlStr);
    
    if (font_mapper_FileNameCtl != null) {
        if (font_mapper_FileNameCtl.options[font_mapper_FileNameCtl.selectedIndex] == null) {alert ("Both the (.csv) file URL list cannot be empty. load the file manually!");return false;}
        fileToDownload = font_mapper_FileNameCtl.options[font_mapper_FileNameCtl.selectedIndex].value;
        if (fileToDownload == "")        alert ("the (.csv) file URL cannot be empty. Please specify!"); 
        }
    if (fileToDownload != "") {
        var xhr = new XMLHttpRequest();
        xhr.onreadystatechange = function() {
            if (xhr.readyState == 4 && xhr.status == 200) {
                //document.getElementById('placeholder').innerHTML = xhr.responseText;
                csvContentsFromServer = xhr.responseText;
                setFontMapperCache (csvContentsFromServer, ",");
                setControlsDisplay (g_processButtonCtlsArr_fontMapper, true, true);
                setControlsDisplay (g_processButtonCtlsArr_fontConv, true, true);
                
            }
        };
        xhr.open('GET', fileToDownload, true);
        xhr.send();
        }
}
function getGlobalCtlStruct () {
    var ctlStruct = {ctl:null, bShow:true, bEnable:true,};
    return ctlStruct;
}
function loadGlobalControlsArray (arrayControlsSrc, arrayControlsDest) {
    if (arrayControlsSrc == null || arrayControlsSrc.length ==0) return;
    for (var i = 0; i< arrayControlsSrc.length; i++) {
        arrayControlsDest [i] = getGlobalCtlStruct ();
        arrayControlsDest [i].ctl = document.getElementById (arrayControlsSrc[i].ctl);
        arrayControlsDest [i].bEnable = arrayControlsSrc[i].bEnable;
        arrayControlsDest [i].bShow = arrayControlsSrc[i].bShow;
        
        }
}

function setControlsDisplay_All () {
    for (var i = 0; i< g_processButtonCtlsArr_fontMapper.length; i++) {
        g_processButtonCtlsArr_fontMapper [i].ctl.style.display = g_processButtonCtlsArr_fontMapper [i].bShow?"block":"none";
        g_processButtonCtlsArr_fontMapper [i].ctl.disabled = !g_processButtonCtlsArr_fontMapper [i].bEnable;
        }
    for (var i = 0; i< g_processButtonCtlsArr_fontConv.length; i++) {
        g_processButtonCtlsArr_fontConv [i].ctl.style.display = g_processButtonCtlsArr_fontConv [i].bShow?"block":"none";
        g_processButtonCtlsArr_fontConv [i].ctl.disabled = !g_processButtonCtlsArr_fontConv [i].bEnable;
        }
}
function setControlsDisplay (ctlArray, bShow, bEnable) {
    for (var i = 0; i< ctlArray.length; i++) {
        ctlArray [i].ctl.style.display = bShow?"block":"none";
        ctlArray [i].ctl.disabled = !bEnable;
        }
}

function loadFontMapperCSV(load_font_mapper_file, convert_to_uni_BtnCtlStr, convert_to_non_uni_BtnCtlStr) {
    var inp = document.getElementById(load_font_mapper_file);
    var conv_uni_btlCtl = document.getElementById(convert_to_uni_BtnCtlStr);
    var conv_nonuni_btlCtl = document.getElementById(convert_to_non_uni_BtnCtlStr);
    
    var contents = "";
    var file = inp.files[0];
    if (!file) {
    alert ("invalid file");
    return;
    }
    var reader = new FileReader();
    reader.onload = function(e) {
        contents = e.target.result;
        setFontMapperCache (contents, ",");
        setControlsDisplay (g_processButtonCtlsArr_fontConv, true, true);
        };
    reader.readAsText(file);
    

}
function onConvertUniFontSelectionChanged (convert_unicode_fontSelCtlStr, load_font_mapper_fileCtlStr, font_mapper_from_server_listCtlStr, convert_to_uni_BtnCtlStr) {
    var load_font_mapper_fileCtl = document.getElementById(load_font_mapper_fileCtlStr);
    var font_mapper_from_server_listCtl = document.getElementById(font_mapper_from_server_listCtlStr);
    var uniConvFontSelCtl = document.getElementById(convert_unicode_fontSelCtlStr);
    var conv_uni_btlCtl = document.getElementById(convert_to_uni_BtnCtlStr);
    var bShow = false;
    
    if (uniConvFontSelCtl != null) {
        if (uniConvFontSelCtl.selectedIndex != 0) {
            bShow = true;
            setControlsDisplay (g_processButtonCtlsArr_fontMapper, false, true);
            setControlsDisplay (g_processButtonCtlsArr_fontConv, true, true);
            } else {
                bShow = false;
                setControlsDisplay (g_processButtonCtlsArr_fontMapper, true, true);
                if (font_mapper_from_server_listCtl.options.length != 0 || load_font_mapper_fileCtl.files.length !=0) 
                setControlsDisplay (g_processButtonCtlsArr_fontConv, true, true);
                else
                setControlsDisplay (g_processButtonCtlsArr_fontConv, true, false);
                }
                
//        font_mapper_from_server_listCtl.selectedIndex = 0;
//        font_mapper_from_server_listCtl.dispatchEvent(new Event('change', { bubbles: true }));                
        }
}

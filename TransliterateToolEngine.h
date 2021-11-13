var LOAD_CUSTOM_NON_UNICODE_UNICODE_MAPPER ;
var BALARAM_SCA_GAUDY_FAMILY;
var SREELIPI_TAMEX_FAMILY;
var ADHAWIN_TAMIL_FAMILY;
var INDOWORD_LT_TM_FAMILY;
var IDS_TAMIL_KA_FAMILY;
var SREELIPI_GEN_813_817_FAMILY;
var TAB_ANNA_TAM_FAMILY;
var SUN_TAMIL_FAMILY;
var SANSKRIT_TIMES_FAMILY;
var UNICODE_FAMILY;

var CONVERT_NONUNICODE_TO_UNICODE;
var CONVERT_UNICODE_TO_NONUNICODE;
var UNICODE_FIELD_LOC;
var NONUNICODE_FIELD_LOC;

var APPEND_CSV_RECORD;
var CSV_HEADER_ROW_INDEX;
var CSV_HEADER_FIELD_LOCATOR_POS;
var CSV_HEADER_FIELD_LABEL_POS;
var CSV_HEADER_FIELD_DEF_VAL_POS;

function initConstants() {
LOAD_CUSTOM_NON_UNICODE_UNICODE_MAPPER = 0;
BALARAM_SCA_GAUDY_FAMILY =1;
SREELIPI_TAMEX_FAMILY =2;
ADHAWIN_TAMIL_FAMILY =3;
INDOWORD_LT_TM_FAMILY =4;
IDS_TAMIL_KA_FAMILY =5;
SREELIPI_GEN_813_817_FAMILY =6;
TAB_ANNA_TAM_FAMILY =7;
SUN_TAMIL_FAMILY =8;
SANSKRIT_TIMES_FAMILY =9;
UNICODE_FAMILY = 10;

CONVERT_NONUNICODE_TO_UNICODE = 0;
CONVERT_UNICODE_TO_NONUNICODE = 1;
UNICODE_FIELD_LOC = 0;
NONUNICODE_FIELD_LOC = 1;
APPEND_CSV_RECORD = -1;
CSV_HEADER_ROW_INDEX = 0;
CSV_HEADER_FIELD_LOCATOR_POS = 0;
CSV_HEADER_FIELD_LABEL_POS = 1;
CSV_HEADER_FIELD_DEF_VAL_POS = 2;

}



function get_NONUNICODE_TO_UNICODE_constant () {return CONVERT_NONUNICODE_TO_UNICODE;}
function get_UNICODE_TO_NONUNICODE_constant () {return CONVERT_UNICODE_TO_NONUNICODE;}
function getVersionObject ()
{
    var obj = {
    // Feb 10, 2021: versionString: 2.10.09 - added a generic function to parse prefix and suffix and return the in-between parts
    // Feb 10, 2021: htmlVersion:1.09.03 onwards Subscript and Superscript are available by default in design mode    
    // Feb 15, 2021: versionString: 2.11.00 - added a support for generic routine to convert non-unicode to unicode fonts
    // Feb 15, 2021: htmlVersion:1.10.00  - added a support for generic routine to convert non-unicode to unicode fonts   
    // March 28, 2021: versionString: 2.12.00 - added a support for telugu Transliteration
    // March 28, 2021: htmlVersion:1.11.00  - added a support for telugu Transliteration
    // April 29, 2021: versionString: 2.13.00 - added a support for ITrans English text
    // March 28, 2021: htmlVersion:1.12.00  - added a support for ITrans English text
    // June 02, 2021: htmlVersion:2.00.00  - added support for NiceEdit Textareas
    // June 07, 2021: htmlVersion:2.00.01  - added support for NiceEdit Textareas on Microsoft OS. Use font-weight:normal or bold styles
    // June 07, 2021: versionString:2.13.02  - added support for characters \u1e5c and \u1e5d
    // June 12, 2021: htmlVersion:2.00.02  - added support for NiceEdit Textareas auto scrollable
    // June 12, 2021: versionString:2.13.03  - added support for NiceEdit Textareas auto scrollable
    // June 19, 2021: versionString:2.14.00  - added support for Tamil guide stylesheet and content review feature
    // June 19, 2021: htmlString:2.01.00  - added support for Tamil guide stylesheet and content review feature
    // June 19, 2021: versionString:2.14.01  - Minor updates to code
    // June 19, 2021: htmlString:2.01.01  - minor updates to code
    // July 20, 2021: versionString:2.14.02  - Minor bug fixes to code
    // June 20, 2021: htmlString:2.01.02  - minor bug fixes to code
    // Aug 09, 2021: versionString:2.14.03  - minor bug fixes to code fixed ṛ transliteration
    // Aug 12, 2021: versionString: 2.14.04 - Added a sleep or delay function 
    // Aug 25, 2021: versionString: 2.14.05 - Bug fixed - missing u in \u unicode code characters. ex:replaced \u0032 with \u0032. 
                                            // handled \u0027 and \u0022 characters for Devag to English mappings.
                                            // also handled special processing of converting successive \u0027 to \u0022
    // Oct 1, 2021: versionString: 2.14.06 - Bug fixed - fixed R to ṛ in ITRANS conversion
    // Oct 5, 2021: htmlVersion: 2.02.01 - Added ID field to all buttons
    // Oct 10, 2021: versionString: 2.15.00 - Add new tool to create proof-read guide file from words list
    // Oct 10, 2021: versionString: 2.15.01 - Add new tool to create proof-read guide file from words list
    // Oct 20, 2021: htmlVersion: 2.03.00 - UI for new tool to create proof-read guide file from words list
    // Oct 20, 2021: htmlVersion: 2.03.01 - UI for new tool to create proof-read guide file from words list
        versionString:"2.15.01", 
        htmlVersion:"2.03.01", 
        indesignVersion:"1.00.01",
        versionStrDesc: "X.YY.ZZ \rX= Major Update (Eg. Adding a new sloka type) \r YY=Feature updates (Adding new lang support) \r ZZ-minor updates",
        slokaVerseTypeInst: [1,1,1],  //corresponds to the fied slokaTypeList of transliterateObj
        translitFuncListInst:[1,1,1,1,1,1], //corresponds to the fied translitFuncList of transliterateObj
        };
    initConstants();
    return obj;
}


async function sleep(ms) {
    function delay(ms) {
        return new Promise(resolve => {
            setTimeout(resolve, ms);
        });
    }
    await delay(ms);
}


function getTransliterationObject () {
    initConstants();
    var transliterateObj = {
        paraStyle:[],
        funcPtr: [
            transliterateEnglishToTamil, 
            transliterateTamilToEnglish,
            transliterateEnglishToDevanag,
            transliterateDevanagToEnglish,
            transliterateTamilToDevanag,
            transliterateDevanagToTamil
            ],

        funcPtr_2: [
            [
            transliterateEnglishToTamil, 
            transliterateTamilToEnglish,
            transliterateEnglishToDevanag,
            transliterateDevanagToEnglish,
            transliterateTamilToDevanag,
            transliterateDevanagToTamil,
            transliterateEnglishToTelugu, 
            transliterateTeluguToEnglish,
            transliterateTeluguToDevanagari, 
            transliterateDevanagariToTelugu,
            ],
            [
            transliterateEnglishToTamil, 
            transliterateTamilToEnglish,
            transliterateEnglishToBengali,
            transliterateBengaliToEnglish,
            transliterateTamilToBengali,
            transliterateBengaliToTamil,
            transliterateEnglishToTelugu, 
            transliterateTeluguToEnglish,
            transliterateTeluguToDevanagari, 
            transliterateDevanagariToTelugu,
            ],
            [
            transliterateEnglishToTamil, 
            transliterateTamilToEnglish,
            transliterateEnglishToDevanag,
            transliterateDevanagToEnglish,
            transliterateTamilToDevanag,
            transliterateDevanagToTamil,
            transliterateEnglishToTelugu, 
            transliterateTeluguToEnglish,
            transliterateTeluguToDevanagari, 
            transliterateDevanagariToTelugu,
            ],
        ],

        slokaTypeList: ["Sanskrit Verse", "Bengali Verse", "Tamil Pasuram"],
        translitFuncList: [
                    ["English2Tamil", "Tamil2English", "English2Devanagari", "Devanagari2English", "Tamil2Devanagari", "Devanagari2Tamil", "English2Telugu", "Telugu2English","Telugu2Devanagari", "Devanagari2Telugu",],
                    ["English2Tamil", "Tamil2English", "English2Bengali", "Bengali2English", "Tamil2Bengali", "Bengali2Tamil", "English2Telugu", "Telugu2English","Telugu2Devanagari", "Devanagari2Telugu",],
                    ["English2Tamil", "Tamil2English", "English2Devanagari", "Devanagari2English", "Tamil2Devanagari", "Devanagari2Tamil", "English2Telugu", "Telugu2English","Telugu2Devanagari", "Devanagari2Telugu",],
                    ],

        bCheckEngForITRANS: false,
        selSlokaTypeIndex: 0,
        selSlokaType_Text: "Sanskrit Verse",
        selTransFunction:0, 
        selTransFunction_Text: "English2Tamil",
        selFunctionPtr: transliterateEnglishToTamil,
        bUseNumbers: false,
        useDiacriticNumbersMoreInfo_label: ["0=no diacritic", "1 = normal diacritics font", "2= numbers_subscripted", "3 = numbers_superscripted"],
        nUseDiacriticNumbersMoreInfo:0, //0=no diacritic, 1 = normal diacritics font, 2= numbers_subscripted, 3 = numbers_superscripted
        wordSepLabel: ["1-space", "2-spaces", "Tab", "hyphen"],
        wordSep: [" ", "  ", "\t", "-"],
        wordSeparator: " ", //one space
        bSmartTranslit_Prompt: false,
        langOffset:0,
        bTranslitFunctionEnable: true, // some UI's want only to enable or disable Transliterate options
        selFontName_TranslitSource:"",
        selFontName_TranslitID:"",
        // following structures are added with version 2.05.04 
        // to expose the non-unicode to uni-code conversion and vice versa to outside clients
        bConvertFromToUnicode: false,
/*        selFontName_From:"", 
        selFontStyle_From:"", 
        selFontFamilyID_From:0, // 0 is reserved for Unicode type
        selFontFamilyID_To:0,     // 0 is reserved for Unicode type
        */
        selFontName_To:"", 
        selFontStyle_To:"", 

        supportedConversionFontFamily_map: [ //first parameter is the font family, second is its internal index
            ["Load mapper (.csv file)", LOAD_CUSTOM_NON_UNICODE_UNICODE_MAPPER,],
            ["Balaram [sca-gaudy..]", BALARAM_SCA_GAUDY_FAMILY,],
            ["ShreeLipi-ex [TamEX..]", SREELIPI_TAMEX_FAMILY,],
            ["Adhawin-Tamil", ADHAWIN_TAMIL_FAMILY,],
            ["Indoword [LT_TM....]", INDOWORD_LT_TM_FAMILY,],
            ["IDS_Tamil [Ka Nazhikai]", IDS_TAMIL_KA_FAMILY,],
            ["ShreeLipi-6 [813, 817...]", SREELIPI_GEN_813_817_FAMILY,],
            ["TAB-Anna", TAB_ANNA_TAM_FAMILY,],
            ["Sun-Family-Tamil", SUN_TAMIL_FAMILY,],
            ["Sanskrit-Times", SANSKRIT_TIMES_FAMILY,],
            ["Unicode", UNICODE_FAMILY,]
        ],
        supportedFonts_map: [ //first parameter is the font family, second is the font name
            ["Load mapper (.csv file)", "TAM_Kumbam",],
            ["Unicode", "BBT-TM-Nityananda",],
            ["Unicode", "BBT-TM-Krishna",],
            ["Unicode", "BBT-TM-Acutya",],
            ["Unicode", "BBT-TM-Advaita",],
            ["Unicode", "BBT-TM-Adi",],
            ["Balaram [sca-gaudy..]", "Balaram",],
            ["Balaram [sca-gaudy..]", "ScaGoudy",],
            ["ShreeLipi-ex [TamEX..]", "SHREE-TAMX-3893",],
            ["Adhawin-Tamil", "Adhawin-Tamil",],
            ["Indoword [LT_TM....]", "LT_TM_Annamalai",],
            ["Indoword [LT_TM....]", "Indevr",],
            ["IDS_Tamil [Ka Nazhikai]", "Ka Nazhikai",],
            ["ShreeLipi-6 [813, 817...]", "SHREE-TAM-0813",],
            ["ShreeLipi-6 [813, 817...]", "SHREE-TAM-0817",],
            ["TAB-Anna","TAB-Anna",],
            ["Sun-Family-Tamil", "Sun-Family-Tamil Fonts",],            
            ["Sanskrit-Times", "Sanskrit-Times",],            
        ],
        
        
        };
    return transliterateObj;
}
function getFontFamilyIDFromName (transliterateObj, fontFamilyName) {
    var supportedConvertFontFamilyArr = transliterateObj.supportedConversionFontFamily_map;
    for (i = 0; i< supportedConvertFontFamilyArr.length; i++)
    {
        if (supportedConvertFontFamilyArr[i][0] == fontFamilyName)
        {
            transliterateObj.selFontName_TranslitID  = supportedConvertFontFamilyArr[i][1];
            break;
            }
    }
    return transliterateObj;
}
function getIndianLanguageOffsetCode (refChar_langFirst, refChar_langSecond)
{
    return refChar_langSecond.charCodeAt(0) - refChar_langFirst.charCodeAt(0);
}
function convertLanguage(str, langCharCodeOffset) {
// this function is only for some internal testing purporses. Use caution....!!!!

    var langOffsetStr = str;
    var i=0;
    
    if (langCharCodeOffset !=0) {
        langOffsetStr="";
        alert(str);
        for (i=0; i<str.length; i++)
        {
            langOffsetStr += String.fromCharCode(str.charCodeAt(i) + langCharCodeOffset);
        }
        alert (langOffsetStr);
    }
    return langOffsetStr;
}
function getTransMappedObject(langFrom, langTo, withNum, selSlokaTypeIndex)
{
    var obj;
    if (langFrom.toLowerCase() == "english"&& langTo.toLowerCase()=="tamil") {
        if (selSlokaTypeIndex == 1) //bengali verse type
                obj = getTransMap_EngToTamil_BengaliVersion(withNum);
            else
                obj = getTransMap_EngToTamil(withNum);
    } else if (langFrom.toLowerCase() == "tamil"&& langTo.toLowerCase()=="english") {

        if (selSlokaTypeIndex == 1) //bengali verse type
            obj = getTransMap_TamToEng_BengaliVersion(withNum);
        else
            obj = getTransMap_TamToEng(withNum);
    } else if (langFrom.toLowerCase() == "english"&& langTo.toLowerCase()=="devanagari") {
        obj = getTransMap_EngToDevag();
    } else if (langFrom.toLowerCase() == "devanagari"&& langTo.toLowerCase()=="english") {
        obj = getTransMap_DevagToEnglish();
    }else     if (langFrom.toLowerCase() == "english"&& langTo.toLowerCase()=="telugu") {
        obj = getTransMap_EngToTelugu();
    } else if (langFrom.toLowerCase() == "telugu"&& langTo.toLowerCase()=="english") {
        obj = getTransMap_TeluguToEnglish();
    }

    return obj;
}
function saveObject(objToSave) {
    return objToSave.toSource();
}

function ConvertEngITRANSToUnicode (strToTransliterate){

    var accent_fold = (function () {
        var EngITRANSToUni_singleChar_map = {
            'A': 'ā', 
            'I':'ī',
            'U':'ū',
            'N':'ṇ',
            'R':'ṛ',
            'D':'ḍ',
            'T':'ṭ',
            'M':'ṁ',
            'S':'ṣ',
            'z':'ś',
            'H':'ḥ',
            'L':'ḷ',
            'X':'r̥̄',
            'W':'ḹ',
            'J':'ñ',
            'Q':'jñ',
        };
        return function accent_fold(s) {
        if (!s) { return ''; }
        var ret = '', accent_map_to_use, tmpChar , tmpMsg = 0;
        accent_map_to_use = EngITRANSToUni_singleChar_map;
        for (var i = 0; i < s.length; i++) {
           
           tmpChar = accent_map_to_use[s.charAt(i)];
            ret += tmpChar || s.charAt(i);
        }
        return ret;
        };
    } ()); 
    strToTransliterate = strToTransliterate.replace(RegExp("lR","g"),"L");
    strToTransliterate = strToTransliterate.replace(RegExp("RR","g"),"X");
    strToTransliterate = strToTransliterate.replace(RegExp("lRR","g"),"W");
    strToTransliterate = strToTransliterate.replace(RegExp("GY","gi"),"Q");
    strToTransliterate = strToTransliterate.replace(RegExp("j~n","gi"),"Q");
    strToTransliterate = strToTransliterate.replace(RegExp("sh","g"),"S");
    return accent_fold(strToTransliterate);

    
}
function convertITransToUnicode (strToConvert, transObj){
    if (transObj.selTransFunction_Text.toLowerCase().indexOf("english2") != -1 ){
        // need convert the input ENGLISH text from ITRANS to regular UNICODE
        return ConvertEngITRANSToUnicode (strToConvert);
        } else {
            return strToConvert;
        }

}
function transliterateTool (strToTransliterate, transObj)
{
    initConstants();
    var outTransStr = "";
    if (transObj == null || strToTransliterate == null) {alert ("invalid arguments");return null;}
    if (transObj.bUseNumbers == false) {
        transObj.nUseDiacriticNumbersMoreInfo = 0;}
    else { // use diacritic is set to true
        if (transObj.nUseDiacriticNumbersMoreInfo < 1) transObj.nUseDiacriticNumbersMoreInfo = 1;} // if the caller did not set moreInfo field, then default it to 1
    outTransStr = transObj.selFunctionPtr (strToTransliterate, transObj).outString;
    switch (transObj.nUseDiacriticNumbersMoreInfo) {
    case 1:
    outTransStr=outTransStr.replace(/(\S)[\u2082\u00b2]/gi,'$1\u0032');
    outTransStr=outTransStr.replace(/(\S)[\u2083\u00b3]/gi,'$1\u0033');
    outTransStr=outTransStr.replace(/(\S)[\u2084\u2074]/gi,'$1\u0034');
    break;
    case 2:
    outTransStr=outTransStr.replace(/(\S)[\u0032\u00b2]/gi,'$1\u2082');
    outTransStr=outTransStr.replace(/(\S)[\u0033\u00b3]/gi,'$1\u2083');
    outTransStr=outTransStr.replace(/(\S)[\u0034\u2074]/gi,'$1\u2084');
    break;
    case 3:
    outTransStr=outTransStr.replace(/(\S)[\u0032\u2082]/gi,'$1\u00b2');
    outTransStr=outTransStr.replace(/(\S)[\u0033\u2083]/gi,'$1\u00b3');
    outTransStr=outTransStr.replace(/(\S)[\u0034\u2084]/gi,'$1\u2074');
    break;
    default:
    break;
    };
    return outTransStr;
}
function getTransMap_EngToTelugu()
{
    var obj;
    var EngToTelugu_singleChar_map = {
        '‘': '‘', '?':'?','—':'—','–':'–','­':'­','‑':'‑','•':'•','^':'^','©':'©','…':'…','¶':'¶','®':'®','§':'§','™':'™','~':'~','`':'`','@':'@','#':'#','$':'$','%':'%','^':'^','&':'&','*':'*','_':'_','+':'+','=':'=','{':'{','[':'[','}':'}',']':']','>':'>','<':'<',
        '\u2018': '\u2018',
        '\u2019': '\u2019', '\u2014':'\u2014',
        '“': '“','"': '"','”':'”',
        '\u2003': '\u2003', '\u00A0':'\u00A0',
        '\n': '\n',
        '\r': '\r',
        '\t': '\t',
        '(': '(', ')': ')',
        '/': '/',
        '-': '-',
        '!': '!',
        ' ': ' ', '\u2009': ' ', '\u200A': ' ',
        '.': '.',
        ',': ',',';':';',':':':',
        '।': '।',
        '॥': '॥', 
        '|': '|',
        '‖': '‖', 
        '0':'\u0C66', '1':'\u0C67', '2':'\u0C68', '3':'\u0C69', '4':'\u0C6A', '5':'\u0C6B', '6':'\u0C6C', '7':'\u0C6D', '8':'\u0C6E', '9':'\u0C6F', 
        '\u0027': '\u0C3D',
        'a': '\u0C05', 'ā': '\u0C06', 'i': '\u0C07', 'ī': '\u0C08', 'u': '\u0C09', 'ū': '\u0C0A', 'e':'\u0C0F', 'ē':'\u0C0F', 'o': '\u0C13',  'ō': '\u0C13',// a
        'A': '\u0C14', 'I': '\u0C10', 'O': '\u0C50', // au and ai and oṁ
        'ḥ': '\u0C03', 'h': '\u0C39\u0C4D', 'H': '\u0C39',
        'ṛ': '\u0C41', 'Ṛ': '\u0C0B', 'Ṝ': '\u0C60', 'ṝ': '\u0C60', 
        'k': '\u0C15\u0C4D', 'K': '\u0C16\u0C4D', 'g': '\u0C17\u0C4D', 'G': '\u0C18\u0C4D', 'ṅ': '\u0C19\u0C4D', 'Ṅ': '\u0C19\u0C4D', 
        'c': '\u0C1A\u0C4D', 'C': '\u0C1B\u0C4D', 'j': '\u0C1C\u0C4D', 'J': '\u0C1D\u0C4D', 'ñ': '\u0C1E\u0C4D', 'Ñ': '\u0B9E\u0C4D', 
        'ṭ': '\u0C1F\u0C4D', 'Ṭ': '\u0C20\u0C4D', 'ḍ': '\u0C21\u0C4D', 'Ḍ': '\u0C22\u0C4D', 'ṇ': '\u0C23\u0C4D', 'Ṇ': '\u0C23\u0C4D', 
        't': '\u0C24\u0C4D', 'T': '\u0C25\u0C4D', 'd': '\u0C26\u0C4D', 'D': '\u0C27\u0C4D', 'n': '\u0C28\u0C4D', 'N': '\u0C28\u0C4D', 
        'p': '\u0C2A\u0C4D', 'P': '\u0C2B\u0C4D', 'b': '\u0C2C\u0C4D', 'B': '\u0C2D\u0C4D', 'm': '\u0C2E\u0C4D', 'M': '\u0C2E\u0C4D', 'ṁ': '\u0C02',  'Ṁ': '\u0C02', 'ḿ': '\u0C02', 'ṃ': '\u0C02', 'Ṃ': '\u0C02', 'ḿ': '\u0C02',
        'y': '\u0C2F\u0C4D', 'Y': '\u0C2F\u0C4D', 'r': '\u0C30\u0C4D', 'R': '\u0C30\u0C4D', 'l': '\u0C32\u0C4D', 'L': '\u0C32\u0C4D', 'ḹ':'\u0C33\u0C4D', 'ḷ': '\u0C0C\u0C4D', 'ḻ': '\u0C01\u0C32\u0C4D', 'v': '\u0C35\u0C4D', 'V': '\u0C35\u0C4D', 
        'ś': '\u0C36\u0C4D', 'Ś': '\u0C36\u0C4D', 'ṣ': '\u0C37\u0C4D', 'Ṣ': '\u0C35\u0C4D', 's': '\u0C38\u0C4D', 'S': '\u0C36\u0C4D\u0C30\u0C40',
         };

     obj = EngToTelugu_singleChar_map;
    
    return obj;
}
function transliterateEnglishToTelugu (strInputEng, tObj)
{
    var outData = {
        outString: "",
        bAccentReplaced: false,
        bFirstCharAccented: false,
        };

    var bUseNumbers = tObj.bUseNumbers;
    var wordSeparator = tObj.wordSeparator;
    
    var outData = {
        outString: "",
        bAccentReplaced: false,
        bFirstCharAccented: false,
        };
    var mapEng_char = (function () {
        var accent_map_to_use;
        accent_map_to_use= getTransMappedObject("English", "Telugu", bUseNumbers, tObj.selSlokaTypeIndex);
        return function mapEng_char(sOrj) {
        var s = sOrj, i,j, wordArray, prevChar, curChar, nextChar, curWord;
        if (!s) { return ''; }
        s = s.toLowerCase();
            
            //alert("b4 "+s);
            s= s.replace(/f/gi, "ph");            
            s= s.replace(/w/gi, "v");            
            s= s.replace(/au/gi, "A");
            s= s.replace(/ai/gi, "I");
            s= s.replace(/oṁ\s/gi, "O ");

            s= s.replace(/ḿ/gi, "ṁ");
            s= s.replace(/ń/gi, "ṅ");
            s= s.replace(/ṛ/gi, "ṛ"); // the two r-dots are different codes. The first one is actually two characters one alphabhet followed by under dot.
            s= s.replace(/ḥ/gi, "ḥ"); // the two h-dots are different codes
            s= s.replace(/ṣ/gi, "ṣ"); // the two s-dots are different codes
            s= s.replace(/ḍ/gi, "ḍ"); // the two d-dots are different codes
            s= s.replace(/ṇ/gi, "ṇ"); // the two n-dots are different codes
            s= s.replace(/ṭ/gi, "ṭ"); // the two t-dots are different codes
            s= s.replace(/ch/gi, "C");
            s= s.replace(/jh/gi, "J");
            s= s.replace(/kh/gi, "K");
            s= s.replace(/gh/gi, "G");
            s= s.replace(/th/gi, "T");
            s= s.replace(/dh/gi, "D");
            s= s.replace(/bh/gi, "B");            
            s= s.replace(/ph/gi, "P");            
            s= s.replace(/ṭh/gi, "Ṭ");
            s= s.replace(/ḍh/gi, "Ḍ");
            s= s.replace(/śrī/gi, "S");

            //alert("aft "+s);
            s= checkSpecialTeluguCharCases (s, tObj.selSlokaTypeIndex);
        var ret = '', tmpChar , tmpChar2 = '', curTransWord='';
        wordArray = s.split (" ");
        //alert(wordArray.length);
        for (i=0; i< wordArray.length; i++) {
            curWord = wordArray[i];
            prevChar = '';
            nextChar = '';
            curTransWord='';
            //alert(curWord);
            for (j = 0; j < curWord.length; j++) {
                curChar = curWord[j];
            //alert(curChar);
                if (j+1< curWord.length) nextChar = curWord[j+1]; else nextChar = '';            
                if (checkIfEngVowel(curChar, "Telugu", tObj.selSlokaTypeIndex)) {
                    if (prevChar != '') {
                        tmpChar = accent_map_to_use[prevChar];
                        if (tmpChar != null && tmpChar != '' && tmpChar != prevChar) 
                        curChar = convertEngConsonantToTelugu (tmpChar, curChar);
                        else curChar = prevChar + accent_map_to_use[curChar] ;
                        curTransWord += curChar;
                    } else curTransWord += accent_map_to_use[curChar] ;
                    prevChar = '';
                } else {
                    if (prevChar != '') {
                        curTransWord += accent_map_to_use[prevChar] ;
                        prevChar = '';
                    } 
                    if (j== curWord.length-1) curTransWord += accent_map_to_use[curChar] ;

                    prevChar = curChar;
                }
            
            }
            ret += curTransWord + wordSeparator;
        }
        if (tObj.selSlokaTypeIndex == 0) // this is sanskrit verse so replace 
        {
                ret = ret.replace(/[\u0112\u0113]/gi, 'e');
                ret = ret.replace(/[\u014C\u014D]/gi, 'o');
        }
        return ret;
        };
    } ()); 

    outData.outString = mapEng_char(strInputEng);
    //outString = outString.replace(/^[\s\uFEFF\xA0]+|[\s\uFEFF\xA0]+$/g, '');
   //outData.outString = outData.outString.replace(/^[\s\uFEFF\xA0]+/, ''); 
    
    return outData;
}
function convertEngConsonantToTelugu (tmpCharEng, curCharEng)
{
    var newChar = "$ˆ$";   
    if (tmpCharEng ==null|| curCharEng==null) {alert (curCharEng+tmpCharEng); return newChar;}
    switch (curCharEng)
    {
        case 'a':
            newChar = tmpCharEng.replace('\u0C4D', '');
            break;
        case 'ā':
            newChar = tmpCharEng.replace('\u0C4D', '\u0C3E');
            break;
        case 'A':
            newChar = tmpCharEng.replace('\u0C4D', '\u0C4C');
            break;
        case 'e':
            newChar = tmpCharEng.replace('\u0C4D', '\u0C47');
            break;
        case 'i':
            newChar = tmpCharEng.replace('\u0C4D', '\u0C3F');
            break;
        case 'ī':
            newChar = tmpCharEng.replace('\u0C4D', '\u0C40');
            break;
        case 'I':
            newChar = tmpCharEng.replace('\u0C4D', '\u0C48');
            break;
        case 'o':
            newChar = tmpCharEng.replace('\u0C4D', '\u0C4B');
            break;
        case 'u':
            newChar = tmpCharEng.replace('\u0C4D', '\u0C41');
            break;
        case 'ū':
            newChar = tmpCharEng.replace('\u0C4D', '\u0C42');
            break;
        case 'ṛ':
            newChar = tmpCharEng.replace('\u0C4D', '\u0C43');
            break;
        case 'Ṛ':
            newChar = tmpCharEng.replace('\u0C4D', '\u0C43');
            break;
        case 'Ṝ':
            newChar = tmpCharEng.replace('\u0C4D', '\u0C44');
            break;
        case 'ṝ':
            newChar = tmpCharEng.replace('\u0C4D', '\u0C44');
            break;
        case 'ḷ':
            newChar = tmpCharEng.replace('\u0C4D', '\u0C62');
            break;
        case 'ḹ':
            newChar = tmpCharEng.replace('\u0C4D', '\u0C63');
            break;
        case 'ḥ':
            newChar = tmpCharEng+'\u0C03';
            break;
        default:
        break;
    }
//   alert (tmpCharEng + ": vowel - " + curCharEng + ": newChar - " + newChar);
   return newChar;
}
function checkSpecialTeluguCharCases (inputEngString, selSlokaTypeIndex)
{
    var modString = inputEngString;
    var i = 0, newPos = 0, nCount=0, tmpArr;
    
 // English character y, r, v, m, followed by a space or 'followed by space and next word starts with a vowel should be transliterated as the two words merged apporpriately:
   var regExp1 = /(y\s)|(r\s)|(v\s)|(m\s)|(\s’)|(\s\u0027)|(\s\u2018])/ig;
    while ((tmpArr = regExp1.exec(modString))!= null)
    {
        newPos = regExp1.lastIndex;
        if (newPos < modString.length-1 ) {
            if (checkIfEngVowel(modString[newPos], "Devanagari", selSlokaTypeIndex) == true || tmpArr[0] == "r " ||tmpArr[0].search(/[’\u0027\u2018]/gi)!=-1)
            {
//        alert (tmpArr[0] + modString);
                if (tmpArr[0].search(/[’\u0027\u2018]/gi)!=-1)
                modString = modString.replace(tmpArr [0], tmpArr[0].charAt(1)); // replace the space
                else
                modString = modString.replace(tmpArr [0], tmpArr[0].charAt(0)); // replace the space
//        alert ("aft "+ modString);
            }
            i = newPos+2;
            nCount++;
            if(nCount >50000) {alert ("CHECK!!! In possible infinite loop "+nCount+ " newPos=" + newPos+ " "+ modString); break;} // avoid infinite loop
        }
    }

    return modString;
}
function getTransMap_TeluguToEnglish()
{
    var obj;
    var TeluguToEnglish_singleChar_map = {
        '‘': '‘', '?':'?','—':'—','–':'–','­':'­','‑':'‑','•':'•','^':'^','©':'©','…':'…','¶':'¶','®':'®','§':'§','™':'™','~':'~','`':'`','@':'@','#':'#','$':'$','%':'%','^':'^','&':'&','*':'*','_':'_','+':'+','=':'=','{':'{','[':'[','}':'}',']':']','>':'>','<':'<',
        '\u2018': '\u2018',
        '\u2019': '\u2019', '\u2014':'\u2014',
        '“': '“','"': '"','”':'”',
        '\u2003': '\u2003', '\u00A0':'\u00A0',
        '\n': '\n',
        '\r': '\r',
        '\t': '\t',
        '(': '(', ')': ')',
        '/': '/',
        '-': '-',
        '!': '!',
        ' ': ' ', '\u2009': ' ', '\u200A': ' ',
        '.': '.',
        ',': ',',';':';',':':':',
        '।': '।',
        '॥': '॥',
        '|': '|',
        '‖': '‖', 
        '\u0C66':'0', '\u0C67':'1', '\u0C68':'2', '\u0C69':'3', '\u0C6A':'4', '\u0C6B':'5', '\u0C6C':'6', '\u0C6D':'7', '\u0C6E':'8', '\u0C6F':'9', 
        '\u0C3D': '\u0027',
       '\u0C05': 'a', '\u0C06': 'ā', '\u0C07': 'i', '\u0C08': 'ī', '\u0C09': 'u', '\u0C0A': 'ū', '\u0C0F':'e',  '\u0C13': 'o', // a
        '\u0C14': 'au', '\u0C10': 'ai', '\u0C50': 'oṁ',// au and ai
        '\u0C03': 'ḥ', '\u0C39': 'ha', 'H': 'ha', '\u0C43': 'ṛ', '\u0C44': 'ṝ', '\u0C62': 'ḷ', '\u0C63': 'ḹ',
        '\u0C0B': 'ṛ', 'Ṝ': '\u0C60', '\u0C60': 'ṝ','\u0C61': 'ḷ',
        '\u0C15': 'ka', '\u0C16': 'kha', '\u0C17': 'ga', '\u0C18': 'gha', '\u0C19': 'ṅa', 'Ṅ': '\u0C19\u0C4D', 
        '\u0C1A': 'ca', '\u0C1B': 'cha', '\u0C1C': 'ja', '\u0C1D': 'jha', '\u0C1E': 'ña', 'Ñ': '\u0C1E\u0C4D', 
        '\u0C1F': 'ṭa', '\u0C20': 'ṭha', '\u0C21': 'ḍa', '\u0C22': 'ḍha', '\u0C23': 'ṇa', 'Ṇ': '\u0C23\u0C4D',
        '\u0C24': 'ta', '\u0C25': 'tha', '\u0C26': 'da', '\u0C27': 'dha', '\u0C28': 'na', 'N': '\u0C28\u0C4D',
        '\u0C2A': 'pa', '\u0C2B': 'pha', '\u0C2C': 'ba', '\u0C2D': 'bha', '\u0C2E': 'ma', 'M': '\u0C2E\u0C4D', '\u0C02': 'ṁ',
        '\u0C2F': 'ya', 'Y': '\u0C2F\u0C4D', '\u0C30': 'ra', 'R': '\u0930\u0C4D', '\u0C32': 'la', 'L': '\u0C32\u0C4D', '\u0C33': 'ḹa', '\u0C0C': 'ḷ',  'Ḷ': '\u0C0C\u0C4D', '\u0C35': 'va', 'V': '\u0C35\u0C4D', 
        '\u0C36': 'śa', 'Ś': '\u0C37\u0C4D', '\u0C37': 'ṣa', '\u0C35': 'va', '\u0C38': 'sa', 
        'Ṣ': 'kṣ',
        'S': 'śrī',        
         };

     obj = TeluguToEnglish_singleChar_map;
    
    return obj;
}

function transliterateTeluguToEnglish (strInputTelugu, tObj)
{
    var bUseNumbers = tObj.bUseNumbers;
    var wordSeparator = tObj.wordSeparator;
    
    var outData = {
        outString: "",
        bAccentReplaced: false,
        bFirstCharAccented: false,
        };
    var mapTelugu_char = (function () {
        var accent_map_to_use;
        accent_map_to_use= getTransMappedObject("Telugu", "English", bUseNumbers, tObj.selSlokaTypeIndex);
        return function mapTelugu_char(sOrj) {
        var s = sOrj, i,j, wordArray, prevChar, curChar, nextChar, curWord;
        if (!s) { return ''; }
            
            s= s.replace(/w/gi, "v");
            s= s.replace(/\u0C36\u0C4D\u0C30\u0C40/gi, "S");
            s= s.replace(/\u0C15\u0C4D\u0C36\u0C4D/gi, "Ṣ");

            //alert("aft "+s);
            //s= checkSpecialDevanagariCharCases (s);
        var ret = '', tmpChar , tmpMsg = 0, curTransWord='';
        wordArray = s.split (" ");
        //alert(wordArray.length);
        for (i=0; i< wordArray.length; i++) {
            curWord = wordArray[i];
            prevChar = '';
            nextChar = '';
            curTransWord = '';
            //alert(curWord);
            for (j = 0; j < curWord.length; j++) {
                curChar = curWord[j];
                if (j+1< curWord.length) nextChar = curWord[j+1]; else nextChar = '';
            //alert(curChar+" "+nextChar);
                if (checkIfTeluguVowel(curChar)) {
                    if (prevChar != '') {
                        tmpChar = accent_map_to_use[prevChar];
                        if (tmpChar != null && tmpChar != '' && tmpChar != prevChar) 
                        curChar = convertTeluguToEngConsonant (prevChar, curChar, nextChar, tmpChar);
                        else curChar = prevChar + accent_map_to_use[curChar] ;
                        curTransWord += curChar;
                    } else curTransWord += accent_map_to_use[curChar] ;
                    prevChar = '';
                } else {
                    if (prevChar != '') {
                        tmpChar = accent_map_to_use[prevChar] ;
                        tmpChar = validateNumberedTamilConsonant (prevChar, curChar, tmpChar);
                        curTransWord += tmpChar;
                        prevChar = '';
                    } 
                    if (j== curWord.length-1) {
                        //alert (prevChar+","+curChar);
                        curTransWord += accent_map_to_use[curChar] 
                        };
                    prevChar = curChar;
                }
            
            }
            ret+= curTransWord + wordSeparator;
        }
        if (tObj.selSlokaTypeIndex == 2) // if this is Tamil poem so replace 
        {
                ret = ret.replace(/e/gi, '\u0113');
                ret = ret.replace(/o/gi, '\u014D');
        }
        return ret;
        };
    } ()); 

    outData.outString = mapTelugu_char(strInputTelugu);
    //outString = outString.replace(/^[\s\uFEFF\xA0]+|[\s\uFEFF\xA0]+$/g, '');
   //outData.outString = outData.outString.replace(/^[\s\uFEFF\xA0]+/, ''); 
    
    return outData;
}
function convertTeluguToEngConsonant (prevCharTel, curCharTel, nextCharTel, tmpCharEng)
{
    var newChar = "$ˆ$";   
    if (tmpCharEng ==null|| curCharTel==null) {alert (curCharTel+tmpCharEng); return newChar;}
    //alert (curCharTel+tmpCharEng);
    switch (curCharTel)
    {
        case '\u0C4D':
            newChar = tmpCharEng.replace('a', '');
            break;
        case '\u0C3E':
            newChar = tmpCharEng.replace('a', 'ā');
            break;
        case '\u0C4C':
            newChar = tmpCharEng.replace('a', 'au');
            break;
        case '\u0C47':
            newChar = tmpCharEng.replace('a', 'e');
            break;
        case '\u0C3F':
            newChar = tmpCharEng.replace('a', 'i');
            break;
        case '\u0C40':
            newChar = tmpCharEng.replace('a', 'ī');
            break;
        case '\u0C48':
            newChar = tmpCharEng.replace('a', 'ai');
            break;
        case '\u0C4B':
            newChar = tmpCharEng.replace('a', 'o');
            break;
        case '\u0C41':
            newChar = tmpCharEng.replace('a', 'u');
            break;
        case '\u0C42':
            newChar = tmpCharEng.replace('a', 'ū');
            break;
        case '\u0C43':
            newChar = tmpCharEng.replace('a', 'ṛ');
            break;
        case '\u0C44':
            newChar = tmpCharEng.replace('a', 'ṝ');
            break;
        case '\u0C62':
            newChar = tmpCharEng.replace('a', 'ḷ');
            break;
        case '\u0C63':
            newChar = tmpCharEng.replace('a', 'ḹ');
            break;
        case '\u0C02':
            //newChar = tmpCharEng.replace('a', '');
             newChar = tmpCharEng+ 'ṁ';
            break;            
        case '\u0C03':
            newChar = tmpCharEng+ 'ḥ';
            break;
        default:
         alert (curCharTel+tmpCharEng);
       
        break;
    }
//   alert (tmpChar + ": vowel - " + curChar + ": newChar - " + newChar);
   return newChar;
}
function checkIfTeluguVowel (charTel)
{
    var bResult = false;
    switch (charTel)
    {
        case '\u0C01':
        case '\u0C02':
        case '\u0C03':
        case '\u0C3E':
        case '\u0C3F':
        case '\u0C40':
        case '\u0C41':
        case '\u0C42':
        case '\u0C43':
        case '\u0C44':
        case '\u0C62':
        case '\u0C63':
        case '\u0C47':
        case '\u0C48':
        case '\u0C4A':
        case '\u0C4B':
        case '\u0C4C':
        case '\u0C4D':
            bResult = true;
            break;
        default:
        break;
    }
//alert (CharTam+bResult);
    return bResult;
}








function transliterateTeluguToDevanagari (strInputTelugu, tObj){
    var outData = {
        outString: "",
        bAccentReplaced: false,
        bFirstCharAccented: false,
        };
    var tmpStr;
    outData= transliterateTeluguToEnglish(strInputTelugu, tObj);
    outData= transliterateEnglishToDevanag (outData.outString, tObj);
    return outData;

}
function transliterateDevanagariToTelugu (strInputTelugu, tObj){
    var outData = {
        outString: "",
        bAccentReplaced: false,
        bFirstCharAccented: false,
        };
    var tmpStr;
    outData= transliterateDevanagToEnglish(strInputTelugu, tObj);
    outData= transliterateEnglishToTelugu (outData.outString, tObj);
    return outData;
}






function getTransMap_EngToDevag()
{
    var obj;
    var EngToDevag_singleChar_map = {
        '‘': '‘', '?':'?','—':'—','–':'–','­':'­','‑':'‑','•':'•','^':'^','©':'©','…':'…','¶':'¶','®':'®','§':'§','™':'™','~':'~','`':'`','@':'@','#':'#','$':'$','%':'%','^':'^','&':'&','*':'*','_':'_','+':'+','=':'=','{':'{','[':'[','}':'}',']':']','>':'>','<':'<',
        '\u2018': '\u2018',
        '\u2019': '\u2019', '\u2014':'\u2014',
        '“': '“','"': '"','”':'”',
        '\u2003': '\u2003', '\u00A0':'\u00A0',
        '\n': '\n',
        '\r': '\r',
        '\t': '\t',
        '(': '(', ')': ')',
        '/': '/',
        '-': '-',
        '!': '!',
        ' ': ' ', '\u2009': ' ', '\u200A': ' ',
        '.': '.',
        ',': ',',';':';',':':':',
        '।': '।',
        '॥': '॥', 
        '|': '|',
        '‖': '‖', 
        '0':'\u0966', '1':'\u0967', '2':'\u0968', '3':'\u0969', '4':'\u096A', '5':'\u096B', '6':'\u096C', '7':'\u096D', '8':'\u096E', '9':'\u096F', 
        '\u0027': '\u093D',
        'a': '\u0905', 'ā': '\u0906', 'i': '\u0907', 'ī': '\u0908', 'u': '\u0909', 'ū': '\u090A', 'e':'\u090F', 'ē':'\u090F', 'o': '\u0913',  'ō': '\u0913',// a
        'A': '\u0914', 'I': '\u0910', 'O': '\u0950', // au and ai and oṁ
        'ḥ': '\u0903', 'h': '\u0939\u094D', 'H': '\u0939',
        'ṛ': '\u090B', 'Ṛ': '\u090B', 'Ṝ': '\u0960', 'ṝ': '\u0960', 
        'k': '\u0915\u094D', 'K': '\u0916\u094D', 'g': '\u0917\u094D', 'G': '\u0918\u094D', 'ṅ': '\u0919\u094D', 'Ṅ': '\u0919\u094D', 
        'c': '\u091A\u094D', 'C': '\u091B\u094D', 'j': '\u091C\u094D', 'J': '\u091D\u094D', 'ñ': '\u091E\u094D', 'Ñ': '\u0B9E\u094D', 
        'ṭ': '\u091F\u094D', 'Ṭ': '\u0920\u094D', 'ḍ': '\u0921\u094D', 'Ḍ': '\u0922\u094D', 'ṇ': '\u0923\u094D', 'Ṇ': '\u0923\u094D', 
        't': '\u0924\u094D', 'T': '\u0925\u094D', 'd': '\u0926\u094D', 'D': '\u0927\u094D', 'n': '\u0928\u094D', 'N': '\u0928\u094D', 
        'p': '\u092A\u094D', 'P': '\u092B\u094D', 'b': '\u092C\u094D', 'B': '\u092D\u094D', 'm': '\u092E\u094D', 'M': '\u092E\u094D', 'ṁ': '\u0902',  'Ṁ': '\u0902', 'ḿ': '\u0902', 'ṃ': '\u0902', 'Ṃ': '\u0902', 'ḿ': '\u0902',
        'y': '\u092F\u094D', 'Y': '\u092F\u094D', 'r': '\u0930\u094D', 'R': '\u0930\u094D', 'l': '\u0932\u094D', 'L': '\u0932\u094D', 'ḹ':'\u0933\u094D', 'Ḹ':'\u0933\u094D', 'ḷ': '\u090C\u094D', 'ḻ': '\u0901\u0932\u094D', 'v': '\u0935\u094D', 'V': '\u0935\u094D', 
        'ś': '\u0936\u094D', 'Ś': '\u0936\u094D', 'ṣ': '\u0937\u094D', 'Ṣ': '\u0935\u094D', 's': '\u0938\u094D', 'S': '\u0936\u094D\u0930\u0940',
         };

     obj = EngToDevag_singleChar_map;
    
    return obj;
}


function transliterateEnglishToDevanag (strInputEng, tObj)
{
    var outData = {
        outString: "",
        bAccentReplaced: false,
        bFirstCharAccented: false,
        };

    var bUseNumbers = tObj.bUseNumbers;
    var wordSeparator = tObj.wordSeparator;
    
    var outData = {
        outString: "",
        bAccentReplaced: false,
        bFirstCharAccented: false,
        };
    var mapEng_char = (function () {
        var accent_map_to_use;
        accent_map_to_use= getTransMappedObject("English", "Devanagari", bUseNumbers, tObj.selSlokaTypeIndex);
        return function mapEng_char(sOrj) {
        var s = sOrj, i,j, wordArray, prevChar, curChar, nextChar, curWord;
        if (!s) { return ''; }
        s = s.toLowerCase();
            
            //alert("b4 "+s);
            s= s.replace(/f/gi, "ph");            
            s= s.replace(/w/gi, "v");            
            s= s.replace(/au/gi, "A");
            s= s.replace(/ai/gi, "I");
            s= s.replace(/oṁ\s/gi, "O ");

            s= s.replace(/ḿ/gi, "ṁ");
            s= s.replace(/ń/gi, "ṅ");
            s= s.replace(/ṛ/gi, "ṛ"); // the two r-dots are different codes. The first one is actually two characters one alphabhet followed by under dot.
            s= s.replace(/ḥ/gi, "ḥ"); // the two h-dots are different codes
            s= s.replace(/ṣ/gi, "ṣ"); // the two s-dots are different codes
            s= s.replace(/ḍ/gi, "ḍ"); // the two d-dots are different codes
            s= s.replace(/ṇ/gi, "ṇ"); // the two n-dots are different codes
            s= s.replace(/ṭ/gi, "ṭ"); // the two t-dots are different codes
            s= s.replace(/ch/gi, "C");
            s= s.replace(/jh/gi, "J");
            s= s.replace(/kh/gi, "K");
            s= s.replace(/gh/gi, "G");
            s= s.replace(/th/gi, "T");
            s= s.replace(/dh/gi, "D");
            s= s.replace(/bh/gi, "B");            
            s= s.replace(/ph/gi, "P");            
            s= s.replace(/ṭh/gi, "Ṭ");
            s= s.replace(/ḍh/gi, "Ḍ");
            s= s.replace(/śrī/gi, "S");

            //alert("aft "+s);
            s= checkSpecialDevanagariCharCases (s, tObj.selSlokaTypeIndex);
        var ret = '', tmpChar , tmpChar2 = '', curTransWord='';
        wordArray = s.split (" ");
        //alert(wordArray.length);
        for (i=0; i< wordArray.length; i++) {
            curWord = wordArray[i];
            prevChar = '';
            nextChar = '';
            curTransWord='';
            //alert(curWord);
            for (j = 0; j < curWord.length; j++) {
                curChar = curWord[j];
            //alert(curChar);
                if (j+1< curWord.length) nextChar = curWord[j+1]; else nextChar = '';            
                if (checkIfEngVowel(curChar, "Devanagari", tObj.selSlokaTypeIndex)) {
                    if (prevChar != '') {
                        tmpChar = accent_map_to_use[prevChar];
                        if (tmpChar != null && tmpChar != '' && tmpChar != prevChar) 
                        curChar = convertEngConsonantToDevanagari (tmpChar, curChar);
                        else curChar = prevChar + accent_map_to_use[curChar] ;
                        curTransWord += curChar;
                    } else curTransWord += accent_map_to_use[curChar] ;
                    prevChar = '';
                } else {
                    if (prevChar != '') {
                        curTransWord += accent_map_to_use[prevChar] ;
                        prevChar = '';
                    } 
                    if (j== curWord.length-1) curTransWord += accent_map_to_use[curChar] ;

                    prevChar = curChar;
                }
            
            }
            ret += curTransWord + wordSeparator;
        }
        if (tObj.selSlokaTypeIndex == 0) // this is sanskrit verse so replace 
        {
                ret = ret.replace(/[\u0112\u0113]/gi, 'e');
                ret = ret.replace(/[\u014C\u014D]/gi, 'o');
        }
        return ret;
        };
    } ()); 

    outData.outString = mapEng_char(strInputEng);
    //outString = outString.replace(/^[\s\uFEFF\xA0]+|[\s\uFEFF\xA0]+$/g, '');
   //outData.outString = outData.outString.replace(/^[\s\uFEFF\xA0]+/, ''); 
    
    return outData;
}
function convertEngConsonantToDevanagari (tmpCharEng, curCharEng)
{
    var newChar = "$ˆ$";   
    if (tmpCharEng ==null|| curCharEng==null) {alert (curCharEng+tmpCharEng); return newChar;}
    switch (curCharEng)
    {
        case 'a':
            newChar = tmpCharEng.replace('\u094D', '');
            break;
        case 'ā':
            newChar = tmpCharEng.replace('\u094D', '\u093E');
            break;
        case 'A':
            newChar = tmpCharEng.replace('\u094D', '\u094C');
            break;
        case 'e':
            newChar = tmpCharEng.replace('\u094D', '\u0947');
            break;
        case 'i':
            newChar = tmpCharEng.replace('\u094D', '\u093F');
            break;
        case 'ī':
            newChar = tmpCharEng.replace('\u094D', '\u0940');
            break;
        case 'I':
            newChar = tmpCharEng.replace('\u094D', '\u0948');
            break;
        case 'o':
            newChar = tmpCharEng.replace('\u094D', '\u094B');
            break;
        case 'u':
            newChar = tmpCharEng.replace('\u094D', '\u0941');
            break;
        case 'ū':
            newChar = tmpCharEng.replace('\u094D', '\u0942');
            break;
        case 'ṛ':
            newChar = tmpCharEng.replace('\u094D', '\u0943');
            break;
        case 'Ṛ':
            newChar = tmpCharEng.replace('\u094D', '\u0943');
            break;
        case 'Ṝ':
            newChar = tmpCharEng.replace('\u094D', '\u0944');
            break;
        case 'ṝ':
            newChar = tmpCharEng.replace('\u094D', '\u0944');
            break;
        case 'ḷ':
            newChar = tmpCharEng.replace('\u094D', '\u0962');
            break;
        case 'ḹ':
            newChar = tmpCharEng.replace('\u094D', '\u0963');
            break;
        case 'Ḹ':
            newChar = tmpCharEng.replace('\u094D', '\u0963');
            break;
            
        case 'ḥ':
            newChar = tmpCharEng+'\u0903';
            break;
        default:
        break;
    }
//   alert (tmpCharEng + ": vowel - " + curCharEng + ": newChar - " + newChar);
   return newChar;
}
function checkSpecialDevanagariCharCases (inputEngString, selSlokaTypeIndex)
{
    var modString = inputEngString;
    var i = 0, newPos = 0, nCount=0, tmpArr;
    
 // English character y, r, v, m, followed by a space or 'followed by space and next word starts with a vowel should be transliterated as the two words merged apporpriately:
   var regExp1 = /(y\s)|(r\s)|(v\s)|(m\s)|(\s’)|(\s\u0027)|(\s\u2018])/ig;
    while ((tmpArr = regExp1.exec(modString))!= null)
    {
        newPos = regExp1.lastIndex;
        if (newPos < modString.length-1 ) {
            if (checkIfEngVowel(modString[newPos], "Devanagari", selSlokaTypeIndex) == true || tmpArr[0] == "r " ||tmpArr[0].search(/[’\u0027\u2018]/gi)!=-1)
            {
//        alert (tmpArr[0] + modString);
                if (tmpArr[0].search(/[’\u0027\u2018]/gi)!=-1)
                modString = modString.replace(tmpArr [0], tmpArr[0].charAt(1)); // replace the space
                else
                modString = modString.replace(tmpArr [0], tmpArr[0].charAt(0)); // replace the space
//        alert ("aft "+ modString);
            }
            i = newPos+2;
            nCount++;
            if(nCount >50000) {alert ("CHECK!!! In possible infinite loop "+nCount+ " newPos=" + newPos+ " "+ modString); break;} // avoid infinite loop
        }
    }

    return modString;
}
function getTransMap_DevagToEnglish()
{
    var obj;
    var DevagToEnglish_singleChar_map = {
        '‘': '‘', '?':'?','—':'—','–':'–','­':'­','‑':'‑','•':'•','^':'^','©':'©','…':'…','¶':'¶','®':'®','§':'§','™':'™','~':'~','`':'`','@':'@','#':'#','$':'$','%':'%','^':'^','&':'&','*':'*','_':'_','+':'+','=':'=','{':'{','[':'[','}':'}',']':']','>':'>','<':'<',
        '\u2018': '\u2018',
        '\u2019': '\u2019', '\u2014':'\u2014',
        '“': '“','"': '"','”':'”',
        '\u2003': '\u2003', '\u00A0':'\u00A0',
        '\n': '\n',
        '\r': '\r',
        '\t': '\t',
        '(': '(', ')': ')',
        '/': '/',
        '-': '-',
        '!': '!',
        ' ': ' ', '\u2009': ' ', '\u200A': ' ',
        '.': '.',
        ',': ',',';':';',':':':',
        '।': '।',
        '॥': '॥',
        '|': '|',
        '‖': '‖', 
        '\u0966':'0', '\u0967':'1', '\u0968':'2', '\u0969':'3', '\u096A':'4', '\u096B':'5', '\u096C':'6', '\u096D':'7', '\u096E':'8', '\u096F':'9', 
        '\u093D': '\u0027',
       '\u0905': 'a', '\u0906': 'ā', '\u0907': 'i', '\u0908': 'ī', '\u0909': 'u', '\u090A': 'ū', '\u090F':'e',  '\u0913': 'o', // a
        '\u0914': 'au', '\u0910': 'ai', '\u0950': 'oṁ',// au and ai
        '\u0903': 'ḥ', '\u0939': 'ha', 'H': 'ha', '\u0943': 'ṛ', '\u0944': 'ṝ', '\u0962': 'ḷ', '\u0963': 'ḹ',
        '\u090B': 'ṛ', 'Ṝ': '\u0960', '\u0960': 'ṝ','\u0961': 'ḷ',
        '\u0915': 'ka', '\u0916': 'kha', '\u0917': 'ga', '\u0918': 'gha', '\u0919': 'ṅa', 'Ṅ': '\u0919\u094D', 
        '\u091A': 'ca', '\u091B': 'cha', '\u091C': 'ja', '\u091D': 'jha', '\u091E': 'ña', 'Ñ': '\u091E\u094D', 
        '\u091F': 'ṭa', '\u0920': 'ṭha', '\u0921': 'ḍa', '\u0922': 'ḍha', '\u0923': 'ṇa', 'Ṇ': '\u0923\u094D',
        '\u0924': 'ta', '\u0925': 'tha', '\u0926': 'da', '\u0927': 'dha', '\u0928': 'na', 'N': '\u0928\u094D',
        '\u092A': 'pa', '\u092B': 'pha', '\u092C': 'ba', '\u092D': 'bha', '\u092E': 'ma', 'M': '\u092E\u094D', '\u0902': 'ṁ',
        '\u092F': 'ya', 'Y': '\u092F\u094D', '\u0930': 'ra', 'R': '\u0930\u094D', '\u0932': 'la', 'L': '\u0932\u094D', '\u0933': 'Ḹa', '\u090C': 'ḷ',  'Ḷ': '\u090C\u094D', '\u0935': 'va', 'V': '\u0935\u094D', 
        '\u0936': 'śa', 'Ś': '\u0937\u094D', '\u0937': 'ṣa', '\u0935': 'va', '\u0938': 'sa', 
        'Ṣ': 'kṣ',
        'S': 'śrī',
        '\u0027':'\u0027',
        '\u0022':'\u0022',
         };

     obj = DevagToEnglish_singleChar_map;
    
    return obj;
}

function transliterateDevanagToEnglish (strInputDevag, tObj)
{
    var bUseNumbers = tObj.bUseNumbers;
    var wordSeparator = tObj.wordSeparator;
    
    var outData = {
        outString: "",
        bAccentReplaced: false,
        bFirstCharAccented: false,
        };
    var mapDevag_char = (function () {
        var accent_map_to_use;
        accent_map_to_use= getTransMappedObject("Devanagari", "English", bUseNumbers, tObj.selSlokaTypeIndex);
        return function mapDevag_char(sOrj) {
        var s = sOrj, i,j, wordArray, prevChar, curChar, nextChar, curWord;
        if (!s) { return ''; }
            //replace successive straight quotes to a double quote
            s= s.replace(/\u0027\u0027/gi,'\u0022');
            s= s.replace(/w/gi, "v");
            s= s.replace(/\u0936\u094D\u0930\u0940/gi, "S");
            s= s.replace(/\u0915\u094D\u0936\u094D/gi, "Ṣ");

            //alert("aft "+s);
            //s= checkSpecialDevanagariCharCases (s);
        var ret = '', tmpChar , tmpMsg = 0, curTransWord='';
        wordArray = s.split (" ");
        //alert(wordArray.length);
        for (i=0; i< wordArray.length; i++) {
            curWord = wordArray[i];
            prevChar = '';
            nextChar = '';
            curTransWord = '';
            //alert(curWord);
            for (j = 0; j < curWord.length; j++) {
                curChar = curWord[j];
                if (j+1< curWord.length) nextChar = curWord[j+1]; else nextChar = '';
            //alert(curChar+" "+nextChar);
                if (checkIfDevagVowel(curChar)) {
                    if (prevChar != '') {
                        tmpChar = accent_map_to_use[prevChar];
                        if (tmpChar != null && tmpChar != '' && tmpChar != prevChar) 
                        curChar = convertDevagToEngConsonant (prevChar, curChar, nextChar, tmpChar);
                        else curChar = prevChar + accent_map_to_use[curChar] ;
                        curTransWord += curChar;
                    } else curTransWord += accent_map_to_use[curChar] ;
                    prevChar = '';
                } else {
                    if (prevChar != '') {
                        tmpChar = accent_map_to_use[prevChar] ;
                        tmpChar = validateNumberedTamilConsonant (prevChar, curChar, tmpChar);
                        curTransWord += tmpChar;
                        prevChar = '';
                    } 
                    if (j== curWord.length-1) {
                        //alert (prevChar+","+curChar);
                        curTransWord += accent_map_to_use[curChar] 
                        };
                    prevChar = curChar;
                }
            
            }
            ret+= curTransWord + wordSeparator;
        }
        if (tObj.selSlokaTypeIndex == 2) // if this is Tamil poem so replace 
        {
                ret = ret.replace(/e/gi, '\u0113');
                ret = ret.replace(/o/gi, '\u014D');
        }
        return ret;
        };
    } ()); 

    outData.outString = mapDevag_char(strInputDevag);
    //outString = outString.replace(/^[\s\uFEFF\xA0]+|[\s\uFEFF\xA0]+$/g, '');
   //outData.outString = outData.outString.replace(/^[\s\uFEFF\xA0]+/, ''); 
    
    return outData;
}
function convertDevagToEngConsonant (prevCharDev, curCharDev, nextCharDev, tmpCharEng)
{
    var newChar = "$ˆ$";   
    if (tmpCharEng ==null|| curCharDev==null) {alert (curCharDev+tmpCharEng); return newChar;}
    //alert (curCharDev+tmpCharEng);
    switch (curCharDev)
    {
        case '\u094D':
            newChar = tmpCharEng.replace('a', '');
            break;
        case '\u093E':
            newChar = tmpCharEng.replace('a', 'ā');
            break;
        case '\u094C':
            newChar = tmpCharEng.replace('a', 'au');
            break;
        case '\u0947':
            newChar = tmpCharEng.replace('a', 'e');
            break;
        case '\u093F':
            newChar = tmpCharEng.replace('a', 'i');
            break;
        case '\u0940':
            newChar = tmpCharEng.replace('a', 'ī');
            break;
        case '\u0948':
            newChar = tmpCharEng.replace('a', 'ai');
            break;
        case '\u094B':
            newChar = tmpCharEng.replace('a', 'o');
            break;
        case '\u0941':
            newChar = tmpCharEng.replace('a', 'u');
            break;
        case '\u0942':
            newChar = tmpCharEng.replace('a', 'ū');
            break;
        case '\u0943':
            newChar = tmpCharEng.replace('a', 'ṛ');
            break;
        case '\u0944':
            newChar = tmpCharEng.replace('a', 'ṝ');
            break;
        case '\u0962':
            newChar = tmpCharEng.replace('a', 'ḷ');
            break;
        case '\u0963':
            newChar = tmpCharEng.replace('a', 'ḹ');
            break;
        case '\u0902':
            //newChar = tmpCharEng.replace('a', '');
             newChar = tmpCharEng+ 'ṁ';
            break;            
        case '\u0903':
            newChar = tmpCharEng+ 'ḥ';
            break;
        default:
         alert (curCharDev+tmpCharEng);
       
        break;
    }
//   alert (tmpChar + ": vowel - " + curChar + ": newChar - " + newChar);
   return newChar;
}
function checkIfDevagVowel (charDev)
{
    var bResult = false;
    switch (charDev)
    {
        case '\u0901':
        case '\u0902':
        case '\u0903':
        case '\u093E':
        case '\u093F':
        case '\u0940':
        case '\u0941':
        case '\u0942':
        case '\u0943':
        case '\u0944':
        case '\u0962':
        case '\u0963':
        case '\u0947':
        case '\u0948':
        case '\u094A':
        case '\u094B':
        case '\u094C':
        case '\u094D':
            bResult = true;
            break;
        default:
        break;
    }
//alert (CharTam+bResult);
    return bResult;
}

function getTransMap_EngToTamil_BengaliVersion (withNum)
{
    var obj;
    var EngToTamil_singleChar_map = {
        '‘': '‘', '?':'?','—':'—','–':'–','­':'­','‑':'‑','•':'•','^':'^','©':'©','…':'…','¶':'¶','®':'®','§':'§','™':'™','~':'~','`':'`','@':'@','#':'#','$':'$','%':'%','^':'^','&':'&','*':'*','_':'_','+':'+','=':'=','{':'{','[':'[','}':'}',']':']','>':'>','<':'<',
        '\u2018': '\u2018',
        '\u2019': '\u2019', '\u2014':'\u2014',
        '“': '“','"': '"','”':'”',
        '\u2003': '\u2003', '\u00A0':'\u00A0',
        '\n': '\n',
        '\r': '\r',
        '\t': '\t',
        '(': '(', ')': ')',
        '/': '/',
        '-': '-',
        '!': '!',
        ' ': ' ', '\u2009': ' ', '\u200A': ' ',
        '.': '.',
        ',': ',',';':';',':':':',
        '।': '।',
        '॥': '॥', '0':'0', '1':'1', '2':'2', '3':'3', '4':'4', '5':'5', '6':'6', '7':'7', '8':'8', '9':'9', 
        '\u2082':'\u20882', '\u00b2':'\u00b2', 
        '\u2083':'\u2083', '\u00b3':'\u00b3', 
        '\u2084':'\u2084', '\u2074':'\u2074', 
        '|': '|',
        '‖': '‖', 
        '\u0027': '\u0027',
        'ā': '\u0B86', 'a': '\u0B85', 'i': '\u0B87', 'ī': '\u0B88', 'u': '\u0B89', 'U': '\u0B89', 'ū': '\u0B8A', 'e':'\u0B8F', 'ē':'\u0B8F', 'o': '\u0B93',  'ō': '\u0B93',// a
        'A': '\u0B94', 'I': '\u0B90', // au and ai
        'ḥ': ':', 'h': '\u0BB9\u0BCD', 'H': ':',
        '\u1e5b': '\u0BB0\u0BC1', '\u1e5a': '\u0BB0\u0BC1', 
        'ṛ': '\u0BB0\u0BBF', 'Ṛ': '\u0BB0\u0BBF', 'Ṝ': '\u0BB0\u0BC0', 'ṝ': '\u0BB0\u0BC0',
        'ṙ': '\u0B83\u0B9F', 'Ṙ': '\u0B83\u0B9F', 
        'k': '\u0B95\u0BCD', 'K': '\u0B95\u0BCD', 'g': '\u0B95\u0BCD', 'G': '\u0B95\u0BCD', 'ṅ': '\u0B99\u0BCD', 'Ṅ': '\u0B99\u0BCD', 
        'c': '\u0B9A\u0BCD', 'C': '\u0B9A\u0BCD', 'j': '\u0B9C\u0BCD', 'J': '\u0B9C\u0BCD', 'ñ': '\u0B9E\u0BCD', 'Ñ': '\u0B9E\u0BCD', 
        'ṭ': '\u0B9F\u0BCD', 'Ṭ': '\u0B9F\u0BCD', 'ḍ': '\u0B9F\u0BCD', 'Ḍ': '\u0B9F\u0BCD', 'ṇ': '\u0BA3\u0BCD', 'Ṇ': '\u0BA3\u0BCD', 
        't': '\u0BA4\u0BCD', 'T': '\u0BA4\u0BCD', 'd': '\u0BA4\u0BCD', 'D': '\u0BA4\u0BCD', 'n': '\u0BA9\u0BCD', 'N': '\u0BA8\u0BCD', 
        'p': '\u0BAA\u0BCD', 'P': '\u0BAA\u0BCD', 'b': '\u0BAA\u0BCD', 'B': '\u0BAA\u0BCD', 'm': '\u0BAE\u0BCD', 'M': '\u0BAE\u0BCD', 'ṁ': '\u0BAE\u0BCD',  'Ṁ': '\u0BAE\u0BCD', 'ḿ': '\u0BAE\u0BCD', 'ṃ': '\u0BAE\u0BCD', 'Ṃ': '\u0BAE\u0BCD', 'ḿ': '\u0BAE\u0BCD',
        'y': '\u0BAF\u0BCD', 'Y': '\u0BAF\u0BCD', 'r': '\u0BB0\u0BCD', 'R': '\u0BB0\u0BCD', 'l': '\u0BB2\u0BCD', 'L': '\u0BB2\u0BCD', 'ḷ': '\u0BB3\u0BCD', 'ḻ': '\u0BB2\u0BCD',  'v': '\u0BB5\u0BCD', 'V': '\u0BB5\u0BCD', 
        'ś': '\u0BB7\u0BCD', 'Ś': '\u0BB7\u0BCD', 'ṣ': '\u0BB7\u0BCD', 'Ṣ': '\u0B95\u0BCD\u0BB7', 's': '\u0BB8\u0BCD', 'S': '\u0BB8\u0BCD\u0BB0\u0BC0',
         };

    var EngToTamil_singleChar_map_withNum = {
        '#':'#',
        '‘': '‘', '?':'?','—':'—','–':'–','­':'­','‑':'‑','•':'•','^':'^','©':'©','…':'…','¶':'¶','®':'®','§':'§','™':'™','~':'~','`':'`','@':'@','#':'#','$':'$','%':'%','^':'^','&':'&','*':'*','_':'_','+':'+','=':'=','{':'{','[':'[','}':'}',']':']','>':'>','<':'<',
        '\u2018': '\u2018',
        '\u2019': '\u2019', '\u2014':'\u2014',
        '“': '“','"': '"','”':'”',
        '\u2003': '\u2003', '\u00A0':'\u00A0',
        '\n': '\n',
        '\r': '\r',
        '\t': '\t',
        '(': '(', ')': ')',
        '/': '/',
        '-': '-',
        '!': '!',
        ' ': ' ', '\u2009': ' ', '\u200A': ' ',
        '.': '.',
        ',': ',',';':';',':':':',
        '।': '।',
        '॥': '॥', '0':'0', '1':'1', '2':'2', '3':'3', '4':'4', '5':'5', '6':'6', '7':'7', '8':'8', '9':'9', 
        '\u2082':'\u20882', '\u00b2':'\u00b2', 
        '\u2083':'\u2083', '\u00b3':'\u00b3', 
        '\u2084':'\u2084', '\u2074':'\u2074', 
        '|': '|',
        '‖': '‖', 
        '\u0027': '\u0027',
        'ā': '\u0B86', 'a': '\u0B85', 'i': '\u0B87', 'ī': '\u0B88', 'u': '\u0B89', 'U': '\u0B89', 'ū': '\u0B8A','e':'\u0B8F', 'ē':'\u0B8F', 'o': '\u0B93',  'ō': '\u0B93',// a
        'A': '\u0B94', 'I': '\u0B90', // au and ai
        'ḥ': ':', 'h': '\u0BB9\u0BCD', 'H': ':',
        'ṛ': '\u0BB0\u0BBF\u0027', 'Ṛ': '\u0BB0\u0BBF\u0027', 'Ṝ': '\u0BB0\u0BC0\u0027', 'ṝ': '\u0BB0\u0BC0\u0027',
        'ṙ': '\u0B83\u0B9F\u0033', 'Ṙ': '\u0B83\u0B9F\u0034', 
        'k': '\u0B95\u0BCD', 'K': '\u0B95\u0BCD\u0032', 'g': '\u0B95\u0BCD\u0033', 'G': '\u0B95\u0BCD\u0034', 'ṅ': '\u0B99\u0BCD', 'Ṅ': '\uE181', 
        'c': '\u0B9A\u0BCD', 'C': '\u0B9A\u0BCD\u0032', 'j': '\u0B9C\u0BCD', 'J': '\u0B9C\u0BCD\u0032', 'ñ': '\u0B9E\u0BCD', 'Ñ': '\u0B9E\u0BCD', 
        'ṭ': '\u0B9F\u0BCD', 'Ṭ': '\u0B9F\u0BCD\u0032', 'ḍ': '\u0B9F\u0BCD\u0033', 'Ḍ': '\u0B9F\u0BCD\u0034', 'ḏ':'\u0B83\u0B9F\u0BCD\u0033','Ḏ':'\u0B83\u0B9F\u0BCD\u0034','ṇ': '\u0BA3\u0BCD', 'Ṇ': '\u0BA3\u0BCD', 
        't': '\u0BA4\u0BCD', 'T': '\u0BA4\u0BCD\u0032', 'd': '\u0BA4\u0BCD\u0033', 'D': '\u0BA4\u0BCD\u0034', 'n': '\u0BA9\u0BCD', 'N': '\u0BA8\u0BCD', 
        'p': '\u0BAA\u0BCD', 'P': '\u0BAA\u0BCD\u0032', 'b': '\u0BAA\u0BCD\u0033', 'B': '\u0BAA\u0BCD\u0034', 'm': '\u0BAE\u0BCD', 'M': '\u0BAE\u0BCD', 'ṁ': '\u0BAE\u0BCD\u0027',  'Ṁ': '\u0BAE\u0BCD\u0027',  'ḿ': '\u0BAE\u0BCD\u0027', 'ṃ': '\u0BAE\u0BCD\u0027', 'Ṃ': '\u0BAE\u0BCD\u0027', 'ḿ': '\u0BAE\u0BCD\u0027',
        'y': '\u0BAF\u0BCD', 'Y': '\u0B9C\u0BCD\u0033', 'r': '\u0BB0\u0BCD', 'R': '\u0BB0\u0BCD', 'l': '\u0BB2\u0BCD', 'L': '\u0BB2\u0BCD', 'ḷ': '\u0BB3\u0BCD\u0027', 'ḻ': '\u0BB2\u0BCD', 'v': '\u0BB5\u0BCD', 'V': '\u0BB5\u0BCD', 
        'ś': '\u0BB7\u0BCD\u0032', 'Ś': '\u0BB7\u0BCD', 'ṣ': '\u0BB7\u0BCD', 'Ṣ': '\u0B95\u0BCD\u0BB7', 's': '\u0BB8\u0BCD', 'S': '\u0BB8\u0BCD\u0BB0\u0BC0',
         };     
     if (withNum == true) obj = EngToTamil_singleChar_map_withNum; else obj = EngToTamil_singleChar_map;
     return obj;
    
}
function getTransMap_EngToTamil(withNum)
{
    var obj;
    var EngToTamil_singleChar_map = {
        '‘': '‘', '?':'?','—':'—','–':'–','­':'­','‑':'‑','•':'•','^':'^','©':'©','…':'…','¶':'¶','®':'®','§':'§','™':'™','~':'~','`':'`','@':'@','#':'#','$':'$','%':'%','^':'^','&':'&','*':'*','_':'_','+':'+','=':'=','{':'{','[':'[','}':'}',']':']','>':'>','<':'<',
        '\u2018': '\u2018',
        '\u2019': '\u2019', '\u2014':'\u2014',
        '“': '“','"': '"','”':'”',
        '\u2003': '\u2003', '\u00A0':'\u00A0',
        '\n': '\n',
        '\r': '\r',
        '\t': '\t',
        '(': '(', ')': ')',
        '/': '/',
        '-': '-',
        '!': '!',
        ' ': ' ', '\u2009': ' ', '\u200A': ' ',
        '.': '.',
        ',': ',',';':';',':':':',
        '।': '।',
        '॥': '॥', '0':'0', '1':'1', '2':'2', '3':'3', '4':'4', '5':'5', '6':'6', '7':'7', '8':'8', '9':'9',
        '\u2082':'\u20882', '\u00b2':'\u00b2', 
        '\u2083':'\u2083', '\u00b3':'\u00b3', 
        '\u2084':'\u2084', '\u2074':'\u2074', 
        '|': '|',
        '‖': '‖', 
        '\u0027': '\u0027',
        'ā': '\u0B86', 'a': '\u0B85', 'i': '\u0B87', 'ī': '\u0B88', 'u': '\u0B89', 'U': '\u0B89', 'ū': '\u0B8A', 'e':'\u0B8F', 'ē':'\u0B8F', 'o': '\u0B93',  'ō': '\u0B93',// a
        'A': '\u0B94', 'I': '\u0B90', // au and ai
        'ḥ': ':', 'h': '\u0BB9\u0BCD', 'H': ':',
        '\u1e5b': '\u0BB0\u0BC1', '\u1e5a': '\u0BB0\u0BC1',
        'ṛ': '\u0BB0\u0BC1', 'Ṛ': '\u0BB0\u0BC1', 'Ṝ': '\u0BB0\u0BC2', 'ṝ': '\u0BB0\u0BC2',
        'k': '\u0B95\u0BCD', 'K': '\u0B95\u0BCD', 'g': '\u0B95\u0BCD', 'G': '\u0B95\u0BCD', 'ṅ': '\u0B99\u0BCD', 'Ṅ': '\u0B99\u0BCD', 
        'c': '\u0B9A\u0BCD', 'C': '\u0B9A\u0BCD', 'j': '\u0B9C\u0BCD', 'J': '\u0B9C\u0BCD', 'ñ': '\u0B9E\u0BCD', 'Ñ': '\u0B9E\u0BCD', 
        'ṭ': '\u0B9F\u0BCD', 'Ṭ': '\u0B9F\u0BCD', 'ḍ': '\u0B9F\u0BCD', 'Ḍ': '\u0B9F\u0BCD', 'ṇ': '\u0BA3\u0BCD', 'Ṇ': '\u0BA3\u0BCD', 
        't': '\u0BA4\u0BCD', 'T': '\u0BA4\u0BCD', 'd': '\u0BA4\u0BCD', 'D': '\u0BA4\u0BCD', 'n': '\u0BA9\u0BCD', 'N': '\u0BA8\u0BCD', 
        'p': '\u0BAA\u0BCD', 'P': '\u0BAA\u0BCD', 'b': '\u0BAA\u0BCD', 'B': '\u0BAA\u0BCD', 'm': '\u0BAE\u0BCD', 'M': '\u0BAE\u0BCD', 'ṁ': '\u0BAE\u0BCD',  'Ṁ': '\u0BAE\u0BCD', 'ḿ': '\u0BAE\u0BCD', 'ṃ': '\u0BAE\u0BCD', 'Ṃ': '\u0BAE\u0BCD', 'ḿ': '\u0BAE\u0BCD',
        'y': '\u0BAF\u0BCD', 'Y': '\u0BAF\u0BCD', 'r': '\u0BB0\u0BCD', 'R': '\u0BB0\u0BCD', 'l': '\u0BB2\u0BCD', 'L': '\u0BB2\u0BCD', 'ḷ': '\u0BB3\u0BCD', 'ḻ': '\u0BB2\u0BCD',  'v': '\u0BB5\u0BCD', 'V': '\u0BB5\u0BCD', '\u1E39':'\u0BB2\u0BCD',
        'ś': '\u0BB7\u0BCD', 'Ś': '\u0BB7\u0BCD', 'ṣ': '\u0BB7\u0BCD', 'Ṣ': '\u0B95\u0BCD\u0BB7', 's': '\u0BB8\u0BCD', 'S': '\u0BB8\u0BCD\u0BB0\u0BC0',
         };

    var EngToTamil_singleChar_map_withNum = {
        '‘': '‘', '?':'?','—':'—','–':'–','­':'­','‑':'‑','•':'•','^':'^','©':'©','…':'…','¶':'¶','®':'®','§':'§','™':'™','~':'~','`':'`','@':'@','#':'#','$':'$','%':'%','^':'^','&':'&','*':'*','_':'_','+':'+','=':'=','{':'{','[':'[','}':'}',']':']','>':'>','<':'<',
        '\u2018': '\u2018',
        '\u2019': '\u2019', '\u2014':'\u2014',
        '“': '“','"': '"','”':'”',
        '\u2003': '\u2003', '\u00A0':'\u00A0',
        '\n': '\n',
        '\r': '\r',
        '\t': '\t',
        '(': '(', ')': ')',
        '/': '/',
        '-': '-',
        '!': '!',
        ' ': ' ', '\u2009': ' ', '\u200A': ' ',
        '.': '.',
        ',': ',',';':';',':':':',
        '।': '।',
        '॥': '॥', '0':'0', '1':'1', '2':'2', '3':'3', '4':'4', '5':'5', '6':'6', '7':'7', '8':'8', '9':'9',
        '\u2082':'\u20882', '\u00b2':'\u00b2', 
        '\u2083':'\u2083', '\u00b3':'\u00b3', 
        '\u2084':'\u2084', '\u2074':'\u2074', 
        '|': '|',
        '‖': '‖', 
        '\u0027': '\u0027',
        'ā': '\u0B86', 'a': '\u0B85', 'i': '\u0B87', 'ī': '\u0B88', 'u': '\u0B89', 'U': '\u0B89', 'ū': '\u0B8A','e':'\u0B8F', 'ē':'\u0B8F', 'o': '\u0B93',  'ō': '\u0B93',// a
        'A': '\u0B94', 'I': '\u0B90', // au and ai
        'ḥ': ':', 'h': '\u0BB9\u0BCD', 'H': ':',
        'ṛ': '\u0BB0\u0BC1\u0027', 'Ṛ': '\u0BB0\u0BC1\u0027', 'Ṝ': '\u0BB0\u0BC2\u0027', 'ṝ': '\u0BB0\u0BC2\u0027',
        'k': '\u0B95\u0BCD', 'K': '\u0B95\u0BCD\u0032', 'g': '\u0B95\u0BCD\u0033', 'G': '\u0B95\u0BCD\u0034', 'ṅ': '\u0B99\u0BCD', 'Ṅ': '\u0B99\u0BCD', 
        'c': '\u0B9A\u0BCD', 'C': '\u0B9A\u0BCD\u0032', 'j': '\u0B9C\u0BCD', 'J': '\u0B9C\u0BCD\u0032', 'ñ': '\u0B9E\u0BCD', 'Ñ': '\u0B9E\u0BCD', 
        'ṭ': '\u0B9F\u0BCD', 'Ṭ': '\u0B9F\u0BCD\u0032', 'ḍ': '\u0B9F\u0BCD\u0033', 'Ḍ': '\u0B9F\u0BCD\u0034', 'ṇ': '\u0BA3\u0BCD', 'Ṇ': '\u0BA3\u0BCD', 
        't': '\u0BA4\u0BCD', 'T': '\u0BA4\u0BCD\u0032', 'd': '\u0BA4\u0BCD\u0033', 'D': '\u0BA4\u0BCD\u0034', 'n': '\u0BA9\u0BCD', 'N': '\u0BA8\u0BCD', 
        'p': '\u0BAA\u0BCD', 'P': '\u0BAA\u0BCD\u0032', 'b': '\u0BAA\u0BCD\u0033', 'B': '\u0BAA\u0BCD\u0034', 'm': '\u0BAE\u0BCD', 'M': '\u0BAE\u0BCD', 'ṁ': '\u0BAE\u0BCD\u0027',  'Ṁ': '\u0BAE\u0BCD\u0027',  'ḿ': '\u0BAE\u0BCD\u0027', 'ṃ': '\u0BAE\u0BCD\u0027', 'Ṃ': '\u0BAE\u0BCD\u0027', 'ḿ': '\u0BAE\u0BCD\u0027',
        'y': '\u0BAF\u0BCD', 'Y': '\u0BAF\u0BCD', 'r': '\u0BB0\u0BCD', 'R': '\u0BB0\u0BCD', 'l': '\u0BB2\u0BCD', 'L': '\u0BB2\u0BCD', 'ḷ': '\u0BB3\u0BCD\u0027', 'ḻ': '\u0BB2\u0BCD', 'v': '\u0BB5\u0BCD', 'V': '\u0BB5\u0BCD', '\u1E39':'\u0BB2\uE181',
        'ś': '\u0BB7\u0BCD\u0032', 'Ś': '\u0BB7\u0BCD', 'ṣ': '\u0BB7\u0BCD', 'Ṣ': '\u0B95\u0BCD\u0BB7', 's': '\u0BB8\u0BCD', 'S': '\u0BB8\u0BCD\u0BB0\u0BC0',
         };     
     if (withNum == true) obj = EngToTamil_singleChar_map_withNum; else obj = EngToTamil_singleChar_map;
     return obj;

}

function transliterateEnglishToTamil (strInputEng, tObj)
{
    var bUseNumbers = tObj.bUseNumbers;
    var wordSeparator = tObj.wordSeparator;
    
    var outData = {
        outString: "",
        bAccentReplaced: false,
        bFirstCharAccented: false,
        };
    var mapEng_char = (function () {
        var accent_map_to_use;
        accent_map_to_use= getTransMappedObject("English", "Tamil", bUseNumbers, tObj.selSlokaTypeIndex);
        return function mapEng_char(sOrj) {
        var s = sOrj, i,j, wordArray, prevChar, curChar, nextChar, curWord;
        if (!s) { return ''; }
        s = s.toLowerCase();
            
            //alert("b4 "+s);
            s= s.replace(/f/gi, "ph");
            s= s.replace(/w/gi, "v");
            s= s.replace(/ḿ/gi, "ṁ");
            s= s.replace(/ń/gi, "ṅ");
            s= s.replace(/ṛ/gi, "ṛ"); // the two r-dots are different codes. The first one is actually two characters one alphabhet followed by under dot.
            s= s.replace(/ḥ/gi, "ḥ"); // the two h-dots are different codes
            s= s.replace(/ṣ/gi, "ṣ"); // the two s-dots are different codes
            s= s.replace(/ḍ/gi, "ḍ"); // the two d-dots are different codes
            s= s.replace(/ṇ/gi, "ṇ"); // the two n-dots are different codes
            s= s.replace(/ṭ/gi, "ṭ"); // the two t-dots are different codes
            s = searchWordsAndReplace (s, tObj.selSlokaTypeIndex); // prepare the english text with appropriate format
            
            s= s.replace(/ch/gi, "C");
            s= s.replace(/jh/gi, "J");
            s= s.replace(/kh/gi, "K");
            s= s.replace(/gh/gi, "G");
            s= s.replace(/th/gi, "T");
            s= s.replace(/dh/gi, "D");
            s= s.replace(/bh/gi, "B");            
            s= s.replace(/ph/gi, "P");            
            s= s.replace(/ṭh/gi, "Ṭ");
            if (tObj.selSlokaTypeIndex == 1 && bUseNumbers == true) {            
                s= s.replace(/ḍh/gi, "Ḏ");
                s= s.replace(/ḍ/gi, "ḏ");
                }
            else {
                s= s.replace(/ḍh/gi, "Ḍ");
                }
            s= s.replace(/śrī/gi, "S");
            s= s.replace(/ṙh/gi, "Ṙ");
            //alert("aft "+s);
            s= checkSpecialTamilCharCases (s, tObj.selSlokaTypeIndex, bUseNumbers);
        var ret = '', tmpChar , tmpChar2 = '', curTransWord='';
        wordArray = s.split (" ");
        //alert(wordArray.length);
        for (i=0; i< wordArray.length; i++) {
            curWord = wordArray[i];
            prevChar = '';
            nextChar = '';
            curTransWord='';
            //alert(curWord);
            for (j = 0; j < curWord.length; j++) {
                curChar = curWord[j];
            //alert("_"+curChar);
                if (j+1< curWord.length) nextChar = curWord[j+1]; else nextChar = '';            
                if (checkIfEngVowel(curChar, "Tamil", tObj.selSlokaTypeIndex, bUseNumbers)) {
                    if (prevChar != '') {
                        tmpChar = accent_map_to_use[prevChar];
                        if (tmpChar != null && tmpChar != '' && tmpChar != prevChar) {
                            tmpChar2 = convertEngConsonantToTamil (tmpChar, curChar);
                            //there are some vowels that do not affect the previous letter [tmpChar]
                            // for example in Bengali.... ṛ
                            if (tmpChar2 == curChar) curChar = tmpChar + accent_map_to_use[curChar] ;
                            else curChar = tmpChar2;
                        }    
                        else curChar = prevChar + accent_map_to_use[curChar] ;
                        curTransWord += curChar;
                    } else curTransWord += accent_map_to_use[curChar] ;
                    //alert("*"+prevChar+"_"+curChar+"_"+curTransWord);
                    prevChar = '';
                } else {
                    //alert("#"+prevChar+"_"+curChar+"_"+curTransWord);
                    if (prevChar != '') {
                        curTransWord += accent_map_to_use[prevChar] ;
                        prevChar = '';
                    } 
                    if (j== curWord.length-1) curTransWord += accent_map_to_use[curChar] ;

                    prevChar = curChar;
                }
            
            }
            ret += curTransWord + wordSeparator;
        }
        if (tObj.selSlokaTypeIndex == 0) // this is sanskrit verse so replace 
        {
                ret = ret.replace(/[\u0112\u0113]/gi, 'e');
                ret = ret.replace(/[\u014C\u014D]/gi, 'o');
        }
        return ret;
        };
    } ()); 

    outData.outString = mapEng_char(strInputEng);
    //outString = outString.replace(/^[\s\uFEFF\xA0]+|[\s\uFEFF\xA0]+$/g, '');
   outData.outString = outData.outString.replace(/(\d):/, ':$1'); 
   outData.outString = outData.outString.replace(/(\d)([\u0981\u0310])/, '$2$1'); 
 return outData;
 }
function convertEngConsonantToTamil (tmpCharTamil, curCharEng)
{
    // the character returned must be the variable tmpCharTamil
    var newChar = "$ˆ$";   
    //alert (curCharEng+tmpCharTamil);
    if (tmpCharTamil ==null|| curCharEng==null) { return newChar;}
    switch (curCharEng)
    {
        case 'a':
            newChar = tmpCharTamil.replace('\u0BCD', '');
            break;
        case 'ā':
            newChar = tmpCharTamil.replace('\u0BCD', '\u0BBE');
            break;
        case 'A':
            newChar = tmpCharTamil.replace('\u0BCD', '\u0BCC');
            break;
        case 'e':
            newChar = tmpCharTamil.replace('\u0BCD', '\u0BC7');
            break;
        case 'i':
            newChar = tmpCharTamil.replace('\u0BCD', '\u0BBF');
            break;
        case 'ī':
            newChar = tmpCharTamil.replace('\u0BCD', '\u0BC0');
            break;
        case 'I':
            newChar = tmpCharTamil.replace('\u0BCD', '\u0BC8');
            break;
        case 'o':
            newChar = tmpCharTamil.replace('\u0BCD', '\u0BCB');
            break;
        case 'u':
            newChar = tmpCharTamil.replace('\u0BCD', '\u0BC1');
            break;
        case 'ū':
            newChar = tmpCharTamil.replace('\u0BCD', '\u0BC2');
            break;
        case 'ḥ':
            newChar = tmpCharTamil+":";
            break;
        case 'ṛ':
            newChar = curCharEng;
            break;
        default:
            newChar = tmpCharTamil;
        break;
    }
//   alert (tmpChar + ": vowel - " + curChar + ": newChar - " + newChar);
   return newChar;
}
function searchWordsAndReplace (inputEngString, textType)
{
    var wListToSearch = getWordsToSearchReplaceObject ();
    var iNdx = 0, jNdx = 0, prefixPos = 2, suffixPos = 3, searchWordPos = 0, replaceWordPos = 1, wordType = 0;
    var strSearch = "", strReplace = "", strPrefix = "", strSuffix= "";
    var searchMask = "is";
    var replaceMask = "";
    
    prefixPos = wListToSearch.searchPrefix;
    suffixPos = wListToSearch.searchSuffix;
    searchWordPos = wListToSearch.toSearch;
    replaceWordPos = wListToSearch.toReplace;
    for (iNdx = 0; iNdx< wListToSearch.allWordsStructure.length; iNdx++)
    {
//alert (String(iNdx) + String(prefixPos) + String(suffixPos)+String(wListToSearch.allWordsStructure.length));
        strPrefix = wListToSearch.allWordsStructure [iNdx][prefixPos];
        strSuffix = wListToSearch.allWordsStructure [iNdx][suffixPos];
        wordType = wListToSearch.allWordsStructure [iNdx][wListToSearch.wordType];
        strSearch = strPrefix + wListToSearch.allWordsStructure [iNdx][searchWordPos] + strSuffix;
        strReplace = wListToSearch.allWordsStructure [iNdx][replaceWordPos];
        //alert (inputEngString);
        var regEx = new RegExp(strSearch, "ig");
        regEx.lastIndex = 0;
        if (wordType == 1 )
        {
            if (textType == wordType) inputEngString = inputEngString.replace (regEx, strReplace);
        } else        inputEngString = inputEngString.replace (regEx, strReplace);
        //alert (strSearch+"<>"+strReplace+"<>");

    }
    return inputEngString;
}
function getWordsToSearchReplaceObject ()
{
    var wordListDict = {
// following fields indicate position within the array
        toSearch:0,
        toReplace:1,
        searchPrefix:2,
        searchSuffix:3,
        wordType:4, //0 sanskrit and 1 bengali
        wrongVariantsArrayToSearch:5, //this should be the last 
        allWordsStructure: [ // see the above fields that define the heading for each element of the following structure
            ["haibe", "ha-ibe#", "", "",1,],
            ["ekai", "eka-i#", "", "",1,],
//            ["hai", "ha-i#", "", "",1,],
            ["lai", "la-i#", "", "",1,],
            ["vai", "$1va-i#$2", "([\\s-,\\u0022\\u201C\\u201D\\u2014\\u2003\\u2018\\u2019\\u0027])", "([\\s-,\\u0022\\u201C\\u201D\\u2014\\u2003\\u2018\\u2019\\u0027])",1,],
            ["hai", "$1ha-i#", "([\\s-,\\u0022\\u201C\\u201D\\u2014\\u2003\\u2018\\u2019\\u0027])", "",1,],
            ["hai", "ha-i#$1", "", "([\\s-,\\u0022\\u201C\\u201D\\u2014\\u2003\\u2018\\u2019\\u0027])",1,],
            ["hau", "haU", "([\\s-,\\u0022\\u201C\\u201D\\u2014\\u2003\\u2018\\u2019\\u0027])", "",1,],
            ["sannyāsī", "saNNyāsī", "", "",0,],
            ["Jagannāth", "JagaNNāth", "", "",0,],
            ["mahānati", "mahāNati", "", "",0,],
            ["mahāniti", "mahāNiti", "", "",0,],
            ["padmanābha", "padmaNābha", "", "",0,],
            ["sāyujya", "sāYujya", "", "",1,],
            ["vidyānagar", "vidyāNagar", "", "",1,],
            ["sanātana", "saNātana", "", "",1,],
            ],
/*        wrongFormatList: [
                    ["haila", ],
                    ["haiyā", "Tamil2English", "English2Bengali", "Bengali2English", "Tamil2Bengali", "Bengali2Tamil", ],
                    ["English2Tamil", "Tamil2English", "English2Devanagari", "Devanagari2English", "Tamil2Devanagari", "Devanagari2Tamil", ],
                    ],
*/        
        
        };
        return wordListDict;
}
function checkSpecialTamilCase_CharacterN(inputEngString, selSlokaTypeIndex, bUseNumbers)
{
    var modString = inputEngString,regExp1,  i = 0, newPos = 0, nCount=0;
 // Implement code that checks language specific rules:
// English character n should be transliterated as follows:
// 1. If n is the first character of the word then it shall always be transliterated as "thannagara na".
// 2. If n is followed by english character "d"or "dh" or "t or th" then it shall be always transliterated as "thannagara na"
// 3. If s. or śrī or Śrī followed by n should be thannanagara

//    modString = modString.replace(/(\S)n([aeiou])\b/gi, "$1n$2"); // if  at end of words >1 character had n then it is rannagara na
//    modString = modString.replace(/(\S)n\b/gi, "$1n"); // if  at end of words >1 character had n then it is rannagara na

    modString = modString.replace(/n([dt])/gi, "N$1"); // n followed by n should be Thannanagara na (N)
    modString = modString.replace(/n(.)([dt])/gi, "N$1$2"); // if na, ni, nu etc... followed by d, D, t, T should be Thannanagara na (N)
    
    modString = modString.replace(/(^s)(.)n/gi, "$1$2N"); // if  at beginning sa, si, su etc...followed by n should be Thannanagara na (N)
    modString = modString.replace(/([\s-,\u0022\u201C\u201D\u2014\u2003\u2018\u2019\u0027]s)(.)n/gi, "$1$2N"); // if  at beginning sa, si, su etc...followed by n should be Thannanagara na (N)

    modString = modString.replace(/(^[Ss])(.)n/gi, "$1$2N"); // if  at beginning sa, si, su etc...followed by n should be Thannanagara na (N)
    modString = modString.replace(/(\s[sS])n/gi, "$1N"); // if  at beginning s etc...followed by n should be Thannanagara na (N)    

    modString = modString.replace(/([(śrī)(Śrī)(śrī.)(Śrī.)])n/gi, "$1N"); // if śrī or Śrī etc...followed by n should be Thannanagara na (N)




    modString= modString.replace(/^n/g, "N"); // if a word starts with n... it should be thannagara na
    modString= modString.replace(/(\s)n/g, '$1N'); // \s will match  white space, carriage return and so on so we need $1 here....
    modString= modString.replace(/\u2003n/gi, "\u2003N"); // 2003 is mspace
    modString= modString.replace(/-n/gi, "-N");  // if hyphen precedes n... then n should be thannanagara N
    modString= modString.replace(/([-,\u0022\u201C\u201D\u2014\u2003\u2018\u2019\u0027])n/gi, '$1N');
// 4. If [m, ma, mi, mu....] or [v, va, vi, vu....] or [t, ta, ti, tu....] or [j, ja, ji, ju....] followed by n 
//          a. that n followed by a consonant should be thannanagara
//          b. that n followed by a vowel should be rannagara na
// 6. If [a, A] followed by k or g followed by n which is followed by a vowel should be rannagara na
//    modString= modString.replace(/(n)(.)(g)/gi,'N$2$3' ); // ex: vidyanagar should have thannanagara na: Decided to add such things in exception list
// 5. In all other cases it shall be transliterated as "rannagara na".

    regExp1=/(m)(.^\s)(n)(.^\s)|(v)(.^\s)(n)(.)|([td])(.^\s)(n)(.)|(j)(.^\s)(n)(.)|([aā])(g)(n)(.)/gi;
    while ((tmpArr = regExp1.exec(modString))!= null)        {
        newPos = regExp1.lastIndex-1;
//alert (String(regExp1) +"\r"+modString[newPos]+String(newPos) +modString);
        if (newPos < modString.length-1 ) {
            if (checkIfEngVowel(modString[newPos], "Tamil", selSlokaTypeIndex, bUseNumbers) == false )
            {
                //alert ("><"+newPos + "><"+tmpArr[0]+"><"+modString);
                    modString = modString.replace(tmpArr[0],tmpArr [0].charAt(0)+tmpArr [0].charAt(1)+ 'N'+tmpArr [0].charAt(3));
                }
                    else 
                    modString = modString.replace(tmpArr[0],tmpArr [0].charAt(0)+tmpArr [0].charAt(1)+ 'n'+tmpArr [0].charAt(3));

            }
                i = newPos+2;
                nCount++;
                if(nCount >50000) {alert ("CHECK!!! In possible infinite loop "+nCount+ " newPos=" + newPos+ " "+ modString); break;} // avoid infinite loop
        
        }
    // the following line should not be moved up......
    modString = modString.replace(/(\S)n([aeiou])\b/gi, "$1n$2"); // if  at end of words >1 character had n then it is rannagara na
    modString = modString.replace(/(\S)n(\s)/gi, "$1n$2"); // if  at end of words >1 character had n then it is rannagara na
   return modString;
}
function checkSpecialTamilCharCases (inputEngString, selSlokaTypeIndex, bUseNumbers)
{
    var modString = inputEngString,regExp1,  i = 0, newPos = 0, nCount=0;
    modString = checkSpecialTamilCase_CharacterN(modString, selSlokaTypeIndex, bUseNumbers);
    if (selSlokaTypeIndex == 1 ) {// special case for Bengali Verses
        if (bUseNumbers == true) {
        // y after r, is always j
        modString= modString.replace(/ry/gi, "rY");
        // y in the beginning is always ja3
        modString= modString.replace(/^y/g, "Y"); // if a word starts with y... it should be j
        modString= modString.replace(/(\s)y/g, '$1Y'); // \s will match  white space, carriage return and so on so we need $1 here....
        modString= modString.replace(/\u2003y/gi, "\u2003Y");
        modString= modString.replace(/-y/gi, "-Y");
        modString= modString.replace(/([\u2018\u2019\u0027])y/gi, '$1Y');

        //  if 'ṅ': ['\u0B99\u0BCD']  is followed by h or space or comma replace it with 'Ṅ': '\uE181'
        modString= modString.replace(/ṅ([rht])/g, 'Ṅ$1'); 
        modString= modString.replace(/([oaāu])ṅ([,\s])/g, '$1Ṅ$2'); 

        // ḏ or Ḏ  in the beginning is always to be presented without \u0B83 i.e  ḍ or Ḍ
        modString= modString.replace(/^ḏ/g, 'ḍ'); // if a word starts with ḍ.. ... it should be without \u0B83
        modString= modString.replace(/^Ḏ/g, 'Ḍ'); // if a word starts with Ḍ ... it should be without \u0B83
        
        modString= modString.replace(/(\s)ḏ/g, '$1ḍ'); // if a word starts with ḍ.. ... it should be without \u0B83
        modString= modString.replace(/(\s)Ḏ/g, '$1Ḍ'); // if a word starts with Ḍ ... it should be without \u0B83

        modString= modString.replace(/\u2003ḏ/gi, "\u2003ḍ");
        modString= modString.replace(/-ḏ/gi, "-ḍ");
        modString= modString.replace(/\u2003Ḏ/gi, "\u2003Ḍ");
        modString= modString.replace(/-Ḏ/gi, "-Ḍ");
        modString= modString.replace(/([\u2018\u2019\u0027])ḏ/g, '$1ḍ'); // if a word starts with ḍ.. ... it should be without \u0B83
        modString= modString.replace(/([\u2018\u2019\u0027])Ḏ/g, '$1Ḍ'); // if a word starts with Ḍ ... it should be without \u0B83
        regExp1 = /(.ḏ.)|(.Ḏ.)/gi;
        while ((tmpArr = regExp1.exec(modString))!= null)
        {
            newPos = regExp1.lastIndex-1;
            if (newPos < modString.length-1 ) {
                if (checkIfEngVowel(modString[newPos], "Tamil", selSlokaTypeIndex, bUseNumbers) == true )
                {
                    //alert (String(newPos-tmpArr.length+1) + "><"+ modString[newPos-tmpArr.length+1]+"><"+newPos + "><"+tmpArr[0]+"><"+modString);
                    if (!(checkIfEngVowel(modString[newPos-tmpArr.length+1], "Tamil", selSlokaTypeIndex, bUseNumbers)==true)) { 
                        if (tmpArr[0].charAt(1) == 'ḏ') modString = modString.replace(tmpArr[0],tmpArr [0].charAt(0)+ "ḍ"+tmpArr [0].charAt(2));
                        if (tmpArr[0].charAt(1) == 'Ḏ') modString = modString.replace(tmpArr[0],tmpArr [0].charAt(0)+ "Ḍ"+tmpArr [0].charAt(2));
                    }
                }
                i = newPos+2;
                nCount++;
                if(nCount >50000) {alert ("CHECK!!! In possible infinite loop "+nCount+ " newPos=" + newPos+ " "+ modString); break;} // avoid infinite loop
            }
        }
    }
        modString= modString.replace(/au/g, "A");
        modString= modString.replace(/ai/g, "I");

    
    } else {
// English character y  followed by a space and next word starts with a vowel should be transliterated as the two words merged apporpriately:
// English character v  preceeded by a non-tamil vovel and followed by a space and next word starts with a vowel should be transliterated as the two words merged apporpriately:
    regExp1 = /(.y[\u0020-])|(.v[\u0020-])/ig;
    while ((tmpArr = regExp1.exec(modString))!= null)
    {
        newPos = regExp1.lastIndex;
        if (newPos < modString.length-1 ) {
            if (checkIfEngVowel(modString[newPos], "Tamil", selSlokaTypeIndex, bUseNumbers) == true )
            {
                //alert (String(newPos-tmpArr.length) + "><"+ modString[newPos-tmpArr.length]+"><"+newPos + ">< "+tmpArr[0]+"><"+modString);
                if (!(tmpArr[0].charAt(1) == 'v' && checkIfEngVowel(modString[newPos-tmpArr.length], "Tamil", selSlokaTypeIndex, bUseNumbers)==true)) { 
                    modString = modString.replace(tmpArr [0], tmpArr[0].charAt(0)+tmpArr[0].charAt(1)); 
                }
                else {
                }
            }
            i = newPos+2;
            nCount++;
            if(nCount >50000) {alert ("CHECK!!! In possible infinite loop "+nCount+ " newPos=" + newPos+ " "+ modString); break;} // avoid infinite loop
        }
    }
        modString= modString.replace(/au/g, "A");
        modString= modString.replace(/ai/g, "I");
    }
    return modString;
}

function checkIfEngVowel (charEng, convertToLang, selSlokaTypeIndex, bUseNumbers)
{
    var bResult = false;
    switch (charEng)
    {
        case 'a':
        case 'ā':
        case 'A':
        case 'e':
        case 'i':
        case 'ī':
        case 'I':
        case 'o':
        case 'u':
        case 'ū':
        case 'ḥ':
            bResult=true;
            break;
        case '’':
        case '\u2018':
        case '\u0027':
        case 'ḷ':
        case 'ḹ':
        case 'ṝ':
        case 'ṛ':
//        alert (charEng+convertToLang);
            if (convertToLang.toLowerCase() == "devanagari"||convertToLang.toLowerCase() == "telugu")  bResult = true;
            if (selSlokaTypeIndex == 1 && bUseNumbers) bResult = true;
            break;
        default:
        break;
    }
//alert (charEng+bResult);
    return bResult;
}

function transliterateDevanagToTamil (strInputDev, tObj)
{
    var outData = {
        outString: "",
        bAccentReplaced: false,
        bFirstCharAccented: false,
        };
    var tmpStr;
    outData= transliterateDevanagToEnglish(strInputDev, tObj);
    outData= transliterateEnglishToTamil (outData.outString, tObj);
    return outData;
}
function transliterateTamilToDevanag (strInputTam, tObj)
{
    var outData = {
        outString: "",
        bAccentReplaced: false,
        bFirstCharAccented: false,
        };
    var tmpStr;
    outData= transliterateTamilToEnglish(strInputTam, tObj);
    outData= transliterateEnglishToDevanag (outData.outString, tObj);
    return outData;
}

function getTransMap_TamToEng_BengaliVersion(withNum)
{
    var obj;
    
    var TamilToEng_singleChar_map_withNum = {
        '‘': '‘', '?':'?','—':'—','–':'–','­':'­','‑':'‑','•':'•','^':'^','©':'©','…':'…','¶':'¶','®':'®','§':'§','™':'™','~':'~','`':'`','@':'@','#':'#','$':'$','%':'%','^':'^','&':'&','*':'*','_':'_','+':'+','=':'=','{':'{','[':'[','}':'}',']':']','>':'>','<':'<',
        '\u2018': '\u2018',
        '\u2019': '\u2019', '\u2014':'\u2014',
        '“': '“','"': '"','”':'”',
        '\u2003': '\u2003', '\u00A0':'\u00A0',
        '\n': '\n',
        '\r': '\r',
        '\t': '\t',
        '(': '(', ')': ')',
        '/': '/',
        '-': '-',
        '!': '!',
        ' ': ' ', '\u2009': ' ', '\u200A': ' ',
        '.': '.',
        ',': ',',';':';',':':':',
        '।': '।',
        '॥': '॥', '0':'0', '1':'1', '2':'2', '3':'3', '4':'4', '5':'5', '6':'6', '7':'7', '8':'8', '9':'9', 
        '\u2082':'\u20882', '\u00b2':'\u00b2', 
        '\u2083':'\u2083', '\u00b3':'\u00b3', 
        '\u2084':'\u2084', '\u2074':'\u2074', 
        '|': '|',
        '‖': '‖', 
        '\u0027': '\u0027',
        '\u0B86': 'ā', '\u0B85': 'a', '\u0B87': 'i', '\u0B88': 'ī', '\u0B89': 'u', '\u0B8A': 'ū', '\u0B8E':'e', '\u0B8F':'ē', '\u0B92': 'o',  '\u0B93': 'ō',// a
        '\u0B94': 'au', '\u0B90': 'ai', // au and ai
        ':': 'ḥ', '\u0BB9': 'ha', 'H': 'ha',
        'R': 'ṙ',
        '\u0BB1': 'ṛa', '\u0BB0': 'ṛa', 'Ṝ': '\u0BB0\u0BC2\u0027', 'ṝ': '\u0BB0\u0BC2\u0027',
        '\u0B95': 'ka', 'K': 'kha', 'g': 'ga', 'G': 'gha', '\u0B99': 'ṅa', 'Ṅ': '\u0B99\u0BCD', 
        '\u0B9A': 'ca', 'C': 'cha', '\u0B9C': 'ja', 'J': 'jha', '\u0B9E': 'ña', 'Ñ': '\u0B9E\u0BCD', 
        '\u0B9F': 'ṭa', 'Ṭ': 'ṭha', 'ḍ': 'ḍa', 'Ḍ': 'ḍha', '\u0BA3': 'ṇa', 'Ṇ': '\u0BA3\u0BCD', 
        '\u0BA4': 'ta', 'T': 'tha', 'd': 'da', 'D': 'dha', '\u0BA9': 'ṉa', '\u0BA8': 'na','N': '\u0BA8\u0BCD', 
        '\u0BAA': 'pa', 'P': 'pha', 'b': 'ba', 'B': 'bha', '\u0BAE': 'ma', 'M': '\u0BAE\u0BCD', 'ṁ': '\u0BAE\u0BCD\u0027',  'Ṁ': '\u0BAE\u0BCD\u0027', 
        '\u0BAF': 'ya', 'Y': 'ya', '\u0BB0': 'ra', 'R': 'ra', '\u0BB2': 'la', '\u0BB4': 'ḻa',  '\u0BB3': 'ḷa', '\u0BB5': 'va', 'V': '\u0BB5\u0BCD', 
        '\u0BB7': 'ṣa', 'Ś': '\u0BB7\u0BCD\u0032', 'ṣ': '\u0BB7\u0BCD', '\u0BB8': 'sa',  
        'Ṣ': 'kṣ',
        'S': 'śrī',
//        '\u0BB8\u0BCD\u0BB0\u0BC0': 'Śrī',
         };
     
        obj = TamilToEng_singleChar_map_withNum;    
    return obj;
}
function getTransMap_TamToEng(withNum)
{
    var obj;

    var TamilToEng_singleChar_map_withNum = {
        '‘': '‘', '?':'?','—':'—','–':'–','­':'­','‑':'‑','•':'•','^':'^','©':'©','…':'…','¶':'¶','®':'®','§':'§','™':'™','~':'~','`':'`','@':'@','#':'#','$':'$','%':'%','^':'^','&':'&','*':'*','_':'_','+':'+','=':'=','{':'{','[':'[','}':'}',']':']','>':'>','<':'<',
        '\u2018': '\u2018',
        '\u2019': '\u2019', '\u2014':'\u2014',
        '“': '“','"': '"','”':'”',
        '\u2003': '\u2003', '\u00A0':'\u00A0',
        '\n': '\n',
        '\r': '\r',
        '\t': '\t',
        '(': '(', ')': ')',
        '/': '/',
        '-': '-',
        '!': '!',
        ' ': ' ', '\u2009': ' ', '\u200A': ' ',
        '.': '.',
        ',': ',',';':';',':':':',
        '।': '।',
        '॥': '॥', '0':'0', '1':'1', '2':'2', '3':'3', '4':'4', '5':'5', '6':'6', '7':'7', '8':'8', '9':'9', 
        '\u2082':'\u20882', '\u00b2':'\u00b2', 
        '\u2083':'\u2083', '\u00b3':'\u00b3', 
        '\u2084':'\u2084', '\u2074':'\u2074', 
        '|': '|',
        '‖': '‖', 
        '\u0027': '\u0027',
        '\u0B83': 'g',
        '\u0B86': 'ā', '\u0B85': 'a', '\u0B87': 'i', '\u0B88': 'ī', '\u0B89': 'u', '\u0B8A': 'ū', '\u0B8E':'e', '\u0B8F':'ē', '\u0B92': 'o',  '\u0B93': 'ō',// a
        '\u0B94': 'au', '\u0B90': 'ai', // au and ai
        ':': 'ḥ', '\u0BB9': 'ha', 'H': 'ha',
        '\u0BB1': 'ṛa', '\u0BB0': 'Ṛa', 'Ṝ': '\u0BB0\u0BC2\u0027', 'ṝ': '\u0BB0\u0BC2\u0027',
        '\u0B95': 'ka', 'K': 'kha', 'g': 'ga', 'G': 'gha', '\u0B99': 'ṅa', 'Ṅ': '\u0B99\u0BCD', 
        '\u0B9A': 'ca', 'C': 'cha', '\u0B9C': 'ja', 'J': 'jha', '\u0B9E': 'ña', 'Ñ': '\u0B9E\u0BCD', 
        '\u0B9F': 'ṭa', 'Ṭ': 'ṭha', 'ḍ': 'ḍa', 'Ḍ': 'ḍha', '\u0BA3': 'ṇa', 'Ṇ': '\u0BA3\u0BCD', 
        '\u0BA4': 'ta', 'T': 'tha', 'd': 'da', 'D': 'dha', '\u0BA9': 'ṉa', '\u0BA8': 'na','N': '\u0BA8\u0BCD', 
        '\u0BAA': 'pa', 'P': 'pha', 'b': 'ba', 'B': 'bha', '\u0BAE': 'ma', 'M': '\u0BAE\u0BCD', 'ṁ': '\u0BAE\u0BCD\u0027',  'Ṁ': '\u0BAE\u0BCD\u0027', 
        '\u0BAF': 'ya', 'Y': 'ya', '\u0BB0': 'ra', 'R': 'ra', '\u0BB2': 'la', '\u0BB4': 'ḻa',  '\u0BB3': 'ḷa', '\u0BB5': 'va', 'V': '\u0BB5\u0BCD', 
        '\u0BB7': 'ṣa', 'Ś': '\u0BB7\u0BCD\u0032', 'ṣ': '\u0BB7\u0BCD', '\u0BB8': 'sa',  
        'Ṣ': 'kṣ',
        'S': 'śrī',
//        '\u0BB8\u0BCD\u0BB0\u0BC0': 'Śrī',
         };
     
        obj = TamilToEng_singleChar_map_withNum;    
    return obj;
}

function transliterateTamilToEnglish (strInputTam, tObj)
{
    var bUseNumbers = tObj.bUseNumbers;
    var wordSeparator = tObj.wordSeparator;
    var bSmartTranslit = tObj.bSmartTranslit_Prompt;
    var outData = {
        outString: "",
        bAccentReplaced: false,
        bFirstCharAccented: false,
        };
    var mapTamil_char = (function () {

        var accent_map_to_use;

        accent_map_to_use= getTransMappedObject("Tamil", "English", bUseNumbers, tObj.selSlokaTypeIndex);

        return function mapTamil_char(sOrj) {
        var s = sOrj, i,j, wordArray, prevChar, curChar, curWord, nextChar;
        if (!s) { return ''; }            
            //s= s.replace(/\u0B94/gi, "A");
            //s= s.replace(/\u0B90/gi, "I");
            s= s.replace(/w/gi, "v");            
            s=s.replace(/(.)(\u0BC6)(\u0BBE)/gi, '$1\u0BCA'); //some use old typewriters in which ko, kO, and kAU are typed as two characters
            s=s.replace(/(.)(\u0BC7)(\u0BBE)/gi, '$1\u0BCB');
//            s=s.replace(/(.)(\u0BC6)(\u0BB3)/gi, '$1\u0BCC');
            //s= s.replace(/\u0BAA\u0BCD\u0032/gi, "P");
            //s= s.replace(/\u0B9A\u0BCD\u0032/gi, "C");
            //s= s.replace(/\u0B95\u0BCD\u0032/gi, "K");
            //s= s.replace(/\u0B95\u0BCD\u0034/gi, "G");
            //s= s.replace(/\u0BA4\u0BCD\u0032/gi, "T");
            //s= s.replace(/\u0BA4\u0BCD\u0034/gi, "D");
            //s= s.replace(/\u0BAA\u0BCD\u0034/gi, "B");            
            //s= s.replace(/\u0B9F\u0BCD\u0032/gi, "Ṭ");
            //s= s.replace(/\u0B9F\u0BCD\u0034/gi, "Ḍ");
            if (tObj.selSlokaTypeIndex == 1)//bengali verse
                s= s.replace(/\u0B83\u0B9F/gi, "R");
            else if (tObj.selSlokaTypeIndex == 0) //sanskrit verse
                s= s.replace(/\u0B83/gi, "");

            s= s.replace(/\u0BB8\u0BCD\u0BB0\u0BC0/gi, "S");
            //convert all varieties of quotes to \u0027
            s= s.replace(/\u2018/gi,'\u0027');
            s= s.replace(/\u2019/gi,'\u0027');

        var ret = '', tmpChar , tmpMsg = 0, curTransWord = '';
        if (bUseNumbers==false) {
            s= s.replace(/[\u0032\u0033\u0034\u0027\u2018\u2019\u2082\u2083\u2084\u00b2\u00b3\u2074]/gi, "");
        } else {
            // change these subscripted or superscripte numbers to real numbers
            s=s.replace(/[\u2082\u00b2]/gi, "\u0032"); 
            s=s.replace(/[\u2083\u00b3]/gi, "\u0033");
            s=s.replace(/[\u2084\u2074]/gi, "\u0034");
            }
        wordArray = s.split (" ");
        //alert(wordArray);
        for (i=0; i< wordArray.length; i++) {
            curWord = wordArray[i];
            prevChar = '';
            nextChar = '';
            curTransWord = '';
            //alert(curWord);
            for (j = 0; j < curWord.length; j++) {
                curChar = curWord[j];
                if (j+1< curWord.length) nextChar = curWord[j+1]; else nextChar = '';
            //alert(curChar+" "+nextChar);
                //if (nextChar == '\u0027'|| nextChar == '’') {alert(curChar+" "+String(nextChar).charCodeAt(0));alert (prevChar+curChar+nextChar);alert(curWord);}
                //if (nextChar == '\u0027') {nextChar = '\u0034';}
                if (checkIfTamVowel(curChar)) {
                    if (prevChar != '') {
                        tmpChar = accent_map_to_use[prevChar];
                        if (tmpChar != null && tmpChar != '' && tmpChar != prevChar) 
                        curChar = convertToEngConsonant (prevChar, curChar, nextChar, tmpChar);
                        else curChar = prevChar + accent_map_to_use[curChar] ;
                        curTransWord += curChar;
                    } else curTransWord += accent_map_to_use[curChar] ;
                    prevChar = '';
                } else {
                    if (prevChar != '') {
//                        if (curChar >= '\u0032' && curChar <= '\u0034') 
                        tmpChar = accent_map_to_use[prevChar] ;
                        tmpChar = validateNumberedTamilConsonant (prevChar, curChar, tmpChar);
                        curTransWord += tmpChar;
                        prevChar = '';
                    } 
                    if (j== curWord.length-1) if (!(curChar >= '\u0032' && curChar <= '\u0034')&&curChar != '\u0027') {
                        //alert (prevChar+","+curChar);
                        curTransWord += accent_map_to_use[curChar] };
                    if ((curChar >= '\u0032' && curChar <= '\u0034')
                    || (j!=0&&curChar == '\u0027')
                    ) prevChar = ''; else prevChar = curChar;
                }
            
            }
            if (bSmartTranslit == true)
            {
                var tmpStr = curTransWord;
                tmpStr = checkTamilAdvRules (curWord, curTransWord);
                if (tmpStr == null) //do not check any further
                {
                    bSmartTranslit = false; // User has asked to  cancel further checking/prompting
                    tmpStr = curTransWord; //re- assign
                } else curTransWord = tmpStr;
            }
            ret+= curTransWord + wordSeparator;
        }
    
        if (tObj.selSlokaTypeIndex == 0) // this is sanskrit verse so replace 
        {
               ret = ret.replace(/[\u0113\u0112]/gi, 'e');
               ret = ret.replace(/[\u014C\u014D]/gi, 'o');
               ret = ret.replace(/ṉ/gi, 'n'); 
               
        }else if (tObj.selSlokaTypeIndex == 2) // this is tamil poem  so replace 
        {
            ret = ret.replace(/\u1E5b\u1E5b/gi, '\u1E6D\u1E5B');
        } else if (tObj.selSlokaTypeIndex == 1) // this is Bengali verse so replace 
        {
               ret = ret.replace(/ṉ/gi, 'n'); 
        }
        return ret;
        };
    } ()); 

    outData.outString = mapTamil_char(strInputTam);
    //outString = outString.replace(/^[\s\uFEFF\xA0]+|[\s\uFEFF\xA0]+$/g, '');
   //outData.outString = outData.outString.replace(/^[\s\uFEFF\xA0]+/, ''); 
 return outData;
 }
function checkDiacritics (inputString, langType)
{
    var i, j, modString="", tmpWord, tmpStr=null, wordArray, modTranslitWord, wordArrayLang2, tmpWord2;
    var transliterateObj, outTransStrEng, searchPos = -1, matchArray;
    var phoneticEquivalent_TamilToEnglish = {
                // english to english mapping
                'k': 'g', 'c': 's', 't': 'd', 'ṭ': 'ḍ', 'p': 'b', 'ś': 'ṣ', 'l': 'l', 'ḷ': 'ḷ', 'ḻ': 'ḻ', 
                //tamil to english mapping
                '\u0B95': 'g', '\u0B9A': 's', '\u0BA4': 'd', '\u0B9F': 'ḍ', '\u0BAA': 'b', '\u0BB7': 'ṣ',
    };
    wordArray = inputString.split (/[\s]/gi);
    if (langType == 1)
    {
            transliterateObj = getTransliterationObject ();
            transliterateObj.selFunctionPtr = transliterateObj.funcPtr[transliterateObj.selTransFunction];
            //transliterateObj.bSmartTranslit_Prompt = true;
            //transliterateObj.selTransFunction_Text = obj.outLangList_name;
            outTransStrEng  = transliterateTool (inputString, transliterateObj);
            wordArrayLang2 = outTransStrEng.split(/[\s]/gi);
        alert (wordArrayLang2);
    }

    for (i=0; i< wordArray.length; i++) {
        tmpWord = wordArray[i];
        //alert(tmpWord);
        if (langType == 0) // english to english
        {        
            modTranslitWord = tmpWord;
            modTranslitWord = modTranslitWord.replace(/ṇṭ/gi, "ṇḍ");
            modTranslitWord = modTranslitWord.replace(/ṇd/gi, "ṇḍ");
            modTranslitWord = modTranslitWord.replace(/ṇt/gi, "ṇḍ");
            modTranslitWord = modTranslitWord.replace(/nṭ/gi, "ṇṭ");
            modTranslitWord = modTranslitWord.replace(/nt/gi, "nd");
            modTranslitWord = modTranslitWord.replace(/tt/gi, "ṭṭ");
            matchArray = modTranslitWord.match (/[kctṭplḷśṣ]/gi);
            if (matchArray != null)
            for (j = 0; j< matchArray.length; j++)
            {
                searchPos = modTranslitWord.lastIndexOf(matchArray[j]);
                if (searchPos > 0)                
                {
                    if (modTranslitWord[searchPos] != modTranslitWord[searchPos-1])
                    {
                        modTranslitWord = modTranslitWord.replace(modTranslitWord[searchPos], phoneticEquivalent_TamilToEnglish[modTranslitWord[searchPos]]);

                    }
               }
            }
            tmpStr = prompt ("Confirm Transliteration for: "+tmpWord, modTranslitWord, "Confirm");

        } else if (langType == 1) // tamil to English
        {            
            tmpWord2 = wordArrayLang2[i];
            //alert (tmpWord+"_"+tmpWord2+i);
            tmpStr = checkTamilAdvRules (tmpWord, tmpWord2);        
        }
        if (tmpStr == null) //do not check any further
        {
            // User has asked to  cancel further checking/prompting
            modTranslitWord = tmpWord;
            break;
        } else modTranslitWord = tmpStr;
        modString += modTranslitWord +" ";
    }
    return modString;
}
function checkTamilAdvRules (curTamilWord, curEngTranslitWord)
{
    var modEngTranslitWord = curEngTranslitWord, tmpStr=null, searchPos = -1, matchArray;
     var phoneticEquivalent_TamilToEnglish = {
                // english to english mapping
                'k': 'g', 'c': 's', 't': 'd', 'ṭ': 'ḍ', 'p': 'b', 'ś': 'ṣ',
                //tamil to english mapping
                '\u0B95': 'g', '\u0B9A': 's', '\u0BA4': 'd', '\u0B9F': 'ḍ', '\u0BAA': 'b', '\u0BB7': 'ṣ',
    };
    matchArray = curTamilWord.match (/[\u0B95\u0B9A\u0B9F\u0BA4\u0BAA\u0BB7]/gi);
    //alert (curTamilWord+"__"+matchArray);
    if (matchArray != null)
    for (j = 0; j< matchArray.length; j++)
    {
        searchPos = curTamilWord.lastIndexOf(matchArray[j]);
        if (searchPos > 0)                                
        {
            if (curTamilWord[searchPos] != curTamilWord[searchPos-2])
            {
                //alert (curTamilWord[searchPos]+"#"+modEngTranslitWord[searchPos]);
                //alert (phoneticEquivalent_TamilToEnglish[modEngTranslitWord[searchPos]]);
                modEngTranslitWord = modEngTranslitWord.replace(modEngTranslitWord[searchPos], phoneticEquivalent_TamilToEnglish[modEngTranslitWord[searchPos]]);
            }
        }
    }
            modEngTranslitWord = modEngTranslitWord.replace(/ṇṭ/gi, "ṇḍ");
            modEngTranslitWord = modEngTranslitWord.replace(/nt/gi, "nd");        
            modEngTranslitWord = prompt ("Confirm Transliteration for: "+curTamilWord, modEngTranslitWord, "Confirm");    
    return modEngTranslitWord;
}
function validateNumberedTamilConsonant (tamilChar, numberSubscript, tmpCharEng)
{
    var modifiedEng = tmpCharEng, sub = numberSubscript, tmpArr;

    if (tamilChar != '') if ((numberSubscript >= '\u0032' && numberSubscript <= '\u0034') || numberSubscript == '\u0027') 
    {
        if (numberSubscript == '\u0027') sub = 5; else sub = numberSubscript - '\u0030';
        if (modifiedEng == null) {
            alert ("input str== null!!! "+ tamilChar + numberSubscript);
             return "error!!!";}
        tmpArr = modifiedEng.split("");
        
        if (sub%2 == 0) if (tamilChar !='\u0BB7') {
            modifiedEng = modifiedEng.replace("a", "ha");
            } else {
                //'ṣa'
                tmpArr[0] = 'ś';
                modifiedEng = tmpArr.join('');
                }
        //alert (sub+numberSubscript);
        tmpArr = modifiedEng.split("");

        if (sub%3==0 || sub%4 == 0 || sub%5 == 0) {
            switch (tamilChar)
            {
/*
        '\u0BB1': 'ṛa', '\u0BB0': 'Ṛa', 'Ṝ': '\u0BB0\u0BC2', 'ṝ': '\u0BB0\u0BC2',
        '\u0B95': 'ka', 'K': 'kha', 'g': 'ga', 'G': 'gha', '\u0B99': 'ṅa', 'Ṅ': '\u0B99\u0BCD', 
        '\u0B9A': 'ca', 'C': 'cha', '\u0B9C': 'ja', 'J': 'jha', '\u0B9E': 'jña', 'Ñ': '\u0B9E\u0BCD', 
        '\u0B9F': 'ṭa', 'Ṭ': 'ṭha', 'ḍ': 'ḍa', 'Ḍ': 'ḍha', '\u0BA3': 'ṇa', 'Ṇ': '\u0BA3\u0BCD', 
        '\u0BA4': 'ta', 'T': 'tha', 'd': 'da', 'D': 'dha', '\u0BA9': 'na', 'N': '\u0BA8\u0BCD', 
        '\u0BAA': 'pa', 'P': 'pha', 'b': 'ba', 'B': 'bha', '\u0BAE': 'ma', 'M': '\u0BAE\u0BCD', 'ṁ': '\u0BAE\u0BCD',  'Ṁ': '\u0BAE\u0BCD', 
        '\u0BAF': 'ya', 'Y': 'ya', '\u0BB0': 'ra', 'R': 'ra', '\u0BB2': 'la', '\u0BB4': 'ḻa',  '\u0BB3': 'ḷa', '\u0BB5': 'va', 'V': '\u0BB5\u0BCD', 
        '\u0BB7': 'śa', 'Ś': '\u0BB7\u0BCD', 'ṣ': '\u0BB7\u0BCD\u0032', '\u0BB7': 'kṣa', '\u0BB8': 'sa',  
*/
            case '\u0B95': //ka 
            {
            tmpArr[0] = 'g';
            modifiedEng = tmpArr.join('');
            }
            break;
            case '\u0B9A': //'ca'
            {
            tmpArr[0] = 'j';
            modifiedEng = tmpArr.join('');
            }
            break;
            case '\u0B9F': //'ṭa':
            {
            tmpArr[0] = 'ḍ';
            modifiedEng = tmpArr.join('');
            }
            break;
            case '\u0BA4': //'ta'
            {
            tmpArr[0] = 'd';
            modifiedEng = tmpArr.join('');
            }
            break;
            case '\u0BAA': //'pa'
            {
            tmpArr[0] = 'b';
            modifiedEng = tmpArr.join('');
            }
            break;
            case '\u0BB0': //'ra'
            {
                //alert (tamilChar+sub);
            if (numberSubscript != '\u0027') {tmpArr[0] = 'ṛ';}else{ tmpArr[1]=''; tmpArr[0] = 'ṛ';}
            modifiedEng = tmpArr.join('');
            }
            break;
            case '\u0BAE': //'ma'
            {
                //alert (tamilChar+sub);
            tmpArr[0] = 'ṁ';
            modifiedEng = tmpArr.join('');
            }
            break;
/*            
            case '\u0BA9': //'na'
            break;
            case '\u0BA3': //'ṇa'
            break;
            case '\u0B9E': //'jña'
            break;
*/                     
            default:
            break;
            }
        }
    }
    return modifiedEng; 
   
}
function verifyTamilConsonant (prevCharTam, curCharTam, nextCharTam, tmpCharEng)
{
    var modifiedEngChar = tmpCharEng;
    if (nextCharTam != '' && nextCharTam >= '\u0032' && nextCharTam <= '\u0034' || nextCharTam == '\u0027')
    {
        modifiedEngChar = validateNumberedTamilConsonant (prevCharTam, nextCharTam, tmpCharEng);
    }
    return modifiedEngChar; 
}




function convertToEngConsonant (prevCharTam, curCharTam, nextCharTam, tmpCharEng)
{
    var newChar = "$ˆ$";   
    if (tmpCharEng ==null|| curCharTam==null) {alert (curCharTam+tmpCharEng); return newChar;}
    tmpCharEng = verifyTamilConsonant (prevCharTam, curCharTam, nextCharTam, tmpCharEng);
    //alert (curCharTam+tmpCharEng);
    switch (curCharTam)
    {
        case '\u0BCD':
            newChar = tmpCharEng.replace('a', '');
            break;
        case '\u0BBE':
            newChar = tmpCharEng.replace('a', 'ā');
            break;
        case '\u0BCC':
            newChar = tmpCharEng.replace('a', 'au');
            break;
        case '\u0BC6':
            newChar = tmpCharEng.replace('a', 'e');
            break;
        case '\u0BC7':
            newChar = tmpCharEng.replace('a', 'ē');
            break;
        case '\u0BBF':
            newChar = tmpCharEng.replace('a', 'i');
            break;
        case '\u0BC0':
            newChar = tmpCharEng.replace('a', 'ī');
            break;
        case '\u0BC8':
            newChar = tmpCharEng.replace('a', 'ai');
            break;
        case '\u0BCA':
            newChar = tmpCharEng.replace('a', 'o');
            break;
        case '\u0BCB':
            newChar = tmpCharEng.replace('a', 'ō');
            break;
        case '\u0BC1':
            newChar = tmpCharEng.replace('a', 'u');
            break;
        case '\u0BC2':
            newChar = tmpCharEng.replace('a', 'ū');
            break;
        default:
         alert (curCharTam+tmpCharEng);
       
        break;
    }
//   alert (tmpChar + ": vowel - " + curChar + ": newChar - " + newChar);
   return newChar;
}

function checkIfTamVowel (charTam)
{
    var bResult = false;
    switch (charTam)
    {
        case '\u0BCA':
        case '\u0BCB':
        case '\u0BCC':
        case '\u0BCD':
        case '\u0BC0':
        case '\u0BC1':
        case '\u0BC2':
        case '\u0BC6':
        case '\u0BC7':
        case '\u0BC8':
        case '\u0BBE':
        case '\u0BBF':
            bResult = true;
            break;
        default:
        break;
    }
//alert (CharTam+bResult);
    return bResult;
}
// Bengali Verse type functions

function bv_transliterateEnglishToTamil (strInputTam, tObj)
{
    alert ("bv_transliterateEnglishToTamil");
    return transliterateEnglishToTamil (strInputEng, tObj);
}
function bv_transliterateTamilToEnglish (strInputTam, tObj)
{
    alert ("bv_transliterateTamilToEnglish");
}
function transliterateEnglishToBengali (strInputTam, tObj)
{
    alert ("transliterate EnglishToBengali - Not implemented yet!");
}
function transliterateBengaliToEnglish (strInputTam, tObj)
{
    alert ("transliterate BengaliToEnglish  - Not implemented yet!");
}
function  transliterateTamilToBengali (strInputTam, tObj)
{
    alert ("transliterate TamilToBengali - Not implemented yet!");
}
function transliterateBengaliToTamil (strInputTam, tObj)
{
    alert ("transliterate BengaliToTamil - Not implemented yet!");
}

function convertUnicodeToNonUnicode (unicodeFont, text)
{

    if (unicodeFont == 1)
    {
        return convertToBalaram (text);
    }
    
    if (unicodeFont == 2)
    {
        alert ("Not yet Implemented!");
        return convertShree_TamEX_0803Text (text);
    }
    if (unicodeFont == 3)
    {
        alert ("Not yet Implemented!");
        return convertAdhawinTamilText (text);
    }
    if (unicodeFont == 4)
    {
        return convertTo_IndowordTamilText (text);
    }
    if (unicodeFont == 5)
    {
        alert ("Not yet Implemented!");
        return convertIDSTamilText (text);
    }
    return text;
}
function myStringReplace_arg1_with_arg2 (inText, argStr1, argStr2)
{
    argStr1.replace(/[\u002Fgi]/gi, "");
    
    return inText.replace (argStr1, argStr2);
}
function myStringReplace_arg2_with_arg1 (inText, argStr1, argStr2)
{    
    return inText.replace (argStr2, argStr1);
}
function myStringReplace (inText, findWhat, replaceWith, bReverseOrder)
{ 
    var argFindRegEx, findStr, replaceStr;
    
    if (bReverseOrder==false) {
        findStr = findWhat; 
        replaceStr = replaceWith;
        } else {
            findStr = replaceWith; 
            replaceStr = findWhat;
            }
    argFindRegEx = new RegExp (findStr, "g");
    inText = inText.replace (argFindRegEx, replaceStr);
    return inText;
}
function handleBalaramFontConvertion (text, bConvertToUnicode)
{

    var bReverseOrder = !bConvertToUnicode;
      text=myStringReplace (text, "", "fi", bReverseOrder); 
      text=myStringReplace (text, "", "fl", bReverseOrder);
      text=myStringReplace (text, "ä", "ā", bReverseOrder);
      text=myStringReplace (text, "é", "ī", bReverseOrder);
      text=myStringReplace (text, "ü", "ū", bReverseOrder);
      text=myStringReplace (text, "å", "ṛ", bReverseOrder);
      text=myStringReplace (text, "è", "ṝ", bReverseOrder);
      text=myStringReplace (text, "ì", "ṅ", bReverseOrder);
      text=myStringReplace (text, "ñ", "ṣ", bReverseOrder);
      text=myStringReplace (text, "ï", "ñ", bReverseOrder);
      text=myStringReplace (text, "ö", "ṭ", bReverseOrder);
      text=myStringReplace (text, "ò", "ḍ", bReverseOrder);
      text=myStringReplace (text, "ë", "ṇ", bReverseOrder);
      text=myStringReplace (text, "ç", "ś", bReverseOrder);
      text=myStringReplace (text, "à", "ṁ", bReverseOrder);
      text=myStringReplace (text, "ù", "ḥ", bReverseOrder);
      text=myStringReplace (text, "ÿ", "ḷ", bReverseOrder);
      text=myStringReplace (text, "û", "ḹ", bReverseOrder);
      text=myStringReplace (text, "Ä", "Ā", bReverseOrder);
      text=myStringReplace (text, "É", "Ī", bReverseOrder);
      text=myStringReplace (text, "Ü", "Ū", bReverseOrder);
      text=myStringReplace (text, "Å", "Ṛ", bReverseOrder);
      text=myStringReplace (text, "È", "Ṝ", bReverseOrder);
      text=myStringReplace (text, "Ì", "Ṅ", bReverseOrder);
      text=myStringReplace (text, "Ñ", "Ṣ", bReverseOrder);
      text=myStringReplace (text, "Ï", "Ñ", bReverseOrder);
      text=myStringReplace (text, "Ö", "Ṭ", bReverseOrder);
      text=myStringReplace (text, "Ò", "Ḍ", bReverseOrder);
      text=myStringReplace (text, "Ë", "Ṇ", bReverseOrder);
      text=myStringReplace (text, "Ç", "Ś", bReverseOrder);
      text=myStringReplace (text, "À", "Ṁ", bReverseOrder);
      text=myStringReplace (text, "Ù", "Ḥ", bReverseOrder);
      text=myStringReplace (text, "ß", "Ḷ", bReverseOrder);
/*      text=myStringReplace (text, "“", "“", bReverseOrder);
      text=myStringReplace (text, "”", "”", bReverseOrder);
      text=myStringReplace (text, " ", " ", bReverseOrder);
      text=myStringReplace (text, "'", "‘", bReverseOrder);
      text=myStringReplace (text, "-", "-", bReverseOrder);
      text=myStringReplace (text, "'", "’", bReverseOrder);
      text=myStringReplace (text, "—", "—", bReverseOrder);
      text=myStringReplace (text, "»", "»", bReverseOrder);
      text=myStringReplace (text, "…", "…", bReverseOrder);
      */
    return text;
    
}
function convertToBalaram (text)
{
    text = handleBalaramFontConvertion (text, false); // bConvertToUnicode is false means, convertFromUnicode
    return text;
};

function convertSanskritTimesText(text, bReverseOrder) {
    
      text=myStringReplace (text, '\u20AC', "ā", bReverseOrder);
      text=myStringReplace (text, '\u0161', "Ā", bReverseOrder);
      text=myStringReplace (text, '\u2026', "ī", bReverseOrder);
      text=myStringReplace (text, '\u0178', "Ī", bReverseOrder);
      text=myStringReplace (text, '\u2122', "ū", bReverseOrder);
      text=myStringReplace (text, '\u00B6', "Ū", bReverseOrder);
      
      text=myStringReplace (text, '\u008D', "ṛ", bReverseOrder);
      text=myStringReplace (text, '\u008E', "ṝ", bReverseOrder);
      text=myStringReplace (text, '\u00AC', "Ṛ", bReverseOrder);
      text=myStringReplace (text, '\u00AD', "Ṝ", bReverseOrder);
      
      text=myStringReplace (text, '\u2030', "ṅ", bReverseOrder);
      text=myStringReplace (text, '\u00A5', "Ṅ", bReverseOrder);
      text=myStringReplace (text, '\u00F1', "ñ", bReverseOrder);
      text=myStringReplace (text, '\u00D1', "Ñ", bReverseOrder);
      text=myStringReplace (text, '\u0160', "ṇ", bReverseOrder);
      text=myStringReplace (text, '\u00A6', "Ṇ", bReverseOrder);
      
      text=myStringReplace (text, '\u0090', "ṣ", bReverseOrder);
      text=myStringReplace (text, '\u00B1', "Ṣ", bReverseOrder);
      text=myStringReplace (text, '\u008F', "ś", bReverseOrder);
      text=myStringReplace (text, '\u00AE', "Ś", bReverseOrder);
      
      text=myStringReplace (text, '\u02DC', "ṭ", bReverseOrder);
      text=myStringReplace (text, '\u00B5', "Ṭ", bReverseOrder);
      text=myStringReplace (text, '\u0081', "ḍ", bReverseOrder);
      text=myStringReplace (text, '\u009D', "Ḍ", bReverseOrder);
      
      text=myStringReplace (text, 'u02C6', "ṁ", bReverseOrder);
      text=myStringReplace (text, '\u00A4', "Ṁ", bReverseOrder);
      text=myStringReplace (text, '\u0192', "ḥ", bReverseOrder);
      text=myStringReplace (text, '\u017E', "Ḥ", bReverseOrder);
      text=myStringReplace (text, '\u2020', "ḷ", bReverseOrder);
      text=myStringReplace (text, '\u00A2', "Ḷ", bReverseOrder);
      text=myStringReplace (text, '\u2021', "ḹ", bReverseOrder);
    return text;    
}

function convertTo_IndowordTamilText(inText) {
	var text = inText;

		text = myStringReplace_arg2_with_arg1 (text, '\u0024', 'ஸ்ரீ');
text = myStringReplace_arg2_with_arg1 (text, '\u007E', '\u0B83');
text = myStringReplace_arg2_with_arg1 (text, '\u006D', '\u0B85');
text = myStringReplace_arg2_with_arg1 (text, '\u004D', '\u0B86');
text = myStringReplace_arg2_with_arg1 (text, '\u00EF', '\u0B87');
text = myStringReplace_arg2_with_arg1 (text, '\u003C', '\u0B88');
text = myStringReplace_arg2_with_arg1 (text, '\u0063', '\u0B89');
text = myStringReplace_arg2_with_arg1 (text, '\u0043', '\u0B8A');
text = myStringReplace_arg2_with_arg1 (text, '\u0076', '\u0B8E');
text = myStringReplace_arg2_with_arg1 (text, '\u0056', '\u0B8F');
text = myStringReplace_arg2_with_arg1 (text, '\u0049', '\u0B90');
text = myStringReplace_arg2_with_arg1 (text, '\u0078', '\u0B92');
text = myStringReplace_arg2_with_arg1 (text, '\u0058', '\u0B93');
text = myStringReplace_arg2_with_arg1 (text, '\u0078\u0073', '\u0B94');

text = myStringReplace_arg2_with_arg1 (text, '\u0066', '\u0B95');
text = myStringReplace_arg2_with_arg1 (text, '\u2021', '\u0B99');
text = myStringReplace_arg2_with_arg1 (text, '\u0072', '\u0B9A');
text = myStringReplace_arg2_with_arg1 (text, '\u0050', '\u0B9E');
text = myStringReplace_arg2_with_arg1 (text, '\u006C', '\u0B9F');
text = myStringReplace_arg2_with_arg1 (text, '\u007A', '\u0BA3');
text = myStringReplace_arg2_with_arg1 (text, '\u006A', '\u0BA4');
text = myStringReplace_arg2_with_arg1 (text, '\u0065', '\u0BA8');
text = myStringReplace_arg2_with_arg1 (text, '\u0064', '\u0BA9');
text = myStringReplace_arg2_with_arg1 (text, '\u0067', '\u0BAA');
text = myStringReplace_arg2_with_arg1 (text, '\u006B', '\u0BAE');
text = myStringReplace_arg2_with_arg1 (text, '\u0061', '\u0BAF');
text = myStringReplace_arg2_with_arg1 (text, '\u0075', '\u0BB0');
text = myStringReplace_arg2_with_arg1 (text, '\u0077', '\u0BB1');
text = myStringReplace_arg2_with_arg1 (text, '\u0079', '\u0BB2');
text = myStringReplace_arg2_with_arg1 (text, '\u0074', '\u0BB5');
text = myStringReplace_arg2_with_arg1 (text, '\u0048', '\u0BB4');
text = myStringReplace_arg2_with_arg1 (text, '\u0073', '\u0BB3');
text = myStringReplace_arg2_with_arg1 (text, '\u00F5', '\u0BB7');
text = myStringReplace_arg2_with_arg1 (text, '\u005B', '\u0BB8');
text = myStringReplace_arg2_with_arg1 (text, '\u0041', '\u0BB9');
text = myStringReplace_arg2_with_arg1 (text, '\u0023', '\u0B9C');
text = myStringReplace_arg2_with_arg1 (text, '\u0042', '\u0B95\u0BCD\u0BB7');

text = myStringReplace_arg2_with_arg1 (text, '(.)(\u0068)', '$1\u0BBE');
text = myStringReplace_arg2_with_arg1 (text, '\u201A', '\u0BA3\u0BBE');
text = myStringReplace_arg2_with_arg1 (text, '\u201E', '\u0BA9\u0BBE');
text = myStringReplace_arg2_with_arg1 (text, '\u0192', '\u0BB1\u0BBE');
text = myStringReplace_arg2_with_arg1 (text, '(\u0062)(.)', '$2\u0BC6');
text = myStringReplace_arg2_with_arg1 (text, '(\u006E)(.)', '$2\u0BC7');

text = myStringReplace_arg2_with_arg1 (text, '(\u0062)(.)(\u0068)', '$2\u0BCA');
text = myStringReplace_arg2_with_arg1 (text, '(\u0067)(.)(\u0068)', '$2\u0BCB');
text = myStringReplace_arg2_with_arg1 (text, '(\u0069)(.)', '$2\u0BC8');

text = myStringReplace_arg2_with_arg1 (text, '(\u0062)(.)(\u0073)', '$2\u0BCC');

text = myStringReplace_arg2_with_arg1 (text, '\u00A1', '\u0B95\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u00A7', '\u0B99\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u00A2', '\u0B9A\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u0160', '\u0B9E\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u00A3', '\u0B9F\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u00A9', '\u0BA3\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u00A4', '\u0BA4\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u00AA', '\u0BA8\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u2039', '\u0BA9\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u00A5', '\u0BAA\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u00AB', '\u0BAE\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u0152', '\u0BAF\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u00AE', '\u0BB0\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u2030', '\u0BB1\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u0161', '\u0BB2\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u203A', '\u0BB5\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u0153', '\u0BB4\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u0178', '\u0BB3\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u005A', '\u0BB7\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u00B0', '\u0BB8\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u00DE', '\u0BB8\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u00E0', '\u0BB9\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u007B', '\u0B9C\u0BCD');
text = myStringReplace_arg2_with_arg1 (text, '\u00BA', '\u0B95\u0BCD\u0BB7\u0BCD');




text = myStringReplace_arg2_with_arg1 (text, '(.)(\u0026)', '$1\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '(.)(\u005D)', '$1\u0BC0');

text = myStringReplace_arg2_with_arg1 (text, '\u00BB', '\u0B95\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00A7', '\u0B99\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00E1', '\u0B9A\u0BBF');
//text = myStringReplace_arg2_with_arg1 (text, '\u0160', '\u0B9E\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u006F', '\u0B9F\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00C2', '\u0BA3\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00E2', '\u0BA4\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00C3', '\u0BA8\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00C5', '\u0BA9\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00E3', '\u0BAA\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00C4', '\u0BAE\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00C6', '\u0BAF\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00C7', '\u0BB0\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00BF', '\u0BB1\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00C8', '\u0BB2\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00C9', '\u0BB5\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00CA', '\u0BB4\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00CB', '\u0BB3\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00CE', '\u0BB7\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00CC', '\u0BB8\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00CF', '\u0BB9\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00CD', '\u0B9C\u0BBF');
text = myStringReplace_arg2_with_arg1 (text, '\u00F8', '\u0B95\u0BCD\u0BB7\u0BBF');

text = myStringReplace_arg2_with_arg1 (text, '\u00D1', '\u0B95\u0BC0');
//text = myStringReplace_arg2_with_arg1 (text, '\u00A7', '\u0B99\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u00D3', '\u0B9A\u0BC0');
//text = myStringReplace_arg2_with_arg1 (text, '\u0160', '\u0B9E\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u004F', '\u0B9F\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u00D9', '\u0BA3\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u00D4', '\u0BA4\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u00DA', '\u0BA8\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u00DC', '\u0BA9\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u00D5', '\u0BAA\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u00DB', '\u0BAE\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u0070', '\u0BAF\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u00DF', '\u0BB0\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u00D6', '\u0BB1\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u00E4', '\u0BB2\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u00E5', '\u0BB5\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u00E6', '\u0BB4\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u00E7', '\u0BB3\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u00EA', '\u0BB7\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u00E8', '\u0BB8\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u00EB', '\u0BB9\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u00E9', '\u0B9C\u0BC0');
text = myStringReplace_arg2_with_arg1 (text, '\u00EC', '\u0B95\u0BCD\u0BB7\u0BC0');

text = myStringReplace_arg2_with_arg1 (text, '\u0046', '\u0B95\u0BC1');
//text = myStringReplace_arg2_with_arg1 (text, '\u00A7', '\u0B99\u0BC1');
text = myStringReplace_arg2_with_arg1 (text, '\u0052', '\u0B9A\u0BC1');
//text = myStringReplace_arg2_with_arg1 (text, '\u0160', '\u0B9E\u0BC1');
text = myStringReplace_arg2_with_arg1 (text, '\u004C', '\u0B9F\u0BC1');
text = myStringReplace_arg2_with_arg1 (text, '\u0051', '\u0BA3\u0BC1');
text = myStringReplace_arg2_with_arg1 (text, '\u004A', '\u0BA4\u0BC1');
text = myStringReplace_arg2_with_arg1 (text, '\u0045', '\u0BA8\u0BC1');
text = myStringReplace_arg2_with_arg1 (text, '\u0044', '\u0BA9\u0BC1');
text = myStringReplace_arg2_with_arg1 (text, '\u00F2', '\u0BAA\u0BC1');
text = myStringReplace_arg2_with_arg1 (text, '\u004B', '\u0BAE\u0BC1');
text = myStringReplace_arg2_with_arg1 (text, '\u00ED', '\u0BAF\u0BC1');
text = myStringReplace_arg2_with_arg1 (text, '\u0055', '\u0BB0\u0BC1');
text = myStringReplace_arg2_with_arg1 (text, '\u0057', '\u0BB1\u0BC1');
text = myStringReplace_arg2_with_arg1 (text, '\u0059', '\u0BB2\u0BC1');
text = myStringReplace_arg2_with_arg1 (text, '\u00EE', '\u0BB5\u0BC1');
text = myStringReplace_arg2_with_arg1 (text, '\u0047', '\u0BB4\u0BC1');
text = myStringReplace_arg2_with_arg1 (text, '\u0053', '\u0BB3\u0BC1');
text = myStringReplace_arg2_with_arg1 (text, '\u00CE', '\u0BB7\u0BC1');
text = myStringReplace_arg2_with_arg1 (text, '\u00CC', '\u0BB8\u0BC1');
text = myStringReplace_arg2_with_arg1 (text, '\u0044', '\u0BB9\u0BC1');
//text = myStringReplace_arg2_with_arg1 (text, '\u00CD', '\u0B9C\u0BC1');
//text = myStringReplace_arg2_with_arg1 (text, '\u00F8', '\u0B95\u0BCD\u0BB7\u0BC1');

text = myStringReplace_arg2_with_arg1 (text, '\u0054', '\u0B95\u0BC2');
//text = myStringReplace_arg2_with_arg1 (text, '\u00A7', '\u0B99\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u004E', '\u0B9A\u0BC2');
//text = myStringReplace_arg2_with_arg1 (text, '\u0160', '\u0B9E\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u005E', '\u0B9F\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u00FB', '\u0BA3\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u00F6', '\u0BA4\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u00FC', '\u0BA8\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u007D', '\u0BA9\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u00F3', '\u0BAA\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u005F', '\u0BAE\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u00F4', '\u0BAF\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u0025', '\u0BB0\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u00F9', '\u0BB1\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u00FF', '\u0BB2\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u00F1', '\u0BB5\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u003E', '\u0BB4\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u0071', '\u0BB3\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u00EA', '\u0BB7\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u00E8', '\u0BB8\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u00EB', '\u0BB9\u0BC2');
text = myStringReplace_arg2_with_arg1 (text, '\u00E9', '\u0B9C\u0BC2');
//text = myStringReplace_arg2_with_arg1 (text, '\u00EC', '\u0B95\u0BCD\u0BB7\u0BC2');





		return text;

}
var g_fontMapperCache = {
    fontMapperCSVFileContent:"",
    csvToArray:[[]],
    delimiter:",",
    };
function getFontMapperCache () {
    return g_fontMapperCache.csvToArray;
}
function resetFontMapperCache () {
    initConstants();    
    g_fontMapperCache.fontMapperCSVFileContent = "";
    g_fontMapperCache.csvToArray = [[]];
    g_fontMapperCache.delimiter = ",";
}
function setFontMapperCache (fontMapperCSVFileContent, delimiter) {
    resetFontMapperCache ();
    g_fontMapperCache.fontMapperCSVFileContent = fontMapperCSVFileContent;
    g_fontMapperCache.csvToArray = parseCSV (fontMapperCSVFileContent, delimiter);
    g_fontMapperCache.delimiter = delimiter;
}
function loadMapperAndConvert (convertMode, textToConvert) {    
    var arrayFrom = [], arrayTo = [];
    var csvToArray = [[]];
    var i = 0, j = 0, seq = 0;
    var convertedText = textToConvert;
    
    if (g_fontMapperCache.csvToArray.length ==1 && g_fontMapperCache.csvToArray[CSV_HEADER_ROW_INDEX].length == 0) {
        return convertedText;
        } 
    csvToArray = g_fontMapperCache.csvToArray;
    
    for (i = 0 ; i < csvToArray.length; i++) { // row index
        for ( j = 0 ; j < csvToArray[i].length; j+=2) { // column index jump by two since even fields are unicode and odd fields are non-unicode 
            if (convertMode == CONVERT_NONUNICODE_TO_UNICODE) {
                arrayFrom [seq] = csvToArray[i][j+1];
                arrayTo [seq] = csvToArray[i][j];
                } else {
                    arrayFrom [seq] = csvToArray[i][j];
                    arrayTo [seq] = csvToArray[i][j+1];
                    }
                if (arrayFrom[seq] == "") continue;
                try {
                    var tmpToSearch = "", tmpToReplace ="";
                    if (i == 13) 
                    tmpToSearch = arrayFrom [seq];
                tmpToSearch = setEscapeSpecialCharacters (arrayFrom [seq], true);
                tmpToReplace = arrayTo [seq];
                arrayFrom [seq] = tmpToSearch;
                convertedText = convertedText.replace (RegExp(String(tmpToSearch), "g"), tmpToReplace);
                }
                catch (e) {
                    alert("excpt: seq="+seq+" - "+arrayFrom[seq]+", textToConvert:"+textToConvert+
                    e.message + "\r(line " + e.line + ")");
                    }
                seq++;
            }
        }
    return convertedText;
}
function setEscapeSpecialCharacters (s, bEscape)
{
    // (un)escape all +=-|[{]}\(.)?$^~*%#@!
//    s =     (bEscape==false)?
//    s.replace (/\\([\u002B\u003D\u002D\u007C\u005B\u007B\u005D\u007D\u005C\u0028\u0029\u003F\u0024\u005E\u007E\u0025\u0023\u0040\u0021])/g, '$1'):
//    s.replace (/([\u002B\u003D\u002D\u007C\u005B\u007B\u005D\u007D\u005C\u0028\u0029\u003F\u0024\u005E\u007E\u0025\u0023\u0040\u0021])/g,'\\$1');
/*
+ 2b
[ 5b
% 25
^ 5e
$ 24
\ 5C
? 3F
( 28
) 29
[ 5B
] 5D
| 7C
& 26
{ 7B
} 7D
. 2E

*/
    if(bEscape==false)
        s=s.replace (/\\([\u002B\u005B\u0025\u005E\u0024\u005C\u003F\u0028\u0029\u005B\u005D\u007C\u0026\u007B\u007D\u002E])/g, '$1');
    else
        s=s.replace (/([\u002B\u005B\u0025\u005E\u0024\u005C\u003F\u0028\u0029\u005B\u005D\u007C\u0026\u007B\u007D\u002E])/g,'\\$1');
    return s;
}
function setEscapeSlashCharacter (s, bEscape)
{
    // (un)escape all +=-|[{]}\(.)?$^~*%#@!
//    s =     (bEscape==false)?
//    s.replace (/\\([\u002B\u003D\u002D\u007C\u005B\u007B\u005D\u007D\u005C\u0028\u0029\u003F\u0024\u005E\u007E\u0025\u0023\u0040\u0021])/g, '$1'):
//    s.replace (/([\u002B\u003D\u002D\u007C\u005B\u007B\u005D\u007D\u005C\u0028\u0029\u003F\u0024\u005E\u007E\u0025\u0023\u0040\u0021])/g,'\\$1');
/*
+ 2b
[ 5b
% 25
^ 5e
$ 24
\ 5C
? 3F
( 28
) 29
[ 5B
] 5D
| 7C
& 26
{ 7B
} 7D
. 2E
*/
    if(bEscape==false)
        s=s.replace (/\\([\u005C])/g, '$1');
    else
        s=s.replace (/([\u005C])/g,'\\$1');
    return s;
}
function convertFont_New (fontCode, textToConvert, convertMode) {
    initConstants();
    if (fontCode == LOAD_CUSTOM_NON_UNICODE_UNICODE_MAPPER )
    {
        return loadMapperAndConvert (convertMode, textToConvert);
    } else return "mapper not supported or invalid font code!";
}
function parseHTMLTag_extractContent(rawText, parseTag) {
    var elementArr = null, combinedText="", retObj = {combinedText:"", extractedTagClass:"", htmlDoc:null,};
    
    if (rawText.toLowerCase().trim().indexOf('<!doctype') === 0) {
        var doc = document.implementation.createHTMLDocument("");
        doc.documentElement.innerHTML = rawText;
        elementArr = doc.getElementsByTagName (parseTag);
        retObj.htmlDoc = doc;
    } else {
       var docfrag = document.createDocumentFragment();
       var el = document.createElement('html');
       el.innerHTML = rawText;
       for (i = 0; 0 < el.childNodes.length;) {
           docfrag.appendChild(el.childNodes[i]);
       }
       elementArr = docfrag.querySelectorAll(parseTag);   
        retObj.htmlDoc = docfrag;
       
    }
    for (var i=0; (elementArr != null &&i<elementArr.length); i++) {
        combinedText+=elementArr[i].innerHTML;
        retObj.extractedTagClass = elementArr[i].className;
        }
   retObj.combinedText = combinedText;
   
   return retObj;
}
function convertNon_unicodeToUnicode (nonUnicodeFont, text)
{
    initConstants();
    if (text == null || text =="") return text;
    if (nonUnicodeFont == BALARAM_SCA_GAUDY_FAMILY)
    {
        return convertFromBalaram (text);
    }
    
    if (nonUnicodeFont == SREELIPI_TAMEX_FAMILY)
    {
        return convertShree_TamEX_0803Text (text);
    }
    if (nonUnicodeFont == ADHAWIN_TAMIL_FAMILY)
    {
        return convertAdhawinTamilText (text);
    }
    if (nonUnicodeFont == INDOWORD_LT_TM_FAMILY)
    {
        return convertIndowordTamilText (text);
    }
    if (nonUnicodeFont == IDS_TAMIL_KA_FAMILY)
    {
        return convertIDSTamilText (text);
    }
    if (nonUnicodeFont == SREELIPI_GEN_813_817_FAMILY)
    {
        return convertShree_Tam_813_817Text (text);
    }
    if (nonUnicodeFont == TAB_ANNA_TAM_FAMILY)
    {
        return convertTAB_Anna_Text (text);
    }
    if (nonUnicodeFont == SUN_TAMIL_FAMILY)
    {
        return convertSunFamilyTamilText (text);
    }
    if (nonUnicodeFont == SANSKRIT_TIMES_FAMILY)
    {
        return convertSanskritTimesText (text, false); // second parameter means bReverseOrder is false... from non-unicode to unicode
    }

    alert ("Font conversion not implemented for font Family - "+nonUnicodeFont);
    return text;
}
function convertTAB_Anna_Text (inText)
{
	var text = inText;
	text = text.replace(/\u0026/g, '\u2013');
text = text.replace(/\u00DC/g, '\u0B85');
text = text.replace(/\u00DD/g, '\u0B86');
text = text.replace(/\u00DE/g, '\u0B87');
text = text.replace(/\u00DF/g, '\u0B88');
text = text.replace(/\u00E0/g, '\u0B89');
text = text.replace(/\u00E1/g, '\u0B8A');
text = text.replace(/\u00E2/g, '\u0B8E');
text = text.replace(/\u00E3/g, '\u0B8F');
text = text.replace(/\u00E4/g, '\u0B90');
text = text.replace(/\u00E5/g, '\u0B92');
text = text.replace(/\u00E6/g, '\u0B93');
text = text.replace(/\u00E5\u00F7/g, '\u0B94');
text = text.replace(/\u00E7/g, '\u0B83');

text = text.replace(/\u00E8/g, '\u0B95');
text = text.replace(/\u00E9/g, '\u0B99');
text = text.replace(/\u00EA/g, '\u0B9A');
text = text.replace(/\u00EB/g, '\u0B9E');
text = text.replace(/\u00EC/g, '\u0B9F');
text = text.replace(/\u00ED/g, '\u0BA3');
text = text.replace(/\u00EE/g, '\u0BA4');
text = text.replace(/\u00EF/g, '\u0BA8');
text = text.replace(/\u00F0/g, '\u0BAA');
text = text.replace(/\u00F1/g, '\u0BAE');
text = text.replace(/\u00F2/g, '\u0BAF');
text = text.replace(/\u00F3/g, '\u0BB0');
text = text.replace(/\u00F4/g, '\u0BB2');
text = text.replace(/\u00F5/g, '\u0BB5');
text = text.replace(/\u00F6/g, '\u0BB4');
text = text.replace(/\u00F7/g, '\u0BB3');
text = text.replace(/\u00F8/g, '\u0BB1');
text = text.replace(/\u00F9/g, '\u0BA9');
text = text.replace(/\u00FA/g, '\u0BB8');
text = text.replace(/\u00FB/g, '\u0BB7');
text = text.replace(/\u00FC/g, '\u0B9C');
text = text.replace(/\u00FD/g, '\u0BB9');
text = text.replace(/\u00FE/g, '\u0B95\u0BCD\u0BB7');
text = text.replace(/\u00FF/g, "ஸ்ரீ");


text = text.replace(/\u00A3/g, '\u0BBE');
text = text.replace(/\u00A4/g, '\u0BBF');
text = text.replace(/\u00A6/g, '\u0BC0');
text = text.replace(/\u00A7/g, '\u0BC1');
text = text.replace(/\u00A8/g, '\u0BC2');
text = text.replace(/\u00A2/g, '\u0BCD');

text = text.replace(/(\u00AA)(.)/g, '$2\u0BC6');
text = text.replace(/(\u00AB)(.)/g, '$2\u0BC7');
text = text.replace(/(\u00AC)(.)/g, '$2\u0BC8');
text = text.replace(/(\u00AA)(.)(\u00A3)/g, '$2\u0BCA');
text = text.replace(/(\u00AB)(.)(\u00A3)/g, '$2\u0BCB');
text = text.replace(/(\u00AA)(.)(\u00F7)/g, '$2\u0BCC');

text = text.replace(/\u00B0/g, '\u0B95\u0BC1');
text = text.replace(/\u00B1/g, '\u0B99\u0BC1');
text = text.replace(/\u00B2/g, '\u0B9A\u0BC1');
text = text.replace(/\u00B3/g, '\u0B9E\u0BC1');
text = text.replace(/\u00B4/g, '\u0B9F\u0BC1');
text = text.replace(/\u00B5/g, '\u0BA3\u0BC1');
text = text.replace(/\u00B6/g, '\u0BA4\u0BC1');
text = text.replace(/\u00B8/g, '\u0BA8\u0BC1');
text = text.replace(/\u00B9/g, '\u0BAA\u0BC1');
text = text.replace(/\u00BA/g, '\u0BAE\u0BC1');
text = text.replace(/\u00BB/g, '\u0BAF\u0BC1');
text = text.replace(/\u00BC/g, '\u0BB0\u0BC1');
text = text.replace(/\u00BD/g, '\u0BB2\u0BC1');
text = text.replace(/\u00BE/g, '\u0BB5\u0BC1');
text = text.replace(/\u00BF/g, '\u0BB4\u0BC1');
text = text.replace(/\u00C0/g, '\u0BB3\u0BC1');
text = text.replace(/\u00C1/g, '\u0BB1\u0BC1');
text = text.replace(/\u00C2/g, '\u0BA9\u0BC1');

text = text.replace(/\u00C3/g, '\u0B95\u0BC2');
text = text.replace(/\u00C4/g, '\u0B99\u0BC2');
text = text.replace(/\u00C5/g, '\u0B9A\u0BC2');
text = text.replace(/\u00C6/g, '\u0B9E\u0BC2');
text = text.replace(/\u00C7/g, '\u0B9F\u0BC2');
text = text.replace(/\u00C8/g, '\u0BA3\u0BC2');
text = text.replace(/\u00C9/g, '\u0BA4\u0BC2');
text = text.replace(/\u00CB/g, '\u0BA8\u0BC2');
text = text.replace(/\u00CC/g, '\u0BAA\u0BC2');
text = text.replace(/\u00CD/g, '\u0BAE\u0BC2');
text = text.replace(/\u00CE/g, '\u0BAF\u0BC2');
text = text.replace(/\u00CF/g, '\u0BB0\u0BC2');
text = text.replace(/\u00D6/g, '\u0BB2\u0BC2');
text = text.replace(/\u00D7/g, '\u0BB5\u0BC2');
text = text.replace(/\u00D8/g, '\u0BB4\u0BC2');
text = text.replace(/\u00D9/g, '\u0BB3\u0BC2');
text = text.replace(/\u00DA/g, '\u0BB1\u0BC2');
text = text.replace(/\u00DB/g, '\u0BA9\u0BC2');


		return text;
    
}
function convertShree_Tam_813_817Text(inText) {
	var text = inText;

	text = text.replace(/\u0026/g, '\u2013');
	text = text.replace(/\u00FF/g, "ஸ்ரீ");
text = text.replace(/\u004C/g, '\u0B83');
text = text.replace(/\u0041/g, '\u0B85');
text = text.replace(/\u0042/g, '\u0B86');
text = text.replace(/\u0043/g, '\u0B87');
text = text.replace(/\u0044/g, '\u0B88');
text = text.replace(/\u0045/g, '\u0B89');
text = text.replace(/\u0046/g, '\u0B8A');
text = text.replace(/\u0047/g, '\u0B8E');
text = text.replace(/\u0048/g, '\u0B8F');
text = text.replace(/\u0049/g, '\u0B90');
text = text.replace(/\u004A/g, '\u0B92');
text = text.replace(/\u004B/g, '\u0B93');
text = text.replace(/\u004A\u00CD/g, '\u0B94');

text = text.replace(/\u0050/g, '\u0B95');
text = text.replace(/\u0051/g, '\u0B95\u0BBF');
text = text.replace(/\u0052/g, '\u0B95\u0BC0');
text = text.replace(/\u0053/g, '\u0B95\u0BC1');
text = text.replace(/\u0054/g, '\u0B95\u0BC2');
text = text.replace(/\u0055/g, '\u0B95\u0BCD');
text = text.replace(/\u0056/g, '\u0B99');
text = text.replace(/\u0057/g, '\u0B99\u0BBF');
text = text.replace(/\u0058/g, '\u0B99\u0BC0');
text = text.replace(/\u0059/g, '\u0B99\u0BC1');
text = text.replace(/\u005A/g, '\u0B99\u0BC2');
text = text.replace(/\u005B/g, '\u0B99\u0BCD');
text = text.replace(/\u005C/g, '\u0B9A');
text = text.replace(/\u005D/g, '\u0B9A\u0BBF');
text = text.replace(/\u005E/g, '\u0B9A\u0BC0');
text = text.replace(/\u005F/g, '\u0B9A\u0BC1');
text = text.replace(/\u0060/g, '\u0B9A\u0BC2');
text = text.replace(/\u0061/g, '\u0B9A\u0BCD');
text = text.replace(/\u0062/g, '\u0B9E');
text = text.replace(/\u0063/g, '\u0B9E\u0BBF');
text = text.replace(/\u0064/g, '\u0B9E\u0BC0');
text = text.replace(/\u0065/g, '\u0B9E\u0BC1');
text = text.replace(/\u0066/g, '\u0B9E\u0BC2');
text = text.replace(/\u0067/g, '\u0B9E\u0BCD');
text = text.replace(/\u0068/g, '\u0B9F');
text = text.replace(/\u0069/g, '\u0B9F\u0BBF');
text = text.replace(/\u006A/g, '\u0B9F\u0BC0');
text = text.replace(/\u006B/g, '\u0B9F\u0BC1');
text = text.replace(/\u006C/g, '\u0B9F\u0BC2');
text = text.replace(/\u006D/g, '\u0B9F\u0BCD');
text = text.replace(/\u006E/g, '\u0BA3');
text = text.replace(/\u006F/g, '\u0BA3\u0BBF');
text = text.replace(/\u0070/g, '\u0BA3\u0BC0');
text = text.replace(/\u0071/g, '\u0BA3\u0BC1');
text = text.replace(/\u0072/g, '\u0BA3\u0BC2');
text = text.replace(/\u0073/g, '\u0BA3\u0BCD');
text = text.replace(/\u0074/g, '\u0BA3\u0BBE');
text = text.replace(/\u0075/g, '\u0BA4');
text = text.replace(/\u0076/g, '\u0BA4\u0BBF');
text = text.replace(/\u0077/g, '\u0BA4\u0BC0');
text = text.replace(/\u0078/g, '\u0BA4\u0BC1');
text = text.replace(/\u0079/g, '\u0BA4\u0BC2');
text = text.replace(/\u007A/g, '\u0BA4\u0BCD');
text = text.replace(/\u007C/g, '\u0BA8');
text = text.replace(/\u007B/g, '\u0BA8\u0BBF');
text = text.replace(/\u007D/g, '\u0BA8\u0BC0');
text = text.replace(/\u007E/g, '\u0BA8\u0BC1');
text = text.replace(/\u00A1/g, '\u0BA8\u0BC2');
text = text.replace(/\u00A2/g, '\u0BA8\u0BCD');
text = text.replace(/\u00A3/g, '\u0BAA');
text = text.replace(/\u00A4/g, '\u0BAA\u0BBF');
text = text.replace(/\u00A5/g, '\u0BAA\u0BC0');
text = text.replace(/\u00A6/g, '\u0BAA\u0BC1');
text = text.replace(/\u00A7/g, '\u0BAA\u0BC2');
text = text.replace(/\u00A8/g, '\u0BAA\u0BCD');
text = text.replace(/\u00A9/g, '\u0BAE');
text = text.replace(/\u00AA/g, '\u0BAE\u0BBF');
text = text.replace(/\u00AB/g, '\u0BAE\u0BC0');
text = text.replace(/\u2022/g, '\u0BAE\u0BC1');
text = text.replace(/\u2030/g, '\u0BAE\u0BC2');
text = text.replace(/\u00AE/g, '\u0BAE\u0BCD');
text = text.replace(/\u00AF/g, '\u0BAF');
text = text.replace(/\u00B0/g, '\u0BAF\u0BBF');
text = text.replace(/\u00B1/g, '\u0BAF\u0BC0');
text = text.replace(/\u00B2/g, '\u0BAF\u0BC1');
text = text.replace(/\u00B3/g, '\u0BAF\u0BC2');
text = text.replace(/\u00B4/g, '\u0BAF\u0BCD');
text = text.replace(/\u00B5/g, '\u0BB0');
text = text.replace(/\u230A/g, '\u0BB0\u0BBF');
text = text.replace(/\u0178/g, '\u0BB0\u0BC0');
text = text.replace(/\u00B8/g, '\u0BB0\u0BC1');
text = text.replace(/\u00B9/g, '\u0BB0\u0BC2');
text = text.replace(/\u00BA/g, '\u0BB0\u0BCD');
text = text.replace(/\u00BB/g, '\u0BB2');
text = text.replace(/\u00BC/g, '\u0BB2\u0BBF');
text = text.replace(/\u00BD/g, '\u0BB2\u0BC0');
text = text.replace(/\u00BE/g, '\u0BB2\u0BC1');
text = text.replace(/\u00BF/g, '\u0BB2\u0BC2');
text = text.replace(/\u00C0/g, '\u0BB2\u0BCD');
text = text.replace(/\u00C1/g, '\u0BB5');
text = text.replace(/\u00C2/g, '\u0BB5\u0BBF');
text = text.replace(/\u00C3/g, '\u0BB5\u0BC0');
text = text.replace(/\u00C4/g, '\u0BB5\u0BC1');
text = text.replace(/\u00C5/g, '\u0BB5\u0BC2');
text = text.replace(/\u00C6/g, '\u0BB5\u0BCD');
text = text.replace(/\u00C7/g, '\u0BB4');
text = text.replace(/\u00C8/g, '\u0BB4\u0BBF');
text = text.replace(/\u00C9/g, '\u0BB4\u0BC0');
text = text.replace(/\u00CA/g, '\u0BB4\u0BC1');
text = text.replace(/\u00CB/g, '\u0BB4\u0BC2');
text = text.replace(/\u00CC/g, '\u0BB4\u0BCD');
text = text.replace(/\u00CD/g, '\u0BB3');
text = text.replace(/\u00CE/g, '\u0BB3\u0BBF');
text = text.replace(/\u00CF/g, '\u0BB3\u0BC0');
text = text.replace(/\u00D0/g, '\u0BB3\u0BC1');
text = text.replace(/\u00D1/g, '\u0BB3\u0BC2');
text = text.replace(/\u00D2/g, '\u0BB3\u0BCD');
text = text.replace(/\u00D3/g, '\u0BB1');
text = text.replace(/\u00D4/g, '\u0BB1\u0BBF');
text = text.replace(/\u00D5/g, '\u0BB1\u0BC0');
text = text.replace(/\u00D6/g, '\u0BB1\u0BC1');
text = text.replace(/\u00D7/g, '\u0BB1\u0BC2');
text = text.replace(/\u00D8/g, '\u0BB1\u0BCD');
text = text.replace(/\u00D9/g, '\u0BB1\u0BBE');
text = text.replace(/\u00DA/g, '\u0BA9');
text = text.replace(/\u00DB/g, '\u0BA9\u0BBF');
text = text.replace(/\u00DC/g, '\u0BA9\u0BC0');
text = text.replace(/\u00DD/g, '\u0BA9\u0BC1');
text = text.replace(/\u00DE/g, '\u0BA9\u0BC2');
text = text.replace(/\u00DF/g, '\u0BA9\u0BCD');
text = text.replace(/\u00E0/g, '\u0BA9\u0BBE');
text = text.replace(/\u00E1/g, '\u0B9C');
text = text.replace(/\u00E2/g, '\u0B9C\u0BBF');
text = text.replace(/\u00E3/g, '\u0B9C\u0BC0');
text = text.replace(/\u00E4/g, '\u0B9C\u0BCD');
text = text.replace(/\u00E5/g, '\u0BB7');
text = text.replace(/\u00E6/g, '\u0BB7\u0BBF');
text = text.replace(/\u00E7/g, '\u0BB7\u0BC0');
text = text.replace(/\u00E8/g, '\u0BB7\u0BCD');
text = text.replace(/\u00E9/g, '\u0BB8');
text = text.replace(/\u00EA/g, '\u0BB8\u0BBF');
text = text.replace(/\u00EB/g, '\u0BB8\u0BC0');
text = text.replace(/\u00EC/g, '\u0BB8\u0BCD');
text = text.replace(/\u00ED/g, '\u0BB9');
text = text.replace(/\u00EE/g, '\u0BB9\u0BBF');
text = text.replace(/\u00EF/g, '\u0BB9\u0BC0');
text = text.replace(/\u00F0/g, '\u0BB9\u0BCD');
text = text.replace(/\u00F1/g, '\u0B95\u0BCD\u0BB7');
text = text.replace(/\u00F2/g, '\u0B95\u0BCD\u0BB7\u0BBF');
text = text.replace(/\u00F3/g, '\u0B95\u0BCD\u0BB7\u0BC0');
text = text.replace(/\u00F4/g, '\u0B95\u0BCD\u0BB7\u0BCD');

text = text.replace(/(.)(\u00F5)/g, '$1\u0BBE');
text = text.replace(/(\u00F6)(.)/g, '$2\u0BC6');
text = text.replace(/(\u00F7)(.)/g, '$2\u0BC7');
text = text.replace(/(\u00F8)(.)/g, '$2\u0BC8');
text = text.replace(/(\u00F9)(.)/g, '$2\u0BC8');
text = text.replace(/(\u00F6)(.)(\u00F5)/g, '$2\u0BCA');
text = text.replace(/(\u00F7)(.)(\u00F5)/g, '$2\u0BCB');
text = text.replace(/(\u00F6)(.)(\u00CD)/g, '$2\u0BCC');

text = text.replace(/(.)(\u00FA)/g, '$1\u0BC1');
text = text.replace(/(.)(\u00FB)/g, '$1\u0BC1');
text = text.replace(/(.)(\u00FC)/g, '$1\u0BC2');
text = text.replace(/(.)(\u00FD)/g, '$1\u0BC2');

		return text;

}

function convertIDSTamilText(inText) {
	var text = inText;

		text = text.replace(/\u0063/g, "ஸ்ரீ");
text = text.replace(/\u0040/g, '\u0B83');
text = text.replace(/\u0041/g, '\u0B85');
text = text.replace(/\u0042/g, '\u0B86');
text = text.replace(/\u0043/g, '\u0B87');
text = text.replace(/\u0044/g, '\u0B88');
text = text.replace(/\u0045/g, '\u0B89');
text = text.replace(/\u0046/g, '\u0B8A');
text = text.replace(/\u0047/g, '\u0B8E');
text = text.replace(/\u0048/g, '\u0B8F');
text = text.replace(/\u0049/g, '\u0B90');
text = text.replace(/\u004A/g, '\u0B92');
text = text.replace(/\u004B/g, '\u0B93');
text = text.replace(/\u004A\u005B/g, '\u0B94');

text = text.replace(/\u004C/g, '\u0B95');
text = text.replace(/\u004D/g, '\u0B99');
text = text.replace(/\u004E/g, '\u0B9A');
text = text.replace(/\u004F/g, '\u0B9E');
text = text.replace(/\u0050/g, '\u0B9F');
text = text.replace(/\u0051/g, '\u0BA3');
text = text.replace(/\u0052/g, '\u0BA4');
text = text.replace(/\u0053/g, '\u0BA8');
text = text.replace(/\u005D/g, '\u0BA9');
text = text.replace(/\u0054/g, '\u0BAA');
text = text.replace(/\u0055/g, '\u0BAE');
text = text.replace(/\u0056/g, '\u0BAF');
text = text.replace(/\u0057/g, '\u0BB0');
text = text.replace(/\u005C/g, '\u0BB1');
text = text.replace(/\u0058/g, '\u0BB2');
text = text.replace(/\u005A/g, '\u0BB4');
text = text.replace(/\u005B/g, '\u0BB3');
text = text.replace(/\u0059/g, '\u0BB5');
text = text.replace(/\u0060/g, '\u0BB7');
text = text.replace(/\u005E/g, '\u0BB8');
text = text.replace(/\u0061/g, '\u0BB9');
text = text.replace(/\u005F/g, '\u0B9C');
text = text.replace(/\u0062/g, '\u0B95\u0BCD\u0BB7');

text = text.replace(/(.)(\u00F4)/g, '$1\u0BBE');
text = text.replace(/\u007E/g, '\u0BA9\u0BBE');
text = text.replace(/(\u00F9)(.)/g, '$2\u0BC6');
text = text.replace(/(\u00FA)(.)/g, '$2\u0BC7');
text = text.replace(/(\u00FB)(.)/g, '$2\u0BC8');

text = text.replace(/\u007B/g, '\u0BA3\u0BC8');
text = text.replace(/\u007D/g, '\u0BB3\u0BC8');
text = text.replace(/\u0080/g, '\u0BA9\u0BC8');
text = text.replace(/\u0081/g, '\u0BB2\u0BC8');


text = text.replace(/(\u00F9)(.)(\u00F4)/g, '$2\u0BCA');
text = text.replace(/(\u00FA)(.)(\u00F4)/g, '$2\u0BCB');

text = text.replace(/(\u00F9)(.)(\u005D)/g, '$2\u0BCC');

text = text.replace(/\u0064/g, '\u0B95\u0BCD');
text = text.replace(/\u0065/g, '\u0B99\u0BCD');
text = text.replace(/\u0066/g, '\u0B9A\u0BCD');
text = text.replace(/\u0067/g, '\u0B9E\u0BCD');
text = text.replace(/\u0068/g, '\u0B9F\u0BCD');
text = text.replace(/\u0069/g, '\u0BA3\u0BCD');
text = text.replace(/\u006A/g, '\u0BA4\u0BCD');
text = text.replace(/\u006B/g, '\u0BA8\u0BCD');
text = text.replace(/\u0075/g, '\u0BA9\u0BCD');
text = text.replace(/\u006C/g, '\u0BAA\u0BCD');
text = text.replace(/\u006D/g, '\u0BAE\u0BCD');
text = text.replace(/\u006E/g, '\u0BAF\u0BCD');
text = text.replace(/\u006F/g, '\u0BB0\u0BCD');
text = text.replace(/\u0074/g, '\u0BB1\u0BCD');
text = text.replace(/\u0070/g, '\u0BB2\u0BCD');
text = text.replace(/\u2071/g, '\u0BB5\u0BCD');
text = text.replace(/\u0072/g, '\u0BB4\u0BCD');
text = text.replace(/\u0073/g, '\u0BB3\u0BCD');
text = text.replace(/\u0078/g, '\u0BB7\u0BCD');
text = text.replace(/\u0076/g, '\u0BB8\u0BCD');
text = text.replace(/\u0079/g, '\u0BB9\u0BCD');
text = text.replace(/\u0077/g, '\u0B9C\u0BCD');
text = text.replace(/\u007A/g, '\u0B95\u0BCD\u0BB7\u0BCD');

text = text.replace(/(.)(\u00F7)/g, '$1\u0BC1');
text = text.replace(/(.)(\u00F8)/g, '$1\u0BC2');

text = text.replace(/\u00A1/g, '\u0B95\u0BBF');
//text = text.replace(/\u00A7/g, '\u0B99\u0BBF');
text = text.replace(/\u00A3/g, '\u0B9A\u0BBF');
//text = text.replace(/\u0160/g, '\u0B9E\u0BBF');
text = text.replace(/\u00A5/g, '\u0B9F\u0BBF');
text = text.replace(/\u00A6/g, '\u0BA3\u0BBF');
text = text.replace(/\u00A7/g, '\u0BA4\u0BBF');
text = text.replace(/\u00A8/g, '\u0BA8\u0BBF');
text = text.replace(/\u00B2/g, '\u0BA9\u0BBF');
text = text.replace(/\u00A9/g, '\u0BAA\u0BBF');
text = text.replace(/\u00AA/g, '\u0BAE\u0BBF');
text = text.replace(/\u00AB/g, '\u0BAF\u0BBF');
text = text.replace(/\u00AC/g, '\u0BB0\u0BBF');
text = text.replace(/\u00B1/g, '\u0BB1\u0BBF');
text = text.replace(/\u00AD/g, '\u0BB2\u0BBF');
text = text.replace(/\u00AE/g, '\u0BB5\u0BBF');
text = text.replace(/\u00AF/g, '\u0BB4\u0BBF');
text = text.replace(/\u00B0/g, '\u0BB3\u0BBF');
text = text.replace(/\u00B5/g, '\u0BB7\u0BBF');
text = text.replace(/\u00B3/g, '\u0BB8\u0BBF');
text = text.replace(/\u00B6/g, '\u0BB9\u0BBF');
text = text.replace(/\u00B4/g, '\u0B9C\u0BBF');
//text = text.replace(/\u00F8/g, '\u0B95\u0BCD\u0BB7\u0BBF');

text = text.replace(/\u00B8/g, '\u0B95\u0BC0');
//text = text.replace(/\u00A7/g, '\u0B99\u0BC0');
text = text.replace(/\u00BA/g, '\u0B9A\u0BC0');
//text = text.replace(/\u0160/g, '\u0B9E\u0BC0');
text = text.replace(/\u00BC/g, '\u0B9F\u0BC0');
text = text.replace(/\u00BD/g, '\u0BA3\u0BC0');
text = text.replace(/\u00BE/g, '\u0BA4\u0BC0');
text = text.replace(/\u00BF/g, '\u0BA8\u0BC0');
text = text.replace(/\u00C9/g, '\u0BA9\u0BC0');
text = text.replace(/\u00C0/g, '\u0BAA\u0BC0');
text = text.replace(/\u00C1/g, '\u0BAE\u0BC0');
text = text.replace(/\u00C2/g, '\u0BAF\u0BC0');
text = text.replace(/\u00C3/g, '\u0BB0\u0BC0');
text = text.replace(/\u00C8/g, '\u0BB1\u0BC0');
text = text.replace(/\u00C4/g, '\u0BB2\u0BC0');
text = text.replace(/\u00C5/g, '\u0BB5\u0BC0');
text = text.replace(/\u00C6/g, '\u0BB4\u0BC0');
text = text.replace(/\u00C7/g, '\u0BB3\u0BC0');
text = text.replace(/\u00CC/g, '\u0BB7\u0BC0');
text = text.replace(/\u00CA/g, '\u0BB8\u0BC0');
text = text.replace(/\u00CD/g, '\u0BB9\u0BC0');
text = text.replace(/\u00B4/g, '\u0B9C\u0BC0');
text = text.replace(/\u00CE/g, '\u0B95\u0BCD\u0BB7\u0BC0');

text = text.replace(/\u00CF/g, '\u0B95\u0BC1');
//text = text.replace(/\u00A7/g, '\u0B99\u0BC1');
text = text.replace(/\u00D1/g, '\u0B9A\u0BC1');
//text = text.replace(/\u0160/g, '\u0B9E\u0BC1');
text = text.replace(/\u00D3/g, '\u0B9F\u0BC1');
text = text.replace(/\u00D4/g, '\u0BA3\u0BC1');
text = text.replace(/\u00D5/g, '\u0BA4\u0BC1');
text = text.replace(/\u00D6/g, '\u0BA8\u0BC1');
text = text.replace(/\u00E0/g, '\u0BA9\u0BC1');
text = text.replace(/\u00D7/g, '\u0BAA\u0BC1');
text = text.replace(/\u00D8/g, '\u0BAE\u0BC1');
text = text.replace(/\u00D9/g, '\u0BAF\u0BC1');
text = text.replace(/\u00DA/g, '\u0BB0\u0BC1');
text = text.replace(/\u00DF/g, '\u0BB1\u0BC1');
text = text.replace(/\u00DB/g, '\u0BB2\u0BC1');
text = text.replace(/\u00DC/g, '\u0BB5\u0BC1');
text = text.replace(/\u00DD/g, '\u0BB4\u0BC1');
text = text.replace(/\u00DE/g, '\u0BB3\u0BC1');

text = text.replace(/\u00E1/g, '\u0B95\u0BC2');
//text = text.replace(/\u00A7/g, '\u0B99\u0BC2');
text = text.replace(/\u00E3/g, '\u0B9A\u0BC2');
//text = text.replace(/\u0160/g, '\u0B9E\u0BC2');
text = text.replace(/\u00E5/g, '\u0B9F\u0BC2');
text = text.replace(/\u00E6/g, '\u0BA3\u0BC2');
text = text.replace(/\u00E7/g, '\u0BA4\u0BC2');
text = text.replace(/\u00E8/g, '\u0BA8\u0BC2');
text = text.replace(/\u00F2/g, '\u0BA9\u0BC2');
text = text.replace(/\u00E9/g, '\u0BAA\u0BC2');
text = text.replace(/\u00EA/g, '\u0BAE\u0BC2');
text = text.replace(/\u00EB/g, '\u0BAF\u0BC2');
text = text.replace(/\u00EC/g, '\u0BB0\u0BC2');
text = text.replace(/\u00F1/g, '\u0BB1\u0BC2');
text = text.replace(/\u00ED/g, '\u0BB2\u0BC2');
text = text.replace(/\u00EE/g, '\u0BB5\u0BC2');
text = text.replace(/\u00EF/g, '\u0BB4\u0BC2');
text = text.replace(/\u00F0/g, '\u0BB3\u0BC2');





		return text;

}
function convertIndowordTamilText(inText) {
	var text = inText;

		text = text.replace(/\u0024/g, "ஸ்ரீ");
text = text.replace(/\u007E/g, '\u0B83');
text = text.replace(/\u006D/g, '\u0B85');
text = text.replace(/\u004D/g, '\u0B86');
text = text.replace(/\u00EF/g, '\u0B87');
text = text.replace(/\u003C/g, '\u0B88');
text = text.replace(/\u0063/g, '\u0B89');
text = text.replace(/\u0043/g, '\u0B8A');
text = text.replace(/\u0076/g, '\u0B8E');
text = text.replace(/\u0056/g, '\u0B8F');
text = text.replace(/\u0049/g, '\u0B90');
text = text.replace(/\u0078/g, '\u0B92');
text = text.replace(/\u0058/g, '\u0B93');
text = text.replace(/\u0078\u0073/g, '\u0B94');

text = text.replace(/\u0066/g, '\u0B95');
text = text.replace(/\u2021/g, '\u0B99');
text = text.replace(/\u0072/g, '\u0B9A');
text = text.replace(/\u0050/g, '\u0B9E');
text = text.replace(/\u006C/g, '\u0B9F');
text = text.replace(/\u007A/g, '\u0BA3');
text = text.replace(/\u006A/g, '\u0BA4');
text = text.replace(/\u0065/g, '\u0BA8');
text = text.replace(/\u0064/g, '\u0BA9');
text = text.replace(/\u0067/g, '\u0BAA');
text = text.replace(/\u006B/g, '\u0BAE');
text = text.replace(/\u0061/g, '\u0BAF');
text = text.replace(/\u0075/g, '\u0BB0');
text = text.replace(/\u0077/g, '\u0BB1');
text = text.replace(/\u0079/g, '\u0BB2');
text = text.replace(/\u0074/g, '\u0BB5');
text = text.replace(/\u0048/g, '\u0BB4');
text = text.replace(/\u0073/g, '\u0BB3');
text = text.replace(/\u00F5/g, '\u0BB7');
text = text.replace(/\u005B/g, '\u0BB8');
text = text.replace(/\u0041/g, '\u0BB9');
text = text.replace(/\u0023/g, '\u0B9C');

text = text.replace(/(.)(\u0068)/g, '$1\u0BBE');
text = text.replace(/\u201A/g, '\u0BA3\u0BBE');
text = text.replace(/\u201E/g, '\u0BA9\u0BBE');
text = text.replace(/\u0192/g, '\u0BB1\u0BBE');
text = text.replace(/(\u0062)(.)/g, '$2\u0BC6');
text = text.replace(/(\u006E)(.)/g, '$2\u0BC7');

text = text.replace(/(\u0062)(.)(\u0068)/g, '$2\u0BCA');
text = text.replace(/(\u0067)(.)(\u0068)/g, '$2\u0BCB');
text = text.replace(/(\u0069)(.)/g, '$2\u0BC8');

text = text.replace(/(\u0062)(.)(\u0073)/g, '$2\u0BCC');

text = text.replace(/\u00A1/g, '\u0B95\u0BCD');
text = text.replace(/\u00A7/g, '\u0B99\u0BCD');
text = text.replace(/\u00A2/g, '\u0B9A\u0BCD');
text = text.replace(/\u0160/g, '\u0B9E\u0BCD');
text = text.replace(/\u00A3/g, '\u0B9F\u0BCD');
text = text.replace(/\u00A9/g, '\u0BA3\u0BCD');
text = text.replace(/\u00A4/g, '\u0BA4\u0BCD');
text = text.replace(/\u00AA/g, '\u0BA8\u0BCD');
text = text.replace(/\u2039/g, '\u0BA9\u0BCD');
text = text.replace(/\u00A5/g, '\u0BAA\u0BCD');
text = text.replace(/\u00AB/g, '\u0BAE\u0BCD');
text = text.replace(/\u0152/g, '\u0BAF\u0BCD');
text = text.replace(/\u00AE/g, '\u0BB0\u0BCD');
text = text.replace(/\u2030/g, '\u0BB1\u0BCD');
text = text.replace(/\u0161/g, '\u0BB2\u0BCD');
text = text.replace(/\u203A/g, '\u0BB5\u0BCD');
text = text.replace(/\u0153/g, '\u0BB4\u0BCD');
text = text.replace(/\u0178/g, '\u0BB3\u0BCD');
text = text.replace(/\u005A/g, '\u0BB7\u0BCD');
text = text.replace(/\u00B0/g, '\u0BB8\u0BCD');
text = text.replace(/\u00DE/g, '\u0BB8\u0BCD');
text = text.replace(/\u00E0/g, '\u0BB9\u0BCD');
text = text.replace(/\u007B/g, '\u0B9C\u0BCD');
text = text.replace(/\u00BA/g, '\u0B95\u0BCD\u0BB7\u0BCD');

text = text.replace(/(.)(\u0026)/g, '$1\u0BBF');
text = text.replace(/(.)(\u005D)/g, '$1\u0BC0');

text = text.replace(/\u00BB/g, '\u0B95\u0BBF');
text = text.replace(/\u00A7/g, '\u0B99\u0BBF');
text = text.replace(/\u00E1/g, '\u0B9A\u0BBF');
//text = text.replace(/\u0160/g, '\u0B9E\u0BBF');
text = text.replace(/\u006F/g, '\u0B9F\u0BBF');
text = text.replace(/\u00C2/g, '\u0BA3\u0BBF');
text = text.replace(/\u00E2/g, '\u0BA4\u0BBF');
text = text.replace(/\u00C3/g, '\u0BA8\u0BBF');
text = text.replace(/\u00C5/g, '\u0BA9\u0BBF');
text = text.replace(/\u00E3/g, '\u0BAA\u0BBF');
text = text.replace(/\u00C4/g, '\u0BAE\u0BBF');
text = text.replace(/\u00C6/g, '\u0BAF\u0BBF');
text = text.replace(/\u00C7/g, '\u0BB0\u0BBF');
text = text.replace(/\u00BF/g, '\u0BB1\u0BBF');
text = text.replace(/\u00C8/g, '\u0BB2\u0BBF');
text = text.replace(/\u00C9/g, '\u0BB5\u0BBF');
text = text.replace(/\u00CA/g, '\u0BB4\u0BBF');
text = text.replace(/\u00CB/g, '\u0BB3\u0BBF');
text = text.replace(/\u00CE/g, '\u0BB7\u0BBF');
text = text.replace(/\u00CC/g, '\u0BB8\u0BBF');
text = text.replace(/\u00CF/g, '\u0BB9\u0BBF');
text = text.replace(/\u00CD/g, '\u0B9C\u0BBF');
text = text.replace(/\u00F8/g, '\u0B95\u0BCD\u0BB7\u0BBF');

text = text.replace(/\u00D1/g, '\u0B95\u0BC0');
//text = text.replace(/\u00A7/g, '\u0B99\u0BC0');
text = text.replace(/\u00D3/g, '\u0B9A\u0BC0');
//text = text.replace(/\u0160/g, '\u0B9E\u0BC0');
text = text.replace(/\u004F/g, '\u0B9F\u0BC0');
text = text.replace(/\u00D9/g, '\u0BA3\u0BC0');
text = text.replace(/\u00D4/g, '\u0BA4\u0BC0');
text = text.replace(/\u00DA/g, '\u0BA8\u0BC0');
text = text.replace(/\u00DC/g, '\u0BA9\u0BC0');
text = text.replace(/\u00D5/g, '\u0BAA\u0BC0');
text = text.replace(/\u00DB/g, '\u0BAE\u0BC0');
text = text.replace(/\u0070/g, '\u0BAF\u0BC0');
text = text.replace(/\u00DF/g, '\u0BB0\u0BC0');
text = text.replace(/\u00D6/g, '\u0BB1\u0BC0');
text = text.replace(/\u00E4/g, '\u0BB2\u0BC0');
text = text.replace(/\u00E5/g, '\u0BB5\u0BC0');
text = text.replace(/\u00E6/g, '\u0BB4\u0BC0');
text = text.replace(/\u00E7/g, '\u0BB3\u0BC0');
text = text.replace(/\u00EA/g, '\u0BB7\u0BC0');
text = text.replace(/\u00E8/g, '\u0BB8\u0BC0');
text = text.replace(/\u00EB/g, '\u0BB9\u0BC0');
text = text.replace(/\u00E9/g, '\u0B9C\u0BC0');
text = text.replace(/\u00EC/g, '\u0B95\u0BCD\u0BB7\u0BC0');

text = text.replace(/\u0046/g, '\u0B95\u0BC1');
//text = text.replace(/\u00A7/g, '\u0B99\u0BC1');
text = text.replace(/\u0052/g, '\u0B9A\u0BC1');
//text = text.replace(/\u0160/g, '\u0B9E\u0BC1');
text = text.replace(/\u004C/g, '\u0B9F\u0BC1');
text = text.replace(/\u0051/g, '\u0BA3\u0BC1');
text = text.replace(/\u004A/g, '\u0BA4\u0BC1');
text = text.replace(/\u0045/g, '\u0BA8\u0BC1');
text = text.replace(/\u0044/g, '\u0BA9\u0BC1');
text = text.replace(/\u00F2/g, '\u0BAA\u0BC1');
text = text.replace(/\u004B/g, '\u0BAE\u0BC1');
text = text.replace(/\u00ED/g, '\u0BAF\u0BC1');
text = text.replace(/\u0055/g, '\u0BB0\u0BC1');
text = text.replace(/\u0057/g, '\u0BB1\u0BC1');
text = text.replace(/\u0059/g, '\u0BB2\u0BC1');
text = text.replace(/\u00EE/g, '\u0BB5\u0BC1');
text = text.replace(/\u0047/g, '\u0BB4\u0BC1');
text = text.replace(/\u0053/g, '\u0BB3\u0BC1');
text = text.replace(/\u00CE/g, '\u0BB7\u0BC1');
text = text.replace(/\u00CC/g, '\u0BB8\u0BC1');
text = text.replace(/\u0044/g, '\u0BB9\u0BC1');
//text = text.replace(/\u00CD/g, '\u0B9C\u0BC1');
//text = text.replace(/\u00F8/g, '\u0B95\u0BCD\u0BB7\u0BC1');

text = text.replace(/\u0054/g, '\u0B95\u0BC2');
//text = text.replace(/\u00A7/g, '\u0B99\u0BC2');
text = text.replace(/\u004E/g, '\u0B9A\u0BC2');
//text = text.replace(/\u0160/g, '\u0B9E\u0BC2');
text = text.replace(/\u005E/g, '\u0B9F\u0BC2');
text = text.replace(/\u00FB/g, '\u0BA3\u0BC2');
text = text.replace(/\u00F6/g, '\u0BA4\u0BC2');
text = text.replace(/\u00FC/g, '\u0BA8\u0BC2');
text = text.replace(/\u007D/g, '\u0BA9\u0BC2');
text = text.replace(/\u00F3/g, '\u0BAA\u0BC2');
text = text.replace(/\u005F/g, '\u0BAE\u0BC2');
text = text.replace(/\u00F4/g, '\u0BAF\u0BC2');
text = text.replace(/\u0025/g, '\u0BB0\u0BC2');
text = text.replace(/\u00F9/g, '\u0BB1\u0BC2');
text = text.replace(/\u00FF/g, '\u0BB2\u0BC2');
text = text.replace(/\u00F1/g, '\u0BB5\u0BC2');
text = text.replace(/\u003E/g, '\u0BB4\u0BC2');
text = text.replace(/\u0071/g, '\u0BB3\u0BC2');
text = text.replace(/\u00EA/g, '\u0BB7\u0BC2');
text = text.replace(/\u00E8/g, '\u0BB8\u0BC2');
text = text.replace(/\u00EB/g, '\u0BB9\u0BC2');
text = text.replace(/\u00E9/g, '\u0B9C\u0BC2');
//text = text.replace(/\u00EC/g, '\u0B95\u0BCD\u0BB7\u0BC2');

text = text.replace(/\u0042/g, '\u0B95\u0BCD\u0BB7'); //க்ஷ...should be at the end only after replacing kshE etc




		return text;

}
function convertAdhawinTamilText(inText) {
	var text = inText;

		text = text.replace(/\u00E0/g, "ஸ்ரீ");
text = text.replace(/\u00BD\u00E7/g, '\u00BD\u00B1\u00DF');
text = text.replace(/\u00BD\u00E6/g, '\u00BD\u00A6\u00DF');
text = text.replace(/\u00BD\u00E7/g, '\u00BD\u00B2\u00DF');

text = text.replace(/\u00D3\u00DC/g, '\u00D3');
text = text.replace(/\u00D4\u00DC/g, '\u00D4');
text = text.replace(/\u00DF\u00DC/g, '\u0BB0\u0BCD');

text = text.replace(/\u00FE/g, '\u0B83');
text = text.replace(/\u00F3/g, '\u0B85');
text = text.replace(/\u00F4/g, '\u0B86');
text = text.replace(/\u00F5/g, '\u0B87');
text = text.replace(/\u00F6/g, '\u0B88');
text = text.replace(/\u00F7/g, '\u0B89');
text = text.replace(/\u00F8/g, '\u0B8A');
text = text.replace(/\u00F9/g, '\u0B8E');
text = text.replace(/\u00FA/g, '\u0B8F');
text = text.replace(/\u00FB/g, '\u0B90');
text = text.replace(/\u00FC/g, '\u0B92');
text = text.replace(/\u00FD/g, '\u0B93');
text = text.replace(/\u00FC\u00B0/g, '\u0B94');
text = text.replace(/\u00A1/g, '\u0B95');
text = text.replace(/\u00A2/g, '\u0B99');
text = text.replace(/\u00A3/g, '\u0B9A');
text = text.replace(/\u00A4/g, '\u0B9E');
text = text.replace(/\u00A5/g, '\u0B9F');
text = text.replace(/\u00A6/g, '\u0BA3');
text = text.replace(/\u00A7/g, '\u0BA4');
text = text.replace(/\u00A8/g, '\u0BA8');
text = text.replace(/\u00A9/g, '\u0BAA');
text = text.replace(/\u00AA/g, '\u0BAE');
text = text.replace(/\u00AB/g, '\u0BAF');
text = text.replace(/\u00EB/g, '\u0BAF');
text = text.replace(/\u00AC/g, '\u0BB0');
text = text.replace(/\u00EC/g, '\u0BB0');
text = text.replace(/\u00AD/g, '\u0BB2');
text = text.replace(/\u00AE/g, '\u0BB5');
text = text.replace(/\u00AF/g, '\u0BB4');
text = text.replace(/\u00B0/g, '\u0BB3');
text = text.replace(/\u00B1/g, '\u0BB1');
text = text.replace(/\u00B2/g, '\u0BA9');
text = text.replace(/\u00B3/g, '\u0BB6');
text = text.replace(/\u00B4/g, '\u0BB7');
text = text.replace(/\u00B5/g, '\u0BB8');
text = text.replace(/\u00B8/g, '\u0BB9');
text = text.replace(/\u00B9/g, '\u0B9C');
text = text.replace(/\u00BA/g, '\u0B95\u0BCD\u0BB7');


text = text.replace(/\u00C1/g, '\u0B95\u0BC1');
text = text.replace(/\u00C2/g, '\u0B99\u0BC1');
text = text.replace(/\u00C3/g, '\u0B9A\u0BC1');
text = text.replace(/\u00B9\u00D3/g, '\u0B9C\u0BC1');

text = text.replace(/\u00C4\u00EF/g, '\u0B9E\u0BC2');
text = text.replace(/\u00C4/g, '\u0B9E\u0BC1');

text = text.replace(/\u00C5/g, '\u0B9F\u0BC1');

text = text.replace(/\u00C6\u00EF/g, '\u0BA3\u0BC2');
text = text.replace(/\u00C6/g, '\u0BA3\u0BC1');

text = text.replace(/\u00C7\u00EF/g, '\u0BA4\u0BC2');
text = text.replace(/\u00C7/g, '\u0BA4\u0BC1');

text = text.replace(/\u00C8\u00EF/g, '\u0BA8\u0BC2');
text = text.replace(/\u00C8/g, '\u0BA8\u0BC1');

text = text.replace(/\u00C9/g, '\u0BAA\u0BC1');
text = text.replace(/\u00CA/g, '\u0BAE\u0BC1');
text = text.replace(/\u00CB/g, '\u0BAF\u0BC1');
text = text.replace(/\u00CC/g, '\u0BB0\u0BC1');

text = text.replace(/\u00CD\u00EF/g, '\u0BB2\u0BC2');
text = text.replace(/\u00CD/g, '\u0BB2\u0BC1');

text = text.replace(/\u00CE/g, '\u0BB5\u0BC1');
text = text.replace(/\u00CF/g, '\u0BB4\u0BC1');
text = text.replace(/\u00D0/g, '\u0BB3\u0BC1');

text = text.replace(/\u00D1\u00EF/g, '\u0BB1\u0BC2');
text = text.replace(/\u00D1/g, '\u0BB1\u0BC1');

text = text.replace(/\u00D2\u00EF/g, '\u0BA9\u0BC2');
text = text.replace(/\u00D2/g, '\u0BA9\u0BC1');



text = text.replace(/(\u00BC)(.)(\u00B0)/g, '$2\u0BCC');
text = text.replace(/(\u00BC)(.)(\u00DF)/g, '$2\u0BCA');
text = text.replace(/(\u00BD)(.)(\u00DF)/g, '$2\u0BCB');
text = text.replace(/(.)(\u00DF)/g, '$1\u0BBE');
text = text.replace(/(\u00BC)(.)/g, '$2\u0BC6');
text = text.replace(/(\u00BD)(.)/g, '$2\u0BC7');
text = text.replace(/(\u00BE)(.)/g, '$2\u0BC8');
text = text.replace(/(\u00BF)(.)/g, '$2\u0BC8');
text = text.replace(/(.)(\u00D3)/g, '$1\u0BBF');
text = text.replace(/(.)(\u00D4)/g, '$1\u0BBF');
text = text.replace(/(.)(\u00D7)/g, '$1\u0BC0');
text = text.replace(/(.)(\u00D5)/g, '$1\u0BBF');
text = text.replace(/(.)(\u00D9)/g, '$1\u0BCD');
text = text.replace(/(.)(\u00DA)/g, '$1\u0BCD');
text = text.replace(/(.)(\u00DB)/g, '$1\u0BCD');
text = text.replace(/(.)(\u00DC)/g, '$1\u0BCD');
text = text.replace(/(.)(\u00DD)/g, '$1\u0BCD');
text = text.replace(/(.)(\u00DE)/g, '$1\u0BCD');
text = text.replace(/(.)(\u00E4)/g, '$1\u0BC2');
text = text.replace(/(.)(\u00ED)/g, '$1\u0BC2');
text = text.replace(/\u00E1/g, '\u0B95\u0BC2');
text = text.replace(/\u00E3/g, '\u0B9A\u0BC2');
text = text.replace(/\u00E5/g, '\u0B9F\u0BC2');
text = text.replace(/\u00E6/g, '\u0BA3\u0BBE');
text = text.replace(/\u00E7/g, '\u0BB1\u0BBE');
text = text.replace(/\u00E8/g, '\u0BA9\u0BBE');
text = text.replace(/\u00E9/g, '\u0BAA\u0BC2');
text = text.replace(/\u00F0/g, '\u0BB3\u0BC2');

		return text;

}
function convertSunFamilyTamilText(inText) {
	var text = inText;




		text = text.replace(/\u003d/g, "ஸ்ரீ");
		text = text.replace(/\u007E/g, '\u0B95\u0BCD\u0BB7'); //ksha
        
		text = text.replace(/\u007E\u007B/g, '\u0B95\u0BCD\u0BB7\u0bc1'); //kshu
		text = text.replace(/\u007E\u005F/g, '\u0B95\u0BCD\u0BB7\u0bc2'); //kshU
		text = text.replace(/\u0048/g, '\u0BB0\u0BCD'); //r kuril
		text = text.replace(/\u0068\u003B/g, '\u0BB0\u0BCD'); //r kuril written as thunai kal+mei pulli
		text = text.replace(/\u0068\u0070/g, '\u0BB0\u0BBF'); //ri kuril written as thunai kal+ kuril i
		text = text.replace(/\u0068\u0050/g, '\u0BB0\u0BC0'); //rI kuril written as thunai kal+ nedil I
        
		text = text.replace(/(\u003B\u003B)/g, '\u003B'); //replace many mei pullis to just one

		text = text.replace(/(\u003B)/g, '\u0BCD'); //mei pulli
		text = text.replace(/(.)(\u0070)/g, '$1\u0BBF'); //kuril i like ki
		text = text.replace(/(.)(\u0050)/g, '$1\u0BC0'); //nedil I like kI
		text = text.replace(/(.)(\u0068)/g, '$1\u0BBE'); //mei pulli

		text = text.replace(/(\u006E)(.)(\u0068)/g, '$2\u0BCA'); //kuril o like k0
		text = text.replace(/(\u004E)(.)(u0068)/g, '$2\u0BCB'); //nedil O like kO
		text = text.replace(/(\u006E)(.)(\u0073)/g, '$2\u0BCC'); // au like kau

		text = text.replace(/(\u006E)(.)/g, '$2\u0BC6'); //kuril e like ke
		text = text.replace(/(\u004E)(.)/g, '$2\u0BC7'); //nedil E like kE
		text = text.replace(/(\u0069)(.)/g, '$2\u0BC8'); // ai like kai

		text = text.replace(/u007B/g, '\u0BC1'); //kuril u like ku
		text = text.replace(/u005F/g, '\u0BC2'); //nedil U like kU




		text = text.replace(/\u0062/g, '\u0b9F\u0bbf'); //ti
		text = text.replace(/\u0042/g, '\u0b9F\u0bc0'); //tI
        
		text = text.replace(/\u007A\u0021/g, '\u0BA3\u0BCD'); //
        
//uyirmei ezhutthukkal
		text = text.replace(/\u0066/g, '\u0B95'); //
		text = text.replace(/\u0071/g, '\u0B99'); //
		text = text.replace(/\u0072/g, '\u0B9A'); //
		text = text.replace(/\u005B/g, '\u0B9C'); //
		text = text.replace(/\u0051/g, '\u0B9E'); //
		text = text.replace(/\u006C/g, '\u0B9F'); //
		text = text.replace(/\u007A/g, '\u0BA3'); //
		text = text.replace(/\u006A/g, '\u0BA4'); //
		text = text.replace(/\u0065/g, '\u0BA8'); //
		text = text.replace(/\u0064/g, '\u0BA9'); //
		text = text.replace(/\u0067/g, '\u0BAA'); //
		text = text.replace(/\u006B/g, '\u0BAE'); //
		text = text.replace(/\u0061/g, '\u0BAF'); //
		text = text.replace(/\u0075/g, '\u0BB0'); //
		text = text.replace(/\u0077/g, '\u0BB1'); //
		text = text.replace(/\u0079/g, '\u0BB2'); //
		text = text.replace(/\u0073/g, '\u0BB3'); //
		text = text.replace(/\u006F/g, '\u0BB4'); //
		text = text.replace(/\u0074/g, '\u0BB5'); //
		text = text.replace(/\u005C/g, '\u0BB7'); //ஷ
		text = text.replace(/\u005D/g, '\u0BB8'); //ஸ
		text = text.replace(/\u0060/g, '\u0BB9'); //ஹ

        
//uyirmei nedil  U ezhutthukkal
		text = text.replace(/\u0024/gi, '\u0b95\u0bc2'); //
		text = text.replace(/\u0023/gi, '\u0b9A\u0bc2'); //
		text = text.replace(/\u005A\u005F/gi, '\u0b9C\u0bc2'); //
		text = text.replace(/\u005E/gi, '\u0b9F\u0bc2'); //
		text = text.replace(/\u005A\u007D/gi, '\u0bA3\u0bc2'); //
		text = text.replace(/\u004A\u007D/gi, '\u0bA4\u0bc2'); //
		text = text.replace(/\u0045\u007D/gi, '\u0bA8\u0bc2'); //
		text = text.replace(/\u0044\u007D/gi, '\u0bA9\u0bc2'); //
		text = text.replace(/\u0047\u002B/gi, '\u0bAA\u0bc2'); //
		text = text.replace(/\u0025/gi, '\u0bAE\u0bc2'); //
		text = text.replace(/\u0041\u002B/gi, '\u0bAF\u0bc2'); //
		text = text.replace(/\u0026/gi, '\u0bb0\u0bc2'); //
		text = text.replace(/\u0057\u007D/gi, '\u0bb1\u0bc2'); //
		text = text.replace(/\u0059\u007D/gi, '\u0bb2\u0bc2'); //
		text = text.replace(/\u0040/gi, '\u0bb3\u0bc2'); //
		text = text.replace(/\u002A/gi, '\u0bb4\u0bc2'); //
		text = text.replace(/\u0054\u002B/gi, '\u0bb5\u0bc2'); //
		text = text.replace(/\u005C\u005F/gi, '\u0bb7\u0bc2'); //ஷ
		text = text.replace(/\u005D\u005F/gi, '\u0bb8\u0bc2'); //ஸ
		text = text.replace(/\u0060\u005F/gi, '\u0bb9\u0bc2'); //ஹ
        
		text = text.replace(/(.)(\u002B)/gi, '$1\u0bc2'); //

//uyirmei kuril u ezhutthukkal
		text = text.replace(/\u0046/gi, '\u0b95\u0bc1'); //

        text = text.replace(/\u0052/gi, '\u0b9A\u0bc1'); //
		text = text.replace(/\u005A\u007B/gi, '\u0b9C\u0bc1'); //

		text = text.replace(/\u004C/gi, '\u0b9F\u0bc1'); //
		text = text.replace(/\u005A/gi, '\u0bA3\u0bc1'); //
		text = text.replace(/\u004A/gi, '\u0bA4\u0bc1'); //
		text = text.replace(/\u0045/gi, '\u0bA8\u0bc1'); //
		text = text.replace(/\u0044/gi, '\u0bA9\u0bc1'); //
		text = text.replace(/\u0047/gi, '\u0bAA\u0bc1'); //
		text = text.replace(/\u004B/gi, '\u0bAE\u0bc1'); //
		text = text.replace(/\u0041/gi, '\u0bAF\u0bc1'); //
		text = text.replace(/\u0055/gi, '\u0bb0\u0bc1'); //
		text = text.replace(/\u0057/gi, '\u0bb1\u0bc1'); //
		text = text.replace(/\u0059/gi, '\u0bb2\u0bc1'); //
		text = text.replace(/\u0053/gi, '\u0bb3\u0bc1'); //
		text = text.replace(/\u004F/gi, '\u0bb4\u0bc1'); //
		text = text.replace(/\u0054/gi, '\u0bb5\u0bc1'); //
		text = text.replace(/\u005C\u007B/gi, '\u0bb7\u0bc1'); //ஷ
		text = text.replace(/\u005D\u007B/gi, '\u0bb8\u0bc1'); //ஸ
		text = text.replace(/\u0060\u007B/gi, '\u0bb9\u0bc1'); //ஹ
        

// uyir ezhutthukkal
		text = text.replace(/\u006D/g, '\u0B85'); //a
		text = text.replace(/\u004D/g, '\u0B86'); //A

		text = text.replace(/\u002C/g, '\u0B87'); //i
		text = text.replace(/\u003C/g, '\u0B88'); //I
        
		text = text.replace(/\u0063/g, '\u0B89'); //u
		text = text.replace(/\u0043/g, '\u0B8A'); //U
		text = text.replace(/\u0076/g, '\u0B8E'); //e
		text = text.replace(/\u0056/g, '\u0B8F'); //E
		text = text.replace(/\u0049/g, '\u0B90'); //ai
		text = text.replace(/\u0078/g, '\u0B92'); //o
		text = text.replace(/\u0058/g, '\u0B93'); //O
		text = text.replace(/\u0078\u0073/g, '\u0B94'); //au
		text = text.replace(/\u00E1/g, '\u0B83'); //ak ஃ
        

        text = text.replace(/\u003E/gi, '\u002C'); // leave this at the end..... other wise it gets over written by tamil char இ
        text = text.replace(/\u003F/gi, '\u003F'); //
        text = text.replace(/([\u0BCD]){2,}/gi, '$1'); // detect duplicate characters
        //text = text.replace(/\b(\w+)\s+\1\b/gi, '$1'); // find repeated words
// tamil numbers
		text = text.replace(/\u007E/g, '\u0B95'); //க்ஷ
		text = text.replace(/\u00C9/g, '\u0BE7'); //௧
		text = text.replace(/\u00CA/g, '\u0BE8'); //௨
		text = text.replace(/\u00CB/g, '\u0BE9'); //௩
		text = text.replace(/\u00CC/g, '\u0BEA'); //௪
		text = text.replace(/\u00CD/g, '\u0BEB'); //௫
		text = text.replace(/\u00CE/g, '\u0BEC'); //௬
		text = text.replace(/\u00CF/g, '\u0BED'); //௭
		text = text.replace(/\u00D0/g, '\u0BEE'); //௮
		text = text.replace(/\u00D1/g, '\u0BEF'); //௯
		text = text.replace(/\u00D2/g, '\u0BF0'); //௰
		text = text.replace(/\u00E0/g, '\u0BF3'); //௳

		return text;

}

function convertShree_TamEX_0803Text(inText) {
    var text = inText;


    text = text.replace(/\uEAAF/g, "ஸ்ரீ");
    text = text.replace(/\uEA04/g, '\u0B83');
    text = text.replace(/\uEA05/g, '\u0B85');
    text = text.replace(/\uEA06/g, '\u0B86');
    text = text.replace(/\uEA07/g, '\u0B87');
    text = text.replace(/\uEA08/g, '\u0B88');
    text = text.replace(/\uEA09/g, '\u0B89');
    text = text.replace(/\uEA0A/g, '\u0B8A');
    text = text.replace(/\uEA0B/g, '\u0B8E');
    text = text.replace(/\uEA0C/g, '\u0B8F');
    text = text.replace(/\uEA0D/g, '\u0B90');
    text = text.replace(/\uEA0E/g, '\u0B92');
    text = text.replace(/\uEA0F/g, '\u0B93');
    text = text.replace(/\uEA10/g, '\u0B94');
    text = text.replace(/\uEA11/g, '\u0B95');
    text = text.replace(/\uEA12/g, '\u0B99');
    text = text.replace(/\uEA13/g, '\u0B9A');
    text = text.replace(/\uEA14/g, '\u0B9C');
    text = text.replace(/\uEA15/g, '\u0B9E');
    text = text.replace(/\uEA16/g, '\u0B9F');
    text = text.replace(/\uEA17/g, '\u0BA3');
    text = text.replace(/\uEA18/g, '\u0BA4');
    text = text.replace(/\uEA19/g, '\u0BA8');
    text = text.replace(/\uEA1A/g, '\u0BA9');
    text = text.replace(/\uEA1B/g, '\u0BAA');
    text = text.replace(/\uEA1C/g, '\u0BAE');
    text = text.replace(/\uEA1D/g, '\u0BAF');
    text = text.replace(/\uEA1E/g, '\u0BB0');
    text = text.replace(/\uEA1F/g, '\u0BB1');
    text = text.replace(/\uEA20/g, '\u0BB2');

    text = text.replace(/(\uEA2C)(.)(\uEA21)/g, '$2\u0BCC');
    text = text.replace(/(.)([\uEA2A\uEAC7])/g, '$1\u0BC1');
    text = text.replace(/(.)([\uEAC8\uEA2B])/g, '$1\u0BC2');

    text = text.replace(/\uEA21/g, '\u0BB3');
    text = text.replace(/\uEA22/g, '\u0BB4');
    text = text.replace(/\uEA23/g, '\u0BB5');
    text = text.replace(/\uEA24/g, '\u0BB7');
    text = text.replace(/\uEA25/g, '\u0BB8');
    text = text.replace(/\uEA26/g, '\u0BB9');

    text = text.replace(/(\uEA2C)(.)(\uEA27)/g, '$2\u0BCA');
    text = text.replace(/(\uEA2D)(.)(\uEA27)/g, '$2\u0BCB');
    text = text.replace(/(.)(\uEA27)/g, '$1\u0BBE');
    text = text.replace(/\uEA27/g, '\u0BBE');
    text = text.replace(/(\uEA2C)(.)/g, '$2\u0BC6');
    text = text.replace(/(\uEA2D)(.)/g, '$2\u0BC7');
    text = text.replace(/(\uEA2E)(.)/g, '$2\u0BC8');


    text = text.replace(/\uEAB0/g, '\u0B95\u0BCD');
    text = text.replace(/\uEAB1/g, '\u0B99\u0BCD');
    text = text.replace(/\uEAB2/g, '\u0B9A\u0BCD');
    text = text.replace(/\uEAB3/g, '\u0B9C\u0BCD');
    text = text.replace(/\uEAB4/g, '\u0B9E\u0BCD');
    text = text.replace(/\uEAB5/g, '\u0B9F\u0BCD');
    text = text.replace(/\uEAB6/g, '\u0BA3\u0BCD');
    text = text.replace(/\uEAB7/g, '\u0BA4\u0BCD');
    text = text.replace(/\uEAB8/g, '\u0BA8\u0BCD');
    text = text.replace(/\uEAB9/g, '\u0BA9\u0BCD');
    text = text.replace(/\uEABA/g, '\u0BAA\u0BCD');
    text = text.replace(/\uEABB/g, '\u0BAE\u0BCD');
    text = text.replace(/\uEABC/g, '\u0BAF\u0BCD');
    text = text.replace(/\uEABD/g, '\u0BB0\u0BCD');
    text = text.replace(/\uEABE/g, '\u0BB1\u0BCD');
    text = text.replace(/\uEABF/g, '\u0BB2\u0BCD');
    text = text.replace(/\uEAC0/g, '\u0BB3\u0BCD');
    text = text.replace(/\uEAC1/g, '\u0BB4\u0BCD');
    text = text.replace(/\uEAC2/g, '\u0BB5\u0BCD');
    text = text.replace(/\uEAC3/g, '\u0BB7\u0BCD');
    text = text.replace(/\uEAC4/g, '\u0BB8\u0BCD');
    text = text.replace(/\uEAC5/g, '\u0BB9\u0BCD');

    text = text.replace(/\uEA5A/g, '\u0B95\u0BBF');
    text = text.replace(/\uEA5B/g, '\u0B99\u0BBF');
    text = text.replace(/\uEA5C/g, '\u0B9A\u0BBF');
    text = text.replace(/\uEA5D/g, '\u0B9C\u0BBF');
    text = text.replace(/\uEA5E/g, '\u0B9E\u0BBF');
    text = text.replace(/\uEA5F/g, '\u0B9F\u0BBF');
    text = text.replace(/\uEA60/g, '\u0BA3\u0BBF');
    text = text.replace(/\uEA61/g, '\u0BA4\u0BBF');
    text = text.replace(/\uEA62/g, '\u0BA8\u0BBF');
    text = text.replace(/\uEA63/g, '\u0BA9\u0BBF');
    text = text.replace(/\uEA64/g, '\u0BAA\u0BBF');
    text = text.replace(/\uEA65/g, '\u0BAE\u0BBF');
    text = text.replace(/\uEA66/g, '\u0BAF\u0BBF');
    text = text.replace(/\uEA67/g, '\u0BB0\u0BBF');
    text = text.replace(/\uEA68/g, '\u0BB1\u0BBF');
    text = text.replace(/\uEA69/g, '\u0BB2\u0BBF');
    text = text.replace(/\uEA6A/g, '\u0BB3\u0BBF');
    text = text.replace(/\uEA6B/g, '\u0BB4\u0BBF');
    text = text.replace(/\uEA6C/g, '\u0BB5\u0BBF');
    text = text.replace(/\uEA6D/g, '\u0BB7\u0BBF');
    text = text.replace(/\uEA6E/g, '\u0BB8\u0BBF');
    text = text.replace(/\uEA6F/g, '\u0BB9\u0BBF');

    text = text.replace(/\uEA70/g, '\u0B95\u0BC0');
    text = text.replace(/\uEA71/g, '\u0B99\u0BC0');
    text = text.replace(/\uEA72/g, '\u0B9A\u0BC0');
    text = text.replace(/\uEA73/g, '\u0B9C\u0BC0');
    text = text.replace(/\uEA74/g, '\u0B9E\u0BC0');
    text = text.replace(/\uEA75/g, '\u0B9F\u0BC0');
    text = text.replace(/\uEA76/g, '\u0BA3\u0BC0');
    text = text.replace(/\uEA77/g, '\u0BA4\u0BC0');
    text = text.replace(/\uEA78/g, '\u0BA8\u0BC0');
    text = text.replace(/\uEA79/g, '\u0BA9\u0BC0');
    text = text.replace(/\uEA7A/g, '\u0BAA\u0BC0');
    text = text.replace(/\uEA7B/g, '\u0BAE\u0BC0');
    text = text.replace(/\uEA7C/g, '\u0BAF\u0BC0');
    text = text.replace(/\uEA7D/g, '\u0BB0\u0BC0');
    text = text.replace(/\uEA7E/g, '\u0BB1\u0BC0');
    text = text.replace(/\uEA7F/g, '\u0BB2\u0BC0');
    text = text.replace(/\uEA80/g, '\u0BB3\u0BC0');
    text = text.replace(/\uEA81/g, '\u0BB4\u0BC0');
    text = text.replace(/\uEA82/g, '\u0BB5\u0BC0');
    text = text.replace(/\uEA83/g, '\u0BB7\u0BC0');
    text = text.replace(/\uEA84/g, '\u0BB8\u0BC0');
    text = text.replace(/\uEA85/g, '\u0BB9\u0BC0');

    text = text.replace(/\uEA86/g, '\u0B95\u0BC1');
    text = text.replace(/\uEA87/g, '\u0B99\u0BC1');
    text = text.replace(/\uEA88/g, '\u0B9A\u0BC1');
    text = text.replace(/\uEA89/g, '\u0B9C\u0BC1');
    text = text.replace(/\uEA8A/g, '\u0B9E\u0BC1');
    text = text.replace(/\uEA8B/g, '\u0B9F\u0BC1');
    text = text.replace(/\uEA8C/g, '\u0BA3\u0BC1');
    text = text.replace(/\uEA8D/g, '\u0BA4\u0BC1');
    text = text.replace(/\uEA8E/g, '\u0BA8\u0BC1');
    text = text.replace(/\uEA8F/g, '\u0BA9\u0BC1');
    text = text.replace(/\uEA90/g, '\u0BAA\u0BC1');
    text = text.replace(/\uEA91/g, '\u0BAE\u0BC1');
    text = text.replace(/\uEA92/g, '\u0BAF\u0BC1');
    text = text.replace(/\uEA93/g, '\u0BB0\u0BC1');
    text = text.replace(/\uEA94/g, '\u0BB1\u0BC1');
    text = text.replace(/\uEA95/g, '\u0BB2\u0BC1');
    text = text.replace(/\uEA96/g, '\u0BB3\u0BC1');
    text = text.replace(/\uEA97/g, '\u0BB4\u0BC1');
    text = text.replace(/\uEA98/g, '\u0BB5\u0BC1');

    text = text.replace(/\uEA99/g, '\u0B95\u0BC2');
    text = text.replace(/\uEA9A/g, '\u0B99\u0BC2');
    text = text.replace(/\uEA9B/g, '\u0B9A\u0BC2');
    text = text.replace(/\uEA9D/g, '\u0B9E\u0BC2');
    text = text.replace(/\uEA9E/g, '\u0B9F\u0BC2');
    text = text.replace(/\uEA9F/g, '\u0BA3\u0BC2');
    text = text.replace(/\uEAA0/g, '\u0BA4\u0BC2');
    text = text.replace(/\uEAA1/g, '\u0BA8\u0BC2');
    text = text.replace(/\uEAA2/g, '\u0BA9\u0BC2');
    text = text.replace(/\uEAA3/g, '\u0BAA\u0BC2');
    text = text.replace(/\uEAA4/g, '\u0BAE\u0BC2');
    text = text.replace(/\uEAA5/g, '\u0BAF\u0BC2');
    text = text.replace(/\uEAA6/g, '\u0BB0\u0BC2');
    text = text.replace(/\uEAA7/g, '\u0BB1\u0BC2');
    text = text.replace(/\uEAA8/g, '\u0BB2\u0BC2');
    text = text.replace(/\uEAA9/g, '\u0BB3\u0BC2');
    text = text.replace(/\uEAAA/g, '\u0BB4\u0BC2');
    text = text.replace(/\uEAAB/g, '\u0BB5\u0BC2');

    text = text.replace(/\uEAC6/g, '\u0B95\u0BCD\u0BB7\u0BCD');
    text = text.replace(/\uEAAC/g, '\u0B95\u0BCD\u0BB7');
    text = text.replace(/\uEAAD/g, '\u0B95\u0BCD\u0BB7\u0BBF');
    text = text.replace(/\uEAAE/g, '\u0B95\u0BCD\u0BB7\u0BC0');
    text = text.replace(/(.)g([\u0BCC\u0BC0\u0BC1\u0BCA\u0BCB\u0BBE])/g, "$1\$2\uE181");
    
    return text;
}

function convertFromBalaram (text)
{
    text = handleBalaramFontConvertion (text, true); // bConvertToUnicode is false means, convertFromUnicode
    return text;
};

// This will parse a delimited string into an array of
// arrays. The default delimiter is the comma, but this
// can be overriden in the second argument.
function CSVToArray( strData, strDelimiter ){
    // Check to see if the delimiter is defined. If not,
    // then default to comma.
    strDelimiter = (strDelimiter || ",");
    // Create a regular expression to parse the CSV values.
    var objPattern = new RegExp(
        (
            // Delimiters.
            "(\\" + strDelimiter + "|\\r?\\n|\\r|^)" +
            // Quoted fields.
            "(?:\"([^\"]*(?:\"\"[^\"]*)*)\"|" +
            // Standard fields.
            "([^\"\\" + strDelimiter + "\\r\\n]*))"
        ),
        "gi"
        );
    // Create an array to hold our data. Give the array
    // a default empty first row.
    var arrData = [[]];
    // Create an array to hold our individual pattern
    // matching groups.
    var arrMatches = null;
    var strMatchedValue = "";
    // Keep looping over the regular expression matches
    // until we can no longer find a match.
    while (arrMatches = objPattern.exec( strData )){
        // Get the delimiter that was found.
        var strMatchedDelimiter = arrMatches[ 0 ];
        // Check to see if the given delimiter has a length
        // (is not the start of string) and if it matches
        // field delimiter. If id does not, then we know
        // that this delimiter is a row delimiter.
        alert (arrMatches[0]+"_"+objPattern.lastIndex);
        if (
            strMatchedDelimiter.length &&
            (strMatchedDelimiter != strDelimiter)
            ){
            // Since we have reached a new row of data,
            // add an empty row to our data array.
            arrData.push( [] );
            strMatchedValue = arrMatches[ 0 ];
        }
        // Now that we have our delimiter out of the way,
        // let's check to see which kind of value we
        // captured (quoted or unquoted).
        if (arrMatches[ 1 ]){
            // We found a quoted value. When we capture
            // this value, unescape any double quotes.
            strMatchedValue = arrMatches[ 1 ].replace(
                new RegExp( "\"\"", "g" ),
                "\""
                );
            alert ("_"+arrMatches[1]+"_"+strMatchedValue);
        } else if (arrMatches[ 2 ]){
            // We found a non-quoted value.
            strMatchedValue = arrMatches[ 2 ];
            alert ("_"+arrMatches[2]+"_"+strMatchedValue);
        }
        // Now that we have our value string, let's add
        // it to the data array.
        arrData[ arrData.length - 1 ].push( strMatchedValue );
    }
    // Return the parsed data.
    return( arrData );
}
function parseCSV(str, delimit) {
    var arr = [];
    var quote = false;  // true means we're inside a quoted field


    // iterate over each character, keep track of current row and column (of the returned array)
    for (var row = col = c = 0; c < str.length; c++) {
        var cc = str[c], nc = str[c+1];        // current character, next character
        arr[row] = arr[row] || [];             // create a new row if necessary
        arr[row][col] = arr[row][col] || '';   // create a new column (start with empty string) if necessary

        // If the current character is a quotation mark, and we're inside a
        // quoted field, and the next character is also a quotation mark,
        // add a quotation mark to the current column and skip the next character
        if (cc == '"' && quote && nc == '"') { arr[row][col] += cc; ++c; continue; }  

        // If it's just one quotation mark, begin/end quoted field
        if (cc == '"') { quote = !quote; continue; }

        // If it's a comma and we're not in a quoted field, move on to the next column
        if (cc == delimit && !quote) { ++col; continue; }

        // If it's a newline (CRLF) and we're not in a quoted field, skip the next character
        // and move on to the next row and move to column 0 of that new row
        if (cc == '\r' && nc == '\n' && !quote) { ++row; col = 0; ++c; continue; }

        // If it's a newline (LF or CR) and we're not in a quoted field,
        // move on to the next row and move to column 0 of that new row
        if (cc == '\n' && !quote) { ++row; col = 0; continue; }
        if (cc == '\r' && !quote) { ++row; col = 0; continue; }

        // Otherwise, append the current character to the current column
        arr[row][col] += cc;
    }
    return arr;
}
function getDictionaryHeaderObject ()
{
    var dictionaryData = {
        dictionaryHeaderFields:{
        sNo:[-1, "S.no",],
        prefix:[-1, "prefix",], 
        suffix:[-1, "suffix",], 
        findKey:[-1, "find key",], 
        replaceKey:[-1, "replace key",], 
        correctWay:[-1, "Correct way",], 
        wrongWay:[-1, "Wrong way",], 
        fullWord: [-1, "Full word",], 
        engEq:[-1, "English equivalant",], 
        comments:[-1, "comments",], 
        action:[-1, "Action item",], 
        wordType:[-1, "Word type",], 
        },
        arrData:[[]],
        bHeaderOK:false,
    };
    return dictionaryData;
}
function checkHeader (dictionaryHeaderFields)
{
    var bRes = true, strRes = "expected Title- ";
    if (-1 == dictionaryHeaderFields.sNo[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += dictionaryHeaderFields.sNo[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == dictionaryHeaderFields.prefix[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += dictionaryHeaderFields.prefix[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == dictionaryHeaderFields.suffix[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += dictionaryHeaderFields.suffix[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == dictionaryHeaderFields.findKey[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += dictionaryHeaderFields.findKey[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == dictionaryHeaderFields.replaceKey[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += dictionaryHeaderFields.replaceKey[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == dictionaryHeaderFields.correctWay[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += dictionaryHeaderFields.correctWay[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == dictionaryHeaderFields.wrongWay[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += dictionaryHeaderFields.wrongWay[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == dictionaryHeaderFields.fullWord[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += dictionaryHeaderFields.fullWord[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == dictionaryHeaderFields.engEq[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += dictionaryHeaderFields.engEq[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == dictionaryHeaderFields.comments[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += dictionaryHeaderFields.comments[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == dictionaryHeaderFields.action[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += dictionaryHeaderFields.action[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == dictionaryHeaderFields.wordType[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += dictionaryHeaderFields.wordType[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (bRes == false) alert ("Missing or corrupt Header \r"+ strRes +"\r Check and Correct header. Process will be terminated!");

    return bRes;
    
}

function loadAndVerifyDictionaryHeader (csvFileContents)
{
    var i =0, j = 0, headerCheckComplete = false;
    var dictionaryData = getDictionaryHeaderObject ();
    dictionaryData.arrData = parseCSV (csvFileContents, ",");
    for (i = 0; i< dictionaryData.arrData.length; i++)
    {
        for (j =0; j< dictionaryData.arrData[i].length; j++)
        {
            // the first row is expected to be the header, so check the headings and update the header info, especially the index
            // Even if the field columns in excel are moved or re arranged, this code will work fine as long as the headings are un altered
            dictionaryData.arrData[i][j] = dictionaryData.arrData[i][j].replace(/^[\s\uFEFF\xA0]+|[\s\uFEFF\xA0]+$/g, ''); //trim functionality
            if (i == CSV_HEADER_ROW_INDEX ) {
                if (dictionaryData.arrData[i][j] == dictionaryData.dictionaryHeaderFields.sNo[CSV_HEADER_FIELD_LABEL_POS]) dictionaryData.dictionaryHeaderFields.sNo[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (dictionaryData.arrData[i][j] == dictionaryData.dictionaryHeaderFields.prefix[CSV_HEADER_FIELD_LABEL_POS]) dictionaryData.dictionaryHeaderFields.prefix[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (dictionaryData.arrData[i][j] == dictionaryData.dictionaryHeaderFields.suffix[CSV_HEADER_FIELD_LABEL_POS]) dictionaryData.dictionaryHeaderFields.suffix[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (dictionaryData.arrData[i][j] == dictionaryData.dictionaryHeaderFields.findKey[CSV_HEADER_FIELD_LABEL_POS]) dictionaryData.dictionaryHeaderFields.findKey[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (dictionaryData.arrData[i][j] == dictionaryData.dictionaryHeaderFields.replaceKey[CSV_HEADER_FIELD_LABEL_POS]) dictionaryData.dictionaryHeaderFields.replaceKey[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (dictionaryData.arrData[i][j] == dictionaryData.dictionaryHeaderFields.correctWay[CSV_HEADER_FIELD_LABEL_POS]) dictionaryData.dictionaryHeaderFields.correctWay[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (dictionaryData.arrData[i][j] == dictionaryData.dictionaryHeaderFields.wrongWay[CSV_HEADER_FIELD_LABEL_POS]) dictionaryData.dictionaryHeaderFields.wrongWay[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (dictionaryData.arrData[i][j] == dictionaryData.dictionaryHeaderFields.fullWord[CSV_HEADER_FIELD_LABEL_POS]) dictionaryData.dictionaryHeaderFields.fullWord[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (dictionaryData.arrData[i][j] == dictionaryData.dictionaryHeaderFields.engEq[CSV_HEADER_FIELD_LABEL_POS]) dictionaryData.dictionaryHeaderFields.engEq[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (dictionaryData.arrData[i][j] == dictionaryData.dictionaryHeaderFields.comments[CSV_HEADER_FIELD_LABEL_POS]) dictionaryData.dictionaryHeaderFields.comments[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (dictionaryData.arrData[i][j] == dictionaryData.dictionaryHeaderFields.action[CSV_HEADER_FIELD_LABEL_POS]) dictionaryData.dictionaryHeaderFields.action[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (dictionaryData.arrData[i][j] == dictionaryData.dictionaryHeaderFields.wordType[CSV_HEADER_FIELD_LABEL_POS]) dictionaryData.dictionaryHeaderFields.wordType[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                }
            //if (i == CSV_HEADER_ROW_INDEX && prompt(dictionaryData.arrData[i][j]+"="+dictionaryData.dictionaryHeaderFields.sNo[CSV_HEADER_FIELD_LABEL_POS], "Ok to proceed. Cancel to exit!", "Confirm") == null) return;
        }
        if (headerCheckComplete == false) {if ((dictionaryData.bHeaderOK = checkHeader(dictionaryData.dictionaryHeaderFields)) == false) return dictionaryData; headerCheckComplete = true;break;}
    }
    return dictionaryData;
}
function checkAgainstDictionary (contentsToCheckStr, csvFileContents, nSelFunctionID)
{
    var resultObj = {
            report:"Dictionary Check Failed! .CSV contents invalid or corrupt or invalid function requested!",
            contentsToCheckStr:"",
            };
    var report="";
    var  i=0, j=0, k=0, newPos = -1, findWhatStr = "", changeToStr = "", actionStr = "", action = 0, tempStr="", promptStr = "";

    if (nSelFunctionID > 2 || nSelFunctionID <0) {alert ("Function Not Implemented.....ID "+nSelFunctionID );return resultObj;}
    var dictObj = loadAndVerifyDictionaryHeader (csvFileContents);
    var arrData = dictObj.arrData;
    var dictionaryHeaderFields = dictObj.dictionaryHeaderFields;
    
    if (dictObj.bHeaderOK == false || arrData == null) {alert ("Failed.....Dict");return resultObj;}
    //start from the second row
    for (i = 1; i< arrData.length; i++)
    {
        findWhatStr = arrData[i][dictionaryHeaderFields.wrongWay[CSV_HEADER_FIELD_LOCATOR_POS]];
        if (findWhatStr == "") continue;
        //findWhatStr = findWhatStr.replace(/([\(\[\+\.\*\?\]\)\<\>\=])/gi,"\\$1"); // escape all special characters
        changeToStr = arrData[i][dictionaryHeaderFields.correctWay[CSV_HEADER_FIELD_LOCATOR_POS]];
        actionStr = arrData[i][dictionaryHeaderFields.action[CSV_HEADER_FIELD_LOCATOR_POS]];
        if (actionStr == "Prompt")
        {
            nSelFunctionID==1? action=1:action = 0; // The user can override the .csv value with Override All Prompts function from dialog box. True will cause auto exec
            }else if (actionStr == "Doubt" || actionStr == "Don't ask")
                {
                    nSelFunctionID==2? action=0:action = 1; // The user can override the .csv value with Override Do Not Ask flag from dialog box. True will force prompts
                    }
            if (action == 0) 
            {
                promptStr = "Replace? instance No. "+String (i) +" "+ findWhatStr +" with "+changeToStr+"\r" ;
                report+= promptStr;
                tempStr = prompt (promptStr +"\r Edit ChangeStr and click Ok to continue. Cancel to quit", changeToStr, "Confirm");
                if (tempStr == null) {report+= "Process terminated by user!\r At location - Instance No. - "+String(j);alert (report); break;}
                changeToStr = tempStr;
                }
            var regEx = new RegExp(findWhatStr, "ig");
            regEx.lastIndex = 0;
            
            contentsToCheckStr = contentsToCheckStr.replace (regEx, changeToStr);
            //contentsToCheckStr = contentsToCheckStr.replace (findWhatStr, changeToStr);
        }
    resultObj.contentsToCheckStr = contentsToCheckStr;
    resultObj.report = report;
    return resultObj;
}


function getTamilGuideHeaderObject ()
{
    var TamilGuideData = {
        TamilGuideHeaderFields:{
            // In the following array 0th location is field locator Index
            // In the following arrays 1st loc is field header label
            // In the following arrays 2nd loc is field default value
            ver:[-1,"ver","NoPrompt",],
            action:[-1,"Action","NoPrompt",],
            ReplaceWord:[-1, "ReplaceWord","",],
            GrepPrefix_find:[-1, "GrepPrefix_find","",],
            GrepSuffix_find:[-1, "GrepSuffix_find","",],
            GrepPrefix_replace:[-1, "GrepPrefix_replace","",],
            GrepSuffix_replace:[-1, "GrepSuffix_replace","",],
            IgnoreGrep_FindPrefix:[-1, "IgnoreGrep_FindPrefix","TRUE",],
            IgnoreGrep_FindSuffix:[-1, "IgnoreGrep_FindSuffix","TRUE",],
            IgnoreGrep_ReplacePrefix:[-1, "IgnoreGrep_ReplacePrefix","TRUE",],
            IgnoreGrep_ReplaceSuffix:[-1, "IgnoreGrep_ReplaceSuffix","TRUE",],
            tooltipText_Desc:[-1, "tooltipText_Desc","",],
            find_1:[-1, "find_1","",],	
            find_2:[-1, "find_2","",],	
            find_3:[-1, "find_3","",],
            find_headerStr:"find_",
            findArr:[[]],
        },
        verNo:-1,
        verSep:"#",
        arrData:[[]],
        bHeaderOK:false,
        ReInitialize: function (verNum, thisVal) {
            var i = j = 0;
            var newGuideObj = thisVal;
            while (newGuideObj.arrData!=null && newGuideObj.arrData.length > 1) {
                newGuideObj.arrData.pop();
            }
          
            newGuideObj.verNo = verNum;
            newGuideObj.arrData[CSV_HEADER_ROW_INDEX][0]= newGuideObj.TamilGuideHeaderFields.ver[CSV_HEADER_FIELD_LABEL_POS]+"="+String(newGuideObj.verNo)+String(newGuideObj.verSep)+newGuideObj.TamilGuideHeaderFields.action[CSV_HEADER_FIELD_LABEL_POS];
            newGuideObj.arrData[CSV_HEADER_ROW_INDEX][1]= newGuideObj.TamilGuideHeaderFields.ReplaceWord[CSV_HEADER_FIELD_LABEL_POS];
            newGuideObj.arrData[CSV_HEADER_ROW_INDEX][2]= newGuideObj.TamilGuideHeaderFields.GrepPrefix_find[CSV_HEADER_FIELD_LABEL_POS];
            newGuideObj.arrData[CSV_HEADER_ROW_INDEX][3]= newGuideObj.TamilGuideHeaderFields.GrepSuffix_find[CSV_HEADER_FIELD_LABEL_POS];
            newGuideObj.arrData[CSV_HEADER_ROW_INDEX][4]= newGuideObj.TamilGuideHeaderFields.GrepPrefix_replace[CSV_HEADER_FIELD_LABEL_POS];
            newGuideObj.arrData[CSV_HEADER_ROW_INDEX][5]= newGuideObj.TamilGuideHeaderFields.GrepSuffix_replace[CSV_HEADER_FIELD_LABEL_POS];
            newGuideObj.arrData[CSV_HEADER_ROW_INDEX][6]= newGuideObj.TamilGuideHeaderFields.IgnoreGrep_FindPrefix[CSV_HEADER_FIELD_LABEL_POS];
            newGuideObj.arrData[CSV_HEADER_ROW_INDEX][7]= newGuideObj.TamilGuideHeaderFields.IgnoreGrep_FindSuffix[CSV_HEADER_FIELD_LABEL_POS];
            newGuideObj.arrData[CSV_HEADER_ROW_INDEX][8]= newGuideObj.TamilGuideHeaderFields.IgnoreGrep_ReplacePrefix[CSV_HEADER_FIELD_LABEL_POS];
            newGuideObj.arrData[CSV_HEADER_ROW_INDEX][9]= newGuideObj.TamilGuideHeaderFields.IgnoreGrep_ReplaceSuffix[CSV_HEADER_FIELD_LABEL_POS];
            newGuideObj.arrData[CSV_HEADER_ROW_INDEX][10]= newGuideObj.TamilGuideHeaderFields.tooltipText_Desc[CSV_HEADER_FIELD_LABEL_POS];
            newGuideObj.arrData[CSV_HEADER_ROW_INDEX][11]= newGuideObj.TamilGuideHeaderFields.find_1[CSV_HEADER_FIELD_LABEL_POS];
            newGuideObj.arrData[CSV_HEADER_ROW_INDEX][12]= newGuideObj.TamilGuideHeaderFields.find_2[CSV_HEADER_FIELD_LABEL_POS];
            newGuideObj.arrData[CSV_HEADER_ROW_INDEX][13]= newGuideObj.TamilGuideHeaderFields.find_3[CSV_HEADER_FIELD_LABEL_POS];
            return newGuideObj;
        },
        getDefaultFieldObject:function () {
            var defaultField = {
                fieldLocatorArr:[],
                dataArr:[],

            }
            for (var i=0; i< this.arrData[CSV_HEADER_ROW_INDEX].length; i++) {
                defaultField.fieldLocatorArr.push(i);
                defaultField.dataArr.push("");
            }

//CSV_HEADER_FIELD_DEF_VAL_POS            
            defaultField.dataArr[0]=this.TamilGuideHeaderFields.ver[CSV_HEADER_FIELD_DEF_VAL_POS];
            defaultField.dataArr[1]=this.TamilGuideHeaderFields.ReplaceWord[CSV_HEADER_FIELD_DEF_VAL_POS];
            defaultField.dataArr[2]=this.TamilGuideHeaderFields.GrepPrefix_find[CSV_HEADER_FIELD_DEF_VAL_POS];
            defaultField.dataArr[3]=this.TamilGuideHeaderFields.GrepSuffix_find[CSV_HEADER_FIELD_DEF_VAL_POS];
            defaultField.dataArr[4]=this.TamilGuideHeaderFields.GrepPrefix_replace[CSV_HEADER_FIELD_DEF_VAL_POS];
            defaultField.dataArr[5]=this.TamilGuideHeaderFields.GrepSuffix_replace[CSV_HEADER_FIELD_DEF_VAL_POS];
            defaultField.dataArr[6]=this.TamilGuideHeaderFields.IgnoreGrep_FindPrefix[CSV_HEADER_FIELD_DEF_VAL_POS];
            defaultField.dataArr[7]=this.TamilGuideHeaderFields.IgnoreGrep_FindSuffix[CSV_HEADER_FIELD_DEF_VAL_POS];
            defaultField.dataArr[8]=this.TamilGuideHeaderFields.IgnoreGrep_ReplacePrefix[CSV_HEADER_FIELD_DEF_VAL_POS];
            defaultField.dataArr[9]=this.TamilGuideHeaderFields.IgnoreGrep_ReplaceSuffix[CSV_HEADER_FIELD_DEF_VAL_POS];
            defaultField.dataArr[10]=this.TamilGuideHeaderFields.tooltipText_Desc[CSV_HEADER_FIELD_DEF_VAL_POS];
            defaultField.dataArr[11]=this.TamilGuideHeaderFields.find_1[CSV_HEADER_FIELD_DEF_VAL_POS];
            defaultField.dataArr[12]=this.TamilGuideHeaderFields.find_2[CSV_HEADER_FIELD_DEF_VAL_POS];
            defaultField.dataArr[13]=this.TamilGuideHeaderFields.find_3[CSV_HEADER_FIELD_DEF_VAL_POS];
            return defaultField;
        },
        getDefaultRecordObj: function () {
            var defaultRecord = {
                recordLocator:APPEND_CSV_RECORD,
                fieldLocatorArr:[],
                dataArr:[],
                fieldsLength:-1,
            }
            var defField=this.getDefaultFieldObject();
            for (var i=0; i< this.arrData[CSV_HEADER_ROW_INDEX].length; i++) {
                defaultRecord.fieldLocatorArr.push(i);
                defaultRecord.dataArr.push("");
                defaultRecord.fieldLocatorArr[i] = defField.fieldLocatorArr[i];
                defaultRecord.dataArr[i] = defField.dataArr[i];
            }
            defaultRecord.fieldsLength = defaultRecord.fieldLocatorArr.length;
            return defaultRecord;
        },

        joinArrayData: function (fieldSepStr, recordSepStr) {
            if (fieldSepStr == null || fieldSepStr == "" || recordSepStr== null || recordSepStr == "") return "";
            var joinedStrArr="", i = 0, j = 0;
            for (i=0; i<this.arrData.length;i++) {
                for (j=0;j<this.arrData[i].length; j++) {
                    joinedStrArr+=this.arrData[i][j]+fieldSepStr;
                } 
                joinedStrArr+=recordSepStr;
            }
            return joinedStrArr;
        },
        updateArrayData: function (recordLocator, fieldLocator, data) {
            var newRow = col = 0, i=0, j=0;
            if (recordLocator < APPEND_CSV_RECORD || fieldLocator < 0 || fieldLocator >= this.arrData[CSV_HEADER_ROW_INDEX].length) return -1;
            col = fieldLocator;
            newRow = recordLocator;
            if (recordLocator == APPEND_CSV_RECORD || recordLocator > this.arrData.length) newRow = this.arrData.length;
            for (j=0; j<this.arrData[CSV_HEADER_ROW_INDEX].length;j++) {
                if (this.arrData[newRow]==null) this.arrData[newRow]=[];
                if (this.arrData[newRow][j] == null) this.arrData[newRow][j]="";
                if (j == col) this.arrData[newRow][j] = data;
            }
            return newRow;
        },
        updateArrayDataBulk: function (defaultRecordObjArr) {
            var newRow = col = 0, i=0, j=0, recordLocator = -2, fieldLocator = -2, data=-1, rInd=0, fInd=0;

            if (defaultRecordObjArr== null || defaultRecordObjArr.length==0 ) return -1;
            for (rInd = 0; rInd < defaultRecordObjArr.length; rInd++) {
                recordLocator = defaultRecordObjArr[rInd].recordLocator;
                if ( defaultRecordObjArr[rInd].fieldLocatorArr == null || defaultRecordObjArr[rInd].fieldLocatorArr.length==0
                || defaultRecordObjArr[rInd].dataArr == null || defaultRecordObjArr[rInd].dataArr.length == 0 
                || defaultRecordObjArr[rInd].fieldLocatorArr.length != defaultRecordObjArr[rInd].dataArr.length
                || defaultRecordObjArr[rInd].fieldLocatorArr.length != this.arrData[CSV_HEADER_ROW_INDEX].length
                ) return -1;
                newRow = recordLocator;
                if (recordLocator == APPEND_CSV_RECORD || recordLocator > this.arrData.length) newRow = this.arrData.length;
                for (fInd = 0; fInd < defaultRecordObjArr[rInd].fieldLocatorArr.length; fInd++) {
                    fieldLocator = defaultRecordObjArr[rInd].fieldLocatorArr [fInd];
                    data = defaultRecordObjArr[rInd].dataArr [fInd];
                    if (recordLocator < APPEND_CSV_RECORD || fieldLocator < 0 || fieldLocator >= this.arrData[CSV_HEADER_ROW_INDEX].length) return -1;
                    col = fieldLocator;
                    if (this.arrData[newRow]==null) this.arrData[newRow]=[];
                    if (this.arrData[newRow][fInd] == null) this.arrData[newRow][fInd]="";
                    if (fInd == col) this.arrData[newRow][fInd] = data;

                }
            }
            return this.arrData.length;
        },   
    };
    return TamilGuideData;
}
var g_TamGuideObj;
var g_bTamGuideLoaded = false;
function resetTamilGuideGlobalObj () {
    g_TamGuideObj = getTamilGuideHeaderObject ();
    var newObj = g_TamGuideObj.ReInitialize(1, g_TamGuideObj);
    g_bTamGuideLoaded = false;
}

function checkTamGuideHeader (TamilGuideHeaderFields)
{
    var bRes = true, strRes = "expected Title- ";
    if (-1 == TamilGuideHeaderFields.ver[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += TamilGuideHeaderFields.ver[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == TamilGuideHeaderFields.action[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += TamilGuideHeaderFields.action[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == TamilGuideHeaderFields.ReplaceWord[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += TamilGuideHeaderFields.ReplaceWord[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == TamilGuideHeaderFields.GrepPrefix_find[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += TamilGuideHeaderFields.GrepPrefix_find[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == TamilGuideHeaderFields.GrepSuffix_find[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += TamilGuideHeaderFields.GrepSuffix_find[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == TamilGuideHeaderFields.GrepPrefix_replace[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += TamilGuideHeaderFields.GrepPrefix_replace[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == TamilGuideHeaderFields.GrepSuffix_replace[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += TamilGuideHeaderFields.GrepSuffix_replace[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == TamilGuideHeaderFields.IgnoreGrep_FindPrefix[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += TamilGuideHeaderFields.IgnoreGrep_FindPrefix[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == TamilGuideHeaderFields.IgnoreGrep_FindSuffix[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += TamilGuideHeaderFields.IgnoreGrep_FindSuffix[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == TamilGuideHeaderFields.IgnoreGrep_ReplacePrefix[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += TamilGuideHeaderFields.IgnoreGrep_ReplacePrefix[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == TamilGuideHeaderFields.IgnoreGrep_ReplaceSuffix[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += TamilGuideHeaderFields.IgnoreGrep_ReplaceSuffix[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == TamilGuideHeaderFields.tooltipText_Desc[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += TamilGuideHeaderFields.tooltipText_Desc [CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == TamilGuideHeaderFields.find_1[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += TamilGuideHeaderFields.find_1[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == TamilGuideHeaderFields.find_2[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += TamilGuideHeaderFields.find_2[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    if (-1 == TamilGuideHeaderFields.find_3[CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += TamilGuideHeaderFields.find_3[CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    for (var k=0;k<TamilGuideHeaderFields.findArr.length;k++) {
        if (-1 == TamilGuideHeaderFields.findArr[k][CSV_HEADER_FIELD_LOCATOR_POS]) {bRes = false; strRes += TamilGuideHeaderFields.findArr[k][CSV_HEADER_FIELD_LABEL_POS] +"\r"; }
    }
    if (bRes == false) alert ("Missing or corrupt Header \r"+ strRes +"\r Check and Correct header. Process will be terminated!");

    return bRes;
    
}
function ConvertEngAccentToNoAccent (strToTransliterate){

    var accent_fold = (function () {
        var EngITRANSToUni_singleChar_map = {
            'ā': 'a', 
            'Ā': 'A', 
            'ī':'i',
            'Ī':'I',
            'ū':'u',
            'Ū':'U',
            'ṇ':'n',
            'Ṇ':'N',
            'ṛ':'r',
            'Ṛ':'r',
            'ḍ':'d',
            'Ḍ':'D',
            'ṭ':'t',
            'Ṭ':'T',
            'ṁ':'m',
            'Ṁ':'M',
            'ṣ':'sh',
            'Ṣ':'Sh',
            'ś':'s',
            'Ś':'S',
            'ḥ':'h',
            'Ḥ':'H',
            'ḷ':'l',
            'Ḷ':'L',
            'r̥̄':'r',
            'R̥̄':'R',
            'ḹ':'l',
            'Ḹ':'L',
            'ñ':'ng',
            'Ñ':'Ng',
            'jñ':'jn',
            'jÑ':'jN',
        };
        return function accent_fold(s) {
        if (!s) { return ''; }
        var ret = '', accent_map_to_use, tmpChar , tmpMsg = 0;
        accent_map_to_use = EngITRANSToUni_singleChar_map;
        for (var i = 0; i < s.length; i++) {
           
           tmpChar = accent_map_to_use[s.charAt(i)];
            ret += tmpChar || s.charAt(i);
        }
        return ret;
        };
    } ()); 
    return accent_fold(strToTransliterate);    
}
function ConvertEngAccentToITRANS (strToTransliterate){

    var accent_fold = (function () {
        var EngITRANSToUni_singleChar_map = {
            'ā': 'A', 
            'Ā': 'A', 
            'ī':'I',
            'Ī':'I',
            'ū':'U',
            'Ū':'U',
            'ṇ':'N',
            'Ṇ':'N',
            'ṛ':'R',
            'Ṛ':'R',
            'ḍ':'D',
            'Ḍ':'D',
            'ṭ':'T',
            'Ṭ':'T',
            'ṁ':'M',
            'Ṁ':'M',
            'ṣ':'S',
            'Ṣ':'S',
            'ś':'z',
            'Ś':'z',
            'ḥ':'H',
            'Ḥ':'H',
            'ḷ':'L',
            'Ḷ':'L',
            'r̥̄':'X',
            'R̥̄':'X',
            'ḹ':'W',
            'Ḹ':'W',
            'ñ':'J',
            'Ñ':'J',
            'jñ':'Q',
            'jÑ':'Q',
        };
        return function accent_fold(s) {
        if (!s) { return ''; }
        var ret = '', accent_map_to_use, tmpChar , tmpMsg = 0;
        accent_map_to_use = EngITRANSToUni_singleChar_map;
        for (var i = 0; i < s.length; i++) {
           
           tmpChar = accent_map_to_use[s.charAt(i)];
            ret += tmpChar || s.charAt(i);
        }
        return ret;
        };
    } ()); 
    return accent_fold(strToTransliterate);    
}
function prepareFindReplaceRecordFromWordList_forCSV(wordListStr) {
    if (wordListStr==null || wordListStr.length==0) return -1;
    // find all the three possible variations of the passed wordListStr (i.e. remove accents, convert to ITRANS format, remove - or spaces)
    var variantWordListArr = [], tempStr;
    variantWordListArr.push(wordListStr); // 0th position will be the actual string to replace
    variantWordListArr.push(ConvertEngAccentToNoAccent (wordListStr)); // 1st position will be to find the string without accent
    // 2nd position will be to find the accented string but with - or space transposed
    if (wordListStr.indexOf('-')!=-1){
        tempStr = wordListStr.replace(RegExp("-","gi")," ");
        variantWordListArr.push(tempStr);
    } else if (wordListStr.indexOf(' ')!=-1) {
        tempStr = wordListStr.replace(RegExp(" ","gi"),"-");
        variantWordListArr.push(tempStr);
    }
    // 3rd position will be to find the string but with both unaccented and - or space transposed
    if (tempStr!=null && tempStr != wordListStr) variantWordListArr.push(ConvertEngAccentToNoAccent (tempStr));
    return variantWordListArr;
}
function createCSVFromWordList(wordListStr){
    if (wordListStr==null || wordListStr.length==0) return -1;
    var findReplaceRecordArr = [[]];
    var wordArr = wordListStr.replace(/\s\r/gi, "\r").split ("\r\n");
    for (var i = 0; i<wordArr.length; i++) {        
        findReplaceRecordArr[i]= prepareFindReplaceRecordFromWordList_forCSV(wordArr[i]);
    }
    var defRecObj = [];
    for (var recId=0; recId<findReplaceRecordArr.length;recId++) {
        defRecObj.push(g_TamGuideObj.getDefaultRecordObj());
        defRecObj[recId].dataArr[1] = findReplaceRecordArr[recId][0];
        defRecObj[recId].dataArr[11] = findReplaceRecordArr[recId][1];
        defRecObj[recId].dataArr[12] = findReplaceRecordArr[recId][2];
        defRecObj[recId].dataArr[13] = findReplaceRecordArr[recId][3];
    }
    var newRow = g_TamGuideObj.updateArrayDataBulk (defRecObj);
    var strOut = g_TamGuideObj.joinArrayData(",","\r\n");
    return strOut;
}

function loadAndVerifyTamilGuideHeader (csvFileContents)
{
    var i =0, j = 0, k = 0, headerCheckComplete = false; 
    var splCellVal; 
    var verArr;
    resetTamilGuideGlobalObj ();
    g_TamGuideObj.arrData = parseCSV (csvFileContents, ",");

    for (i = 0; i< g_TamGuideObj.arrData.length; i++)
    {
        for (j =0; j< g_TamGuideObj.arrData[i].length; j++)
        {
            // the first row is expected to be the header, so check the headings and update the header info, especially the index
            // Even if the field columns in excel are moved or re arranged, this code will work fine as long as the headings are un altered
            g_TamGuideObj.arrData[i][j] = g_TamGuideObj.arrData[i][j].replace(/^[\s\uFEFF\xA0]+|[\s\uFEFF\xA0]+$/g, ''); //trim functionality
            if (i == CSV_HEADER_ROW_INDEX ) {
                if (j==0) {
                    splCellVal = g_TamGuideObj.arrData[i][j].split(g_TamGuideObj.verSep);
                    verArr=splCellVal[0].split("=");
                    if (verArr[CSV_HEADER_FIELD_LOCATOR_POS]&&verArr[CSV_HEADER_FIELD_LABEL_POS]){g_TamGuideObj.verNo = Number(verArr[CSV_HEADER_FIELD_LABEL_POS]);}
                    if (splCellVal[0] && verArr[CSV_HEADER_FIELD_LOCATOR_POS] == g_TamGuideObj.TamilGuideHeaderFields.ver[CSV_HEADER_FIELD_LABEL_POS]) g_TamGuideObj.TamilGuideHeaderFields.ver[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                    if (splCellVal[CSV_HEADER_FIELD_LABEL_POS] && splCellVal[CSV_HEADER_FIELD_LABEL_POS] == g_TamGuideObj.TamilGuideHeaderFields.action[CSV_HEADER_FIELD_LABEL_POS]) g_TamGuideObj.TamilGuideHeaderFields.action[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                    }
                if (g_TamGuideObj.arrData[i][j] == g_TamGuideObj.TamilGuideHeaderFields.ReplaceWord[CSV_HEADER_FIELD_LABEL_POS]) g_TamGuideObj.TamilGuideHeaderFields.ReplaceWord[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (g_TamGuideObj.arrData[i][j] == g_TamGuideObj.TamilGuideHeaderFields.GrepPrefix_find[CSV_HEADER_FIELD_LABEL_POS]) g_TamGuideObj.TamilGuideHeaderFields.GrepPrefix_find[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (g_TamGuideObj.arrData[i][j] == g_TamGuideObj.TamilGuideHeaderFields.GrepSuffix_find[CSV_HEADER_FIELD_LABEL_POS]) g_TamGuideObj.TamilGuideHeaderFields.GrepSuffix_find[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (g_TamGuideObj.arrData[i][j] == g_TamGuideObj.TamilGuideHeaderFields.GrepPrefix_replace[CSV_HEADER_FIELD_LABEL_POS]) g_TamGuideObj.TamilGuideHeaderFields.GrepPrefix_replace[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (g_TamGuideObj.arrData[i][j] == g_TamGuideObj.TamilGuideHeaderFields.GrepSuffix_replace[CSV_HEADER_FIELD_LABEL_POS]) g_TamGuideObj.TamilGuideHeaderFields.GrepSuffix_replace[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (g_TamGuideObj.arrData[i][j] == g_TamGuideObj.TamilGuideHeaderFields.IgnoreGrep_FindPrefix[CSV_HEADER_FIELD_LABEL_POS]) g_TamGuideObj.TamilGuideHeaderFields.IgnoreGrep_FindPrefix[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (g_TamGuideObj.arrData[i][j] == g_TamGuideObj.TamilGuideHeaderFields.IgnoreGrep_FindSuffix[CSV_HEADER_FIELD_LABEL_POS]) g_TamGuideObj.TamilGuideHeaderFields.IgnoreGrep_FindSuffix[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (g_TamGuideObj.arrData[i][j] == g_TamGuideObj.TamilGuideHeaderFields.IgnoreGrep_ReplacePrefix[CSV_HEADER_FIELD_LABEL_POS]) g_TamGuideObj.TamilGuideHeaderFields.IgnoreGrep_ReplacePrefix[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (g_TamGuideObj.arrData[i][j] == g_TamGuideObj.TamilGuideHeaderFields.IgnoreGrep_ReplaceSuffix[CSV_HEADER_FIELD_LABEL_POS]) g_TamGuideObj.TamilGuideHeaderFields.IgnoreGrep_ReplaceSuffix[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (g_TamGuideObj.arrData[i][j] == g_TamGuideObj.TamilGuideHeaderFields.tooltipText_Desc[CSV_HEADER_FIELD_LABEL_POS]) g_TamGuideObj.TamilGuideHeaderFields.tooltipText_Desc[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (g_TamGuideObj.arrData[i][j] == g_TamGuideObj.TamilGuideHeaderFields.find_1[CSV_HEADER_FIELD_LABEL_POS]) g_TamGuideObj.TamilGuideHeaderFields.find_1[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (g_TamGuideObj.arrData[i][j] == g_TamGuideObj.TamilGuideHeaderFields.find_2[CSV_HEADER_FIELD_LABEL_POS]) g_TamGuideObj.TamilGuideHeaderFields.find_2[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (g_TamGuideObj.arrData[i][j] == g_TamGuideObj.TamilGuideHeaderFields.find_3[CSV_HEADER_FIELD_LABEL_POS]) g_TamGuideObj.TamilGuideHeaderFields.find_3[CSV_HEADER_FIELD_LOCATOR_POS] = j; // update the index
                if (g_TamGuideObj.arrData[i][j] == (g_TamGuideObj.TamilGuideHeaderFields.find_headerStr+String(k+1))) {
                    if (g_TamGuideObj.TamilGuideHeaderFields.findArr[k]==null)g_TamGuideObj.TamilGuideHeaderFields.findArr[k]=[-1,""];
                    g_TamGuideObj.TamilGuideHeaderFields.findArr[k][CSV_HEADER_FIELD_LOCATOR_POS] = j;
                    g_TamGuideObj.TamilGuideHeaderFields.findArr[k][CSV_HEADER_FIELD_LABEL_POS]= g_TamGuideObj.TamilGuideHeaderFields.find_headerStr+String(k+1);
                    k++;}
            }
            //if (i == CSV_HEADER_ROW_INDEX && prompt(g_TamGuideObj.arrData[i][j]+"="+g_TamGuideObj.TamilGuideHeaderFields.ReplaceWord[CSV_HEADER_FIELD_LABEL_POS], "Ok to proceed. Cancel to exit!", "Confirm") == null) return;
        }
        if (headerCheckComplete == false) {
            if ((g_TamGuideObj.bHeaderOK = checkTamGuideHeader(g_TamGuideObj.TamilGuideHeaderFields)) == false) return g_TamGuideObj; 
            headerCheckComplete = true;
            g_bTamGuideLoaded = true;
            break;
            }
    }
    return g_TamGuideObj;
}
function joinAllFindsInArray(srcArray, locatorArray, separatorStr) {
    if (srcArray == null || Array.isArray(srcArray) == false || srcArray.length == 0 || locatorArray == null || Array.isArray(locatorArray) == false || locatorArray.length == 0 || separatorStr == null) return "";
    var joinedStrArr=[], i = 0, j = 0;
    for (i=0; i<locatorArray.length;i++) {
        if (Array(locatorArray[i])) {
            if (locatorArray[i][CSV_HEADER_FIELD_LOCATOR_POS] < srcArray.length && srcArray[locatorArray[i][CSV_HEADER_FIELD_LOCATOR_POS]]!="") {
                joinedStrArr.push(srcArray[locatorArray[i][CSV_HEADER_FIELD_LOCATOR_POS]]);
                }
        } else {
            for (i=0; i<locatorArray.length;i++) {
                if (locatorArray[i] < srcArray.length && srcArray[locatorArray[i]]!="") {
                    joinedStrArr.push(srcArray[locatorArray[i]]);
                }
            }
        }
    }
    return joinedStrArr.join(separatorStr);
}
function checkAgainstTamilGuide (contentsToCheckStr, csvFileContents, nSelFunctionID, bReloadGlobalCache=false, padCharToRemove)
{
    var resultObj = {
            report:"TamilGuide Check Failed! .CSV contents invalid or corrupt or invalid function requested!",
            modifiedContentsStr:"",
            nChangesMade_Total:0,
            nPendingChanges:0,
            getChangeIDMap:function(){
                var obj = {
                    elmID_orjStr:"", 
                    elmName_orjStr:"", 
                    orjStrLoc:-1, 
                    elmID_repStr:"",
                    elmName_repStr:"",
                    repStrLoc:-1,
                    elmID_orjStrTag:"textOriginal",
                    elmID_repStrTag:"textReplaced",
                    bChangeAccepted:false,
                    bChangeRejected:false,
                    bReviewComplete:false,
                    categoryLocator:-1, //use cat locator to find out cat start and end
                    elmID_toolTipStr:"",
                    };
                return obj;},
            mapChangeIDLoc:[],
            padCharToRemove:"",
            currentMapLocator:-1,
            prevOrgCtl:null,
            prevRepCtl:null,
            curOrgCtl:null,
            curRepCtl:null,
            nextMapLocator:-1,
            prevMapLocator:-1,
            categoriesChange:[],
            bAllChangesReadyToCommit:false,
            getCategoryObj:function(){
                var obj = {
                    elementIDLocator:-1,
                    catLocatorInMapChangesArr:-1,
                    catStartLoc:-1,
                    catEndLoc:-1,
                    categoryStr:"",
                    numItemsChanged:0,
                    numAccepted:0,
                    numRejected:0,
                    numUnresolved:0,
                    tooltipText_Desc:"",
                    elmID_toolTipStr:"",
                    elmClass_toolTipStr:"",
                    elmID_toolTipTag:"tooltiptext",
                    };
                    return obj;
            },
            reset:function(){
                this.report="";
                this.modifiedContentsStr="";
                this.nChangesMade_Total = 0;
                this.nPendingChanges = 0;
                this.mapChangeIDLoc=[];
                this.padCharToRemove="";
                this.currentMapLocator=-1;
                this.nextMapLocator=-1;
                this.prevMapLocator=-1;
                this.prevOrgCtl=null;
                this.prevRepCtl=null;
                this.curOrgCtl=null;
                this.curRepCtl=null;
            },
        };
    resultObj.reset();
    resultObj.padCharToRemove = padCharToRemove;
    var report="", mapResults;
    var  i=0, j=0, k=0, newPos = -1, findWhatStr = "", changeToStr = "", actionStr = "", action = 0, tempStr="", promptStr = "", tooltipText_DescStr="";

    if (nSelFunctionID > 2 || nSelFunctionID <0) {alert ("Function Not Implemented.....ID "+nSelFunctionID );return resultObj;}
    
    var dictObj, arrData; 
    if (g_bTamGuideLoaded == false|| bReloadGlobalCache == true){ 
        dictObj = loadAndVerifyTamilGuideHeader (csvFileContents);
        } else {
            dictObj = g_TamGuideObj;
        }
    arrData = dictObj.arrData;
    var TamilGuideHeaderFields = dictObj.TamilGuideHeaderFields;
    
    if (dictObj.bHeaderOK == false || arrData == null) {
        alert ("Failed.....Dict");return resultObj;
        }

    //start from the second row
    for (i = 1; i< arrData.length; i++)
    {
        //findWhatStr = arrData[i][TamilGuideHeaderFields.find_1[CSV_HEADER_FIELD_LOCATOR_POS]];
        findWhatStr = joinAllFindsInArray(arrData[i], TamilGuideHeaderFields.findArr, "|");
        if (arrData[i][TamilGuideHeaderFields.IgnoreGrep_FindPrefix[CSV_HEADER_FIELD_LOCATOR_POS]].toLowerCase() == "false")
            findWhatStr = arrData[i][TamilGuideHeaderFields.GrepPrefix_find[CSV_HEADER_FIELD_LOCATOR_POS]]+findWhatStr;
        if (arrData[i][TamilGuideHeaderFields.IgnoreGrep_FindSuffix[CSV_HEADER_FIELD_LOCATOR_POS]].toLowerCase() == "false")
            findWhatStr = findWhatStr +arrData[i][TamilGuideHeaderFields.GrepSuffix_find[CSV_HEADER_FIELD_LOCATOR_POS]];
        if (findWhatStr == "") continue;
        //findWhatStr = findWhatStr.replace(/([\(\[\+\.\*\?\]\)\<\>\=])/gi,"\\$1"); // escape all special characters
        changeToStr = arrData[i][TamilGuideHeaderFields.ReplaceWord[CSV_HEADER_FIELD_LOCATOR_POS]];
        tooltipText_DescStr = arrData[i][TamilGuideHeaderFields.tooltipText_Desc[CSV_HEADER_FIELD_LOCATOR_POS]];
        if (arrData[i][TamilGuideHeaderFields.IgnoreGrep_ReplacePrefix[CSV_HEADER_FIELD_LOCATOR_POS]].toLowerCase() == "false")
            changeToStr = arrData[i][TamilGuideHeaderFields.GrepPrefix_replace[CSV_HEADER_FIELD_LOCATOR_POS]]+changeToStr;
        if (arrData[i][TamilGuideHeaderFields.IgnoreGrep_ReplaceSuffix[CSV_HEADER_FIELD_LOCATOR_POS]].toLowerCase() == "false")
            changeToStr = changeToStr +arrData[i][TamilGuideHeaderFields.GrepSuffix_replace[CSV_HEADER_FIELD_LOCATOR_POS]];        
        actionStr = arrData[i][TamilGuideHeaderFields.action[CSV_HEADER_FIELD_LOCATOR_POS]];
        if (actionStr.toLowerCase()== "prompt"){
            nSelFunctionID==1? action=1:action = 0; // The user can override the .csv value with Override All Prompts function from dialog box. True will cause auto exec
            }else if (actionStr == "Doubt" || actionStr.toLowerCase()== "noprompt"){
                nSelFunctionID==2? action=0:action = 1; // The user can override the .csv value with Override Do Not Ask flag from dialog box. True will force prompts
                }
        if (action == 0) {
            promptStr = "Replace? instance No. "+String (i) +"<"+ findWhatStr +"> with <"+changeToStr+">\r" ;
            report+= promptStr;
            tempStr = prompt (promptStr +"\r Edit ChangeStr and click Ok to continue. Cancel to quit", changeToStr, "Confirm");
            if (tempStr == null) {
                report+= "Process terminated by user!\r At location - Instance No. - "+String(j);alert (report); break;}
                changeToStr = tempStr;
            }
        var regEx = new RegExp(findWhatStr, "ig");
        var regEx_notGlobal = new RegExp (findWhatStr,"i");
        regEx.lastIndex = 0;
        changeToStr = changeToStr.replace(/\u202C/gi,"");
        var tempCatObj = resultObj.getCategoryObj();
        var numMatchedItems = 0;
        function getRepStr() {
            var match = arguments[0], changeStr_Mod = changeToStr; 
            offset = arguments [arguments.length-2];
            for (var ind=1; ind<arguments.length-2;ind++) {
                changeStr_Mod = changeStr_Mod.replace(RegExp("\\$"+String(ind),"gi"), arguments[ind]);
                }

            var retStr="", matchStr_map = "", splCharPos=0;
            matchStr_map = match;
            tempCatObj.elementIDLocator = i-1;//category locator
            /*matchStr_map = myTrim (match,true,true);
            if ((splCharPos = match.indexOf(">")) != -1) {
                matchStr_map = match.substr(splCharPos+1);
                } else if ((splCharPos = match.indexOf("<")) != -1){
                    matchStr_map = match.substr(0,splCharPos);
                    }*/
            if (numMatchedItems == 0) {
                tempCatObj.catLocatorInMapChangesArr = resultObj.nChangesMade_Total; // beginning of a category
                tempCatObj.catStartLoc = tempCatObj.catLocatorInMapChangesArr;
                tempCatObj.categoryStr = findWhatStr;
                tempCatObj.elmClass_toolTipStr = "tooltiptext";
                tempCatObj.elmID_toolTipTag = "label";
                }
            resultObj.nChangesMade_Total++;
            resultObj.nPendingChanges++;
            tempCatObj.numItemsChanged = ++numMatchedItems; // this variable will be reset for each category of change in sequence for each match
            tempCatObj.catEndLoc = tempCatObj.catStartLoc + (numMatchedItems-1);            
            var tempObj = resultObj.getChangeIDMap();
            tempObj.elmName_orjStr = "orj_"+String(i);
            tempObj.elmID_orjStr = "orj_"+String(offset);
            tempObj.repStrLoc = tempObj.orjStrLoc = offset;
            tempObj.elmName_repStr = "rep_"+String(i);
            tempObj.elmID_repStr = "rep_"+String(offset);
            tempObj.categoryLocator = resultObj.categoriesChange.length;

            resultObj.mapChangeIDLoc.push(tempObj);
            resultObj.prevMapLocator = resultObj.nextMapLocator = resultObj.currentMapLocator = 0; // reset it to the beginning...
            tempObj.elmID_toolTipStr = "TT_"+String(offset);
            retStr = "<"+tempObj.elmID_orjStrTag 
                +" id=\""+tempObj.elmID_orjStr+"\""
                +" name=\""+tempObj.elmName_orjStr+"\" "
                +"class=\"tooltip\">"+matchStr_map
                +"<"+tempCatObj.elmID_toolTipTag 
                +" id=\""+tempObj.elmID_toolTipStr+"\""
                +" class=\""+tempCatObj.elmClass_toolTipStr+"\" "
                +" style=\"top:95%\">"+"#"+String(tempCatObj.numItemsChanged)+"<BR>"+tooltipText_DescStr
                +"</"+tempCatObj.elmID_toolTipTag+">"                
                +"</"+tempObj.elmID_orjStrTag+">"
                +"<"+tempObj.elmID_repStrTag 
                +" id=\""+tempObj.elmID_repStr+"\""
                +" name=\""+tempObj.elmName_repStr+"\" "
                +">"+changeStr_Mod
                +"</"+tempObj.elmID_repStrTag+">";

            return retStr;
        }

        contentsToCheckStr = contentsToCheckStr.replace (regEx, getRepStr);
        if (numMatchedItems != 0){
            tempCatObj.categoryStr = findWhatStr + " <=> " + numMatchedItems + " matches";
            tempCatObj.tooltipText_Desc = tooltipText_DescStr;
            tempCatObj.numUnresolved = tempCatObj.numItemsChanged;
            resultObj.categoriesChange.push(tempCatObj);

        }
        //contentsToCheckStr = contentsToCheckStr.replace (findWhatStr, changeToStr);
    }
    resultObj.modifiedContentsStr = contentsToCheckStr;
    resultObj.report = report;
    return resultObj;
}







function getTranslitPatternSearchObj ()
{
    var translitPatternObj = {
        translitActions:    {
            convertAndTranslit:[
            {actionId:-1, actionStr:"None",}, 
            {actionId:0, actionStr:"Convert Font and Transliterate",}, 
            {actionId:1, actionStr:"Transliterate Only"}, 
            {actionId:2, actionStr:"Convert Font only"},
            {actionId:3, actionStr:"Copy and replace only"},
            {actionId:4, actionStr:"Convert Font, copy-replace"},
            ],
            },
        nSelActionID: 0,
        selActionStr:"",
        transliterateObj:null,
    };

    return translitPatternObj;
}
function getSynonymsDelimitersObj ()
{
    var delimitersObj = {
        regExp_PatternToSearch:"",
        leadingDelimiter:";", //default
        langMeaningSeparatorDelimiter:"[–—]", //default is hyphen or em-dash... hyphen (–) is different from regular dash(-)
        trailingDelimiter:"[;.]", //default is a semi colon or period
        leadingPaddedDelimiterToRemove:";\\t", // default is ; followed by a tab. This will be searched and removed from entire string
        trailingPaddedDelimiterToRemove:"", //default none
        };
    return delimitersObj;
}

function processSynonymsParts (fullSynonymString, langPartObj, meaningPartObj, delimitersObj)
{
    var processedSynStringObj = {
        regExp_PatternSearched:"",
        fullMatchingStr_In:"",
        fullMatchingStr_Out:"",
        langPartActionPerf_ID:-1,
        extractedLangPart_Str:"",
        extractedAndProcLangPart_Str:"",
        meaningPartActionPerf_ID:-1,
        extractedMeaningPart_Str:"",
        extractedAndProcMeaningPart_Str:"",
        //if we want to know what langMeaningSeparatorDelimiter was used, we need to extract them, 
        // for example  langMeaningSeparatorDelimiter:"[–—]", //default is dash or hyphen or em-dash
        // how to which one was actually found?
        actualDelimiterFound:"",
        };
    if (fullSynonymString != null && fullSynonymString != "")
    {
        var  sanskritPart = "", englishPart="", parts;
        var regex = new RegExp (delimitersObj.langMeaningSeparatorDelimiter);
        parts = fullSynonymString.split(regex);
        var actualDelimiterArr = fullSynonymString.match(regex);
        var actualDelimiter = (actualDelimiterArr.length !=0)?actualDelimiterArr[0]:"";
        var actualDelimiterFoundPos = fullSynonymString.search(regex);
        if (parts.length == 0) {alert (fullSynonymString+"_not is expected format!!!!");return null;}        
        processedSynStringObj.regExp_PatternSearched = delimitersObj.regExp_PatternToSearch;
        processedSynStringObj.fullMatchingStr_In = fullSynonymString;
        processedSynStringObj.langPartActionPerf_ID = langPartObj.nSelActionID;
        processedSynStringObj.meaningPartActionPerf_ID = meaningPartObj.nSelActionID;
        
        if (parts.length>0) sanskritPart = parts[0];
        if (parts.length>1) englishPart= parts[1];
        
        if (sanskritPart!="") {
            processedSynStringObj.extractedLangPart_Str = sanskritPart;
            switch (langPartObj.nSelActionID) {
                case 0:
                   sanskritPart = convertNon_unicodeToUnicode (langPartObj.transliterateObj.selFontName_TranslitID, sanskritPart);
    //               alert (changeToStr);
                   sanskritPart = transliterateTool (sanskritPart, langPartObj.transliterateObj);
    //                alert (changeToStr);
                   break;
                case 1:
                   sanskritPart = transliterateTool (sanskritPart, langPartObj.transliterateObj);
                   break;
                case 2:
                   sanskritPart = convertNon_unicodeToUnicode (langPartObj.transliterateObj.selFontName_TranslitID, sanskritPart);
                   break;
                default:
                   break;
                }
            processedSynStringObj.extractedAndProcLangPart_Str = myTrim(sanskritPart, true, true);
            }

        if (englishPart!="") {
            processedSynStringObj.extractedMeaningPart_Str = englishPart;
            switch (meaningPartObj.nSelActionID) {
                case 0:
                   englishPart = convertNon_unicodeToUnicode (meaningPartObj.transliterateObj.selFontName_TranslitID, englishPart);
                   englishPart = transliterateTool (englishPart, meaningPartObj.transliterateObj);
                   break;
                case 1:
                   englishPart = transliterateTool (englishPart, meaningPartObj.transliterateObj);
                   break;
                case 2:
                   englishPart = convertNon_unicodeToUnicode (meaningPartObj.transliterateObj.selFontName_TranslitID, englishPart);
                   break;
                default:
                   break;
                }
            processedSynStringObj.extractedAndProcMeaningPart_Str = myTrim(englishPart, true, true);
            }
        if (actualDelimiterFoundPos == -1) {
            processedSynStringObj.fullMatchingStr_Out = myTrim(sanskritPart, false,true)+"—"+englishPart; // if for some reason the delimiter used could not be located
            } else {
                processedSynStringObj.fullMatchingStr_Out = myTrim(sanskritPart, false,true)+actualDelimiter+englishPart;
                processedSynStringObj.actualDelimiterFound = fullSynonymString[actualDelimiterFoundPos];
                }

    }
    return processedSynStringObj;
    }
function extractAndProcessSynonyms (originalStr, sanskritPartObj, englishPartObj, delimitersObj)
{
    var  transformStr = originalStr;
    var dummyPaddingStr = "<=>";
    var regExpStr = "(?<="+delimitersObj.leadingDelimiter+")(.+?)("+delimitersObj.langMeaningSeparatorDelimiter+")(.+?)(?="+delimitersObj.trailingDelimiter+")";
    var regex = new RegExp (regExpStr,"g");
    // the following is the look around to extract the sanskritPartObj and the englishPartObj
    //var regex = /(?<=;).+?[–—].+?(?=[;.])/g; 
    // this works in the indesign find grep window and browser's javascript workbench third party tool
    //var regex = /((?<=^)|(?<=;)|(?<=\r)).+?[–—].+?(?=[;.])/g;
    var found, sanskritPartPos = 1, delimitPos1 = 3, englishPartPos = 4, delimitPos2 = 5, changeToStr = ""; //these were tested in javascript workbench and found that positons 1 and 4 are where the strings
//    alert ("OriginalSTR: "+transformStr+"\r"+regex);
//    alert (sanskritPartObj.nSelActionID+"_"+englishPartObj.nSelActionID+"="+ regex);
    // the first position of found array has the entire matching strings
//    while ((found = transformStr.match(regex)) != null) {
    var  sanskritPart = "", englishPart="", parts, processedSynStringObj;
    delimitersObj.regExp_PatternToSearch = regExpStr;
    while ((found = regex.exec(originalStr)) != null) {
        if ((processedSynStringObj = processSynonymsParts (found[0], sanskritPartObj, englishPartObj, delimitersObj))==null) continue;
       transformStr = transformStr.replace (found [0],processedSynStringObj.fullMatchingStr_Out);
    }        
    var regEx1 = new RegExp (delimitersObj.leadingPaddedDelimiterToRemove, "g");
    transformStr = transformStr.replace(regEx1,"");
//    alert ("TransformSTR: "+transformStr);

    return transformStr;
    
    
}
function extractSynonymsMeaningArray (originalStr, sanskritPartObj, englishPartObj, delimitersObj)
{
    var  transformStr = originalStr;
    var returnArrayObj = [];
    var retObj = {
        part1:[],
        part2:[],
        fullObj:[],
        };
    
    var arrayPos = 0;
    var dummyPaddingStr = "<=>";
    var regExpStr = "(?<="+delimitersObj.leadingDelimiter+")(.+?)("+delimitersObj.langMeaningSeparatorDelimiter+")(.+?)(?="+delimitersObj.trailingDelimiter+")";
    var regex = new RegExp (regExpStr,"g");
    // the following is the look around to extract the sanskritPartObj and the englishPartObj
    //var regex = /(?<=;).+?[–—].+?(?=[;.])/g; 
    // this works in the indesign find grep window and browser's javascript workbench third party tool
    //var regex = /((?<=^)|(?<=;)|(?<=\r)).+?[–—].+?(?=[;.])/g;
//    var found, sanskritPartPos = 1, delimitPos1 = 3, englishPartPos = 4, delimitPos2 = 5, changeToStr = ""; //these were tested in javascript workbench and found that positons 1 and 4 are where the strings
//    alert ("OriginalSTR: "+transformStr+"\r"+regex);
//    alert (sanskritPartObj.nSelActionID+"_"+englishPartObj.nSelActionID+"="+ regex);
    // the first position of found array has the entire matching strings
//    while ((found = transformStr.match(regex)) != null) {
    var  processedSynStringObj;
    while ((found = regex.exec(originalStr)) != null) {
        if ((processedSynStringObj = processSynonymsParts (found[0], sanskritPartObj, englishPartObj, delimitersObj))==null) continue;
        retObj.fullObj[arrayPos] = processedSynStringObj;
        retObj.part1[arrayPos] = processedSynStringObj.extractedLangPart_Str
        //.replace(RegExp(delimitersObj.trailingDelimiter,"g"),"")
        ;
        retObj.part2[arrayPos] = processedSynStringObj.extractedMeaningPart_Str
        //.replace(RegExp(delimitersObj.trailingDelimiter,"g"),"")
        ;
        arrayPos++;
    }        
    return retObj;
    
    
}
function extractInBetweenAndReturnResArray (originalStr, delimiterBegin, delimiterEnd)
{
    var returnArrayObj = [];
    
    var arrayPos = 0;
    var regExpStr = "(?<="+delimiterBegin+")(.+?)(?="+delimiterEnd+")";
    var regex = new RegExp (regExpStr,"g");
    while ((found = regex.exec(originalStr)) != null) {
        returnArrayObj[arrayPos] = found[0];
        arrayPos++;
    }        
    return returnArrayObj;    
}
function myTrim(str, bTrimStart, bTrimEnd, trimChar="") {
    if (trimChar==""){
        if (bTrimStart == true&& bTrimEnd == true) return str.replace(/^\s+/,'').replace(/\s+$/,'');
        if (bTrimStart == true) return str.replace(/^\s+/,'');
        if (bTrimEnd == true) return str.replace(/\s+$/,'');
    } else {
        if (bTrimStart == true&& bTrimEnd == true) return str.replace(RegExp("^"+trimChar,"i"),'').replace(RegExp(trimChar+"$","i"),'');
        if (bTrimStart == true) return str.replace(RegExp("^"+trimChar,"i"),'');
        if (bTrimEnd == true) return str.replace(RegExp(trimChar+"$","i"),'');
    }
    return str;
    }
var classGetBetween = {
    results:[],
    string:"",
    get_UsingRegx_match:function extract(str, beg, end) {
        const matcher = new RegExp(beg+"(.+?)(?="+end+")","gi");
        this.results = str.match(matcher);
        
        return this.results;
        //const normalise = (str) => str.slice(beg.length,end.length*-1);
      //return str.match(matcher).map(normalise);
     },
    get_UsingRegx_exec:function extract(str, beg, end) {
        var returnArrayObj = [];

        var arrayPos = 0;
        var regExpStr = "(?<="+beg+")(.+?)(?="+end+")";
        var regex = new RegExp (regExpStr,"g");
        while ((found = regex.exec(str)) != null) {
            returnArrayObj[arrayPos] = found[0];
            arrayPos++;
        }        
        return returnArrayObj;    
     },
    getFromBetween:function (sub1,sub2) {
        if(this.string.indexOf(sub1) < 0 || this.string.indexOf(sub2) < 0) return false;
        var SP = this.string.indexOf(sub1)+sub1.length;
        var string1 = this.string.substr(0,SP);
        var string2 = this.string.substr(SP);
        var TP = string1.length + string2.indexOf(sub2);
        return this.string.substring(SP,TP);
    },
    removeFromBetween:function (sub1,sub2) {
        if(this.string.indexOf(sub1) < 0 || this.string.indexOf(sub2) < 0) return false;
        var removal = sub1+this.getFromBetween(sub1,sub2)+sub2;
        this.string = this.string.replace(removal,"");
    },
    getAllResults:function (sub1,sub2) {
        // first check to see if we do have both substrings
        if(this.string.indexOf(sub1) < 0 || this.string.indexOf(sub2) < 0) return;

        // find one result
        var result = this.getFromBetween(sub1,sub2);
        // push it to the results array
        this.results.push(result);
        // remove the most recently found one from the string
        this.removeFromBetween(sub1,sub2);

        // if there's more substrings
        if(this.string.indexOf(sub1) > -1 && this.string.indexOf(sub2) > -1) {
            this.getAllResults(sub1,sub2);
        }
        else return;
    },
    get:function (string,sub1,sub2) {
        this.results = [];
        this.string = string;
        this.getAllResults(sub1,sub2);
        return this.results;
    }
}
// Generic excel .csv file extract and parse functionality

var g_csvCol = {
    colHeadingStr:"",
    colData:[],
    };
var g_csvAllCols = [[]];
function getArrayToStoreCol (){ var tempArr = []; return tempArr;}
function setCSVColInfo (csvDataArray, csvHeaderTitlesArray) {
    var row =0, col = 0, colDataIndex = 0;
    if (csvDataArray.length == 0 || csvDataArray[CSV_HEADER_ROW_INDEX].length == 0 || csvHeaderTitlesArray.length == 0 || csvHeaderTitlesArray.length != csvDataArray[CSV_HEADER_ROW_INDEX].length) {alert("invalid args!");return null;}
    var colTitle = [], tempArr, temp;
    for (row = 0; row<csvDataArray.length; row++) {
        for (col = 0; col<csvDataArray[row].length; col++) {
            if (row == 0)   {
                colTitle[col]  =  csvDataArray [row][col]; 
                if (colTitle[col].indexOf(csvHeaderTitlesArray[col]) == -1) { alert(colTitle[col] +": title Mismatch at "+String(row)+","+String(col)+":"+csvHeaderTitlesArray[col]);return null;}
                tempArr = getArrayToStoreCol ();
                if (g_csvAllCols [csvHeaderTitlesArray[col]] == null) g_csvAllCols.push(csvHeaderTitlesArray[col]);
                g_csvAllCols [csvHeaderTitlesArray[col]]=tempArr;
                }
            }
        }
    
    for (col = 0; col <csvDataArray[CSV_HEADER_ROW_INDEX].length; col++) {
        temp = g_csvAllCols [csvHeaderTitlesArray[col]];
        for (row = 1; row <csvDataArray.length; row++) {
            temp [row-1] = csvDataArray[row][col];
            }
        }
    return g_csvAllCols;

}
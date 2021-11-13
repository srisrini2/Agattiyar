/* Window Engine - MIT License - Copyright (c) 2019 Gauthier Staehler */


var g_activePopupClass;
const metaTag = document.createElement("meta");
metaTag.name = "viewport";
metaTag.content = "user-scalable=0";
document.getElementsByTagName("head")[0].appendChild(metaTag);    
var g_ResultObj;
var g_outputEditorControl;
var g_bBrowseByCat = false;
var g_catCurCatSel = 0;
var g_catDefCatSel = 0;
var BTN_PREV = 1;
var BTN_NEXT = 2;
var BTN_ACCEPT = 3;
var BTN_ACCEPT_ALL = 4;
var BTN_REJECT = 5;
var BTN_REJECT_ALL = 6;
var BTN_COMMIT = 7;
var g_actionButtonDetailsObjArr = [
    {id:BTN_PREV, idStr:"button", bDefLabel:"<<Prev", bLabelParenFlag:false, parenLabel:"(0)", bBttnDisabled:false,},
    {id:BTN_NEXT, idStr:"button", bDefLabel:"Next>>", bLabelParenFlag:false, parenLabel:"(0)", bBttnDisabled:false,},
    {id:BTN_ACCEPT, idStr:"button", bDefLabel:"Accept", bLabelParenFlag:false, parenLabel:"(%d)", bBttnDisabled:false,},
    {id:BTN_ACCEPT_ALL, idStr:"button", bDefLabel:"Accept.All", bLabelParenFlag:false, parenLabel:"(%d)", bBttnDisabled:false,},
    {id:BTN_REJECT, idStr:"button", bDefLabel:"Reject", bLabelParenFlag:false, parenLabel:"(%d)", bBttnDisabled:false,},
    {id:BTN_REJECT_ALL, idStr:"button", bDefLabel:"Reject.All", bLabelParenFlag:false, parenLabel:"(%d)", bBttnDisabled:false,},
    {id:BTN_COMMIT, idStr:"button", bDefLabel:"Commit", bLabelParenFlag:false, parenLabel:"(Update)", bBttnDisabled:false,},
];
function doModal(id, htmlContent, resultMapObj, outputEditorControl) {
    let windowID = document.getElementById("window" + id);
    var footerModalCtl = document.getElementById("window" + id+"footer");
    var bodyModalCtl = document.getElementById("mainWindowModal"+id);
    var headCloseModalCtl = document.getElementById("closeButton"+id);
    bodyModalCtl.innerHTML = htmlContent;
    headCloseModalCtl.innerHTML = "x";
    fadeIn(windowID);
    fadeIn(footerModalCtl);
    fadeIn(bodyModalCtl);
    g_ResultObj = resultMapObj;
    g_outputEditorControl = outputEditorControl;

    var inpSel = document.getElementById('categoryLocatorSelect'), opt = null, textNode=null, textNode2 = null, labelNode=null;
    while (inpSel.options.length > 0) {                
        inpSel.remove(0);
    } 
    for (var i = 0; i< g_ResultObj.categoriesChange.length; i++)
    {
        opt = document.createElement("option");
        opt.setAttribute("value", g_ResultObj.categoriesChange[i].catLocatorInMapChangesArr);
        opt.setAttribute("id", "catSelCh_"+String(i));
        textNode = document.createTextNode(g_ResultObj.categoriesChange[i].categoryStr);
        opt.appendChild(textNode);
        inpSel.appendChild(opt);
    }
    g_catCurCatSel = g_catDefCatSel;

    setButtonStatus (true, false, true);// this function will also call updateButtonLabels ();
    onEnableCatBrowse('enableCatBrowse','categoryLocatorSelect');
    showNextChange ("mainWindowModal"+id, 1); // scroll to the first change

}
function setButtonStatus (bAll, bDisable, bDefault, bBttnIDListArr) {
    if (bAll == false && Array.isArray(bBttnIDListArr) == false) return;
    if (bAll){
        for (var i=0; i<g_actionButtonDetailsObjArr.length;i++) {
            g_actionButtonDetailsObjArr[i].bBttnDisabled = bDefault? false:bDisable;
            }
    } else {
        for (var bBttnReq=0; bBttnReq<bBttnIDListArr.length;bBttnReq++) {
            for (var i=0; i<g_actionButtonDetailsObjArr.length;i++) {
                if (bBttnIDListArr[bBttnReq] == g_actionButtonDetailsObjArr[i].id) {
                    g_actionButtonDetailsObjArr[i].bBttnDisabled = bDefault? false:bDisable;
                    break;
                }
            }
        }
    }
    updateButtonLabels ();
}
function updateButtonLabels () {
    var button_ctl = null, bttnNo=0, bttnLabel = "", bttnParenNum = 0, bttnParenNumOffset_acc = 0, bttnParenNumOffset_Rej = 0, bBttnDisabled = false;
    if (g_bBrowseByCat == true){
            bttnParenNum = g_ResultObj.categoriesChange[g_catCurCatSel].numItemsChanged;
            bttnParenNumOffset_acc = g_ResultObj.categoriesChange[g_catCurCatSel].numAccepted;
            bttnParenNumOffset_Rej = g_ResultObj.categoriesChange[g_catCurCatSel].numRejected;
        }else {
            bttnParenNum = g_ResultObj.nChangesMade_Total; // in this case browse through all categories and add up accepted and rejected
            for (var i = 0; i< g_ResultObj.categoriesChange.length; i++)
            {
                bttnParenNumOffset_acc += g_ResultObj.categoriesChange[i].numAccepted;
                bttnParenNumOffset_Rej += g_ResultObj.categoriesChange[i].numRejected;
                }        
        }
    while(bttnNo<g_actionButtonDetailsObjArr.length && (button_ctl = document.getElementById(g_actionButtonDetailsObjArr[bttnNo].idStr + g_actionButtonDetailsObjArr[bttnNo].id))!=null){
        bttnLabel = g_actionButtonDetailsObjArr[bttnNo].bLabelParenFlag == false? 
            g_actionButtonDetailsObjArr[bttnNo].bDefLabel
            :g_actionButtonDetailsObjArr[bttnNo].bDefLabel+g_actionButtonDetailsObjArr[bttnNo].parenLabel;
        if (g_actionButtonDetailsObjArr[bttnNo].id == BTN_ACCEPT)
            bttnLabel = bttnLabel.replace(/\%d/gi,String(g_ResultObj.currentMapLocator));
        if (g_actionButtonDetailsObjArr[bttnNo].id == BTN_REJECT)
            bttnLabel = bttnLabel.replace(/\%d/gi,String(g_ResultObj.currentMapLocator));
        if (g_actionButtonDetailsObjArr[bttnNo].id == BTN_ACCEPT_ALL)
            bttnLabel = bttnLabel.replace(/\%d/gi,String(bttnParenNum - bttnParenNumOffset_acc));
        if (g_actionButtonDetailsObjArr[bttnNo].id == BTN_REJECT_ALL)
            bttnLabel = bttnLabel.replace(/\%d/gi,String(bttnParenNum - bttnParenNumOffset_Rej));
        button_ctl.innerText = bttnLabel;
        bBttnDisabled = g_actionButtonDetailsObjArr[bttnNo].bBttnDisabled;
        button_ctl.setAttribute("disabled", bBttnDisabled);
        if (bBttnDisabled) { 
            button_ctl.style.background = "grey";
            button_ctl.style.color = "white";
        }else{
            button_ctl.style.background = "black";
            button_ctl.style.color = "yellow";
        }
        bttnNo++;

    }    
}
function createModalWindow(windowGroupClassNameStr, windowClassStr, bInitialShow, windowIDToShow){
    const lastWindow = document.getElementsByClassName(windowGroupClassNameStr)[0].lastElementChild.id.substring(6);
    g_activePopupClass = document.getElementsByClassName(windowClassStr);

    for (let i = 1; i <= lastWindow; i++) {
        createWindow(i, bInitialShow);
    }
}
function createWindow(id, bInitialShow) {
    let windowID = document.getElementById("window" + id);
    let headerID = windowID.firstElementChild;
    headerID.id = "window" + id + "header";
    headerID.style = "flex";

    let createCloseButton = document.createElement("b");
    createCloseButton.id = "closeButton" + id;
    createCloseButton.innerHTML = "x";
    headerID.appendChild(createCloseButton);
    let footerID = windowID.lastElementChild;
    footerID.id = "window" + id + "footer";
    footerID.style = "flex";
    var button_ctl = null, bttnNo=0;
    while(bttnNo<g_actionButtonDetailsObjArr.length && (button_ctl = document.getElementById(g_actionButtonDetailsObjArr[bttnNo].idStr + g_actionButtonDetailsObjArr[bttnNo].id))!=null){
        button_ctl.style.cursor= "pointer";
        button_ctl.style.background = "black";
        button_ctl.style.color = "yellow";
        button_ctl.style.padding = "3px";
        button_ctl.style.borderColor = "cyan";
        button_ctl.style.borderStyle = "double";
        button_ctl.innerText = g_actionButtonDetailsObjArr[bttnNo].bLabelParenFlag == false? 
        g_actionButtonDetailsObjArr[bttnNo].bDefLabel
        :g_actionButtonDetailsObjArr[bttnNo].bDefLabel+g_actionButtonDetailsObjArr[bttnNo].parenLabel;
        bttnNo++;
    }

    document.getElementById("closeButton" + id).onclick = function (e) {
        var closeCtl = e.target, bShow = false, bodyModalCtl = document.getElementById("mainWindowModal"+id), footerModalCtl = document.getElementById("window" + id+"footer");
        if (closeCtl.innerHTML=="x"){
            closeCtl.innerHTML = "v";
            fadeOut(footerModalCtl);
            fadeOut(bodyModalCtl);
        }else {
            closeCtl.innerHTML = "x";
            fadeIn(footerModalCtl);
            fadeIn(bodyModalCtl);
        }
    };
    dragElement(windowID);
    bInitialShow ? fadeIn (windowID):fadeOut (windowID);
}
function acceptRejectChange (modalWindowCtlStr, acceptRejectThisStr, bAcceptAll){
    var modalWindowCtl = document.getElementById(modalWindowCtlStr);
    var curCtls_obj = null, elmID_orjStrTag = "", elmID_orjStr = "", elmID_repStrTag = "", elmID_repStr = "", curOrgCtl = null, curRepCtl = null;
    var start= 0, end=0, i = 0, bAcceptThis = true;

    curCtls_obj = g_ResultObj.mapChangeIDLoc[g_ResultObj.currentMapLocator]; // get current location control's information
    elmID_orjStrTag = curCtls_obj.elmID_orjStrTag;
    elmID_orjStr = curCtls_obj.elmID_orjStr;
    elmID_repStrTag = curCtls_obj.elmID_repStrTag;
    elmID_repStr = curCtls_obj.elmID_repStr;

    bAcceptThis = acceptRejectThisStr.toLowerCase()=="acceptthis";
    if (bAcceptAll == true) {
        if (g_bBrowseByCat){
            start = g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].catStartLoc;
            end = g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].catEndLoc;
            if (bAcceptThis) {        
                g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numAccepted = g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numItemsChanged;
                g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numRejected = 0;                
            } else {
                g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numRejected = g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numItemsChanged;
                g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numAccepted = 0;
            }
        } else {
                start = 0;
                end = g_ResultObj.nChangesMade_Total-1;
                g_ResultObj.bAllChangesReadyToCommit = true;
                // reset all the individual categories accepted flags
                for (i=0; i<g_ResultObj.categoriesChange.length; i++){
                    if (bAcceptThis) {        
                        g_ResultObj.categoriesChange[i].numAccepted = g_ResultObj.categoriesChange[i].numItemsChanged;
                    } else {
                        g_ResultObj.categoriesChange[i].numRejected = g_ResultObj.categoriesChange[i].numItemsChanged;
                    }
                }
            }
        if (bAcceptThis) {        
            setButtonStatus (false, true, false, [BTN_PREV, BTN_NEXT, BTN_ACCEPT, BTN_REJECT, BTN_ACCEPT_ALL]);//disable all others including accept all
            setButtonStatus (false, false, false, [BTN_REJECT_ALL]);//enable reject all
        } else {
            setButtonStatus (false, true, false, [BTN_PREV, BTN_NEXT, BTN_ACCEPT, BTN_REJECT, BTN_REJECT_ALL]);//disable all others including reject all
            setButtonStatus (false, false, false, [BTN_ACCEPT_ALL]);//enable accept all
        }
    } else {
        start = g_ResultObj.currentMapLocator;
        end = start;
        if (bAcceptThis) {        
            g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numAccepted++;
            g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numRejected--;                
        } else {
            g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numRejected++;
            g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numAccepted--;
        }
        if (g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numAccepted >= g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numItemsChanged) {
            g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numAccepted = g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numItemsChanged;
            if (bAcceptThis) {        
                setButtonStatus (false, true, false, [BTN_PREV, BTN_NEXT, BTN_ACCEPT, BTN_REJECT, BTN_ACCEPT_ALL]);//disable all others including accept all
                setButtonStatus (false, false, false, [BTN_REJECT_ALL]);//enable reject all
            } else {
                setButtonStatus (false, true, false, [BTN_PREV, BTN_NEXT, BTN_ACCEPT, BTN_REJECT, BTN_REJECT_ALL]);//disable all others including reject all
                setButtonStatus (false, false, false, [BTN_ACCEPT_ALL]);//enable accept all
            }
        } else if (g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numAccepted < 0)
            g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numAccepted = 0;
        if (g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numRejected >= g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numItemsChanged) {
            g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numRejected = g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numItemsChanged;
            if (bAcceptThis) {        
                setButtonStatus (false, true, false, [BTN_PREV, BTN_NEXT, BTN_ACCEPT, BTN_REJECT, BTN_ACCEPT_ALL]);//disable all others including accept all
                setButtonStatus (false, false, false, [BTN_REJECT_ALL]);//enable reject all
            } else {
                setButtonStatus (false, true, false, [BTN_PREV, BTN_NEXT, BTN_ACCEPT, BTN_REJECT, BTN_REJECT_ALL]);//disable all others including reject all
                setButtonStatus (false, false, false, [BTN_ACCEPT_ALL]);//enable accept all
            }
        } else if (g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numRejected < 0)
            g_ResultObj.categoriesChange[curCtls_obj.categoryLocator].numRejected = 0;


        updateButtonLabels ();
    }
    for (var i=start; i<=end; i++) {
        curCtls_obj = g_ResultObj.mapChangeIDLoc[i];
        elmID_orjStrTag = curCtls_obj.elmID_orjStrTag;
        elmID_orjStr = curCtls_obj.elmID_orjStr;
        elmID_repStrTag = curCtls_obj.elmID_repStrTag;
        elmID_repStr = curCtls_obj.elmID_repStr;

        curOrgCtl = modalWindowCtl.querySelector(elmID_orjStrTag+"#"+elmID_orjStr);
        curRepCtl = modalWindowCtl.querySelector(elmID_repStrTag+"#"+elmID_repStr);
        if (curOrgCtl == null || curRepCtl == null) return;
//        curOrgCtl.scrollIntoView({behavior: "smooth", block: "center", inline: "nearest"});
//        curOrgCtl.focus();
        if (bAcceptThis) {
            curOrgCtl.style.display = "none";
            curRepCtl.style.display = "initial"
            curOrgCtl.style.background = "none";
            curRepCtl.style.background = "lightGreen";

            curCtls_obj.bChangeAccepted = true;
            curCtls_obj.bChangeRejected = false;
            curCtls_obj.bReviewComplete = false;
            

            } else {
                curOrgCtl.style.display = "initial";
                curRepCtl.style.display = "none"
                curOrgCtl.style.background = "lightBlue";
                curRepCtl.style.background = "none";

                curCtls_obj.bChangeAccepted = false;
                curCtls_obj.bChangeRejected = true;
                curCtls_obj.bReviewComplete = false;
                }
        curOrgCtl.style.borderStyle = "none";
        curRepCtl.style.borderStyle = "none";
        curOrgCtl.style.textDecoration = "none";
        curRepCtl.style.textDecoration = "none";
    }
    //g_catCurCatSel = categoryLocatorSelectCtl.selectedIndex;
}
function commitAndUpdateChange (modalWindowCtlStr){
    var modalWindowCtl = document.getElementById(modalWindowCtlStr);

    var tempStr = "",  promptStr = "All changes will be finalized now. Output control will be updated now." ;
    var curCtls_obj = null, elmID_orjStrTag = "", elmID_orjStr = "", elmID_repStrTag = "", elmID_repStr = "", curOrgCtl = null, curRepCtl = null;
    tempStr = prompt (promptStr, "Ok to proceed and cancel to continue edits.", "Confirm");
    if (tempStr == null) {
        return;
    }
    for (var i=0; i<g_ResultObj.mapChangeIDLoc.length; i++) {
        curCtls_obj = g_ResultObj.mapChangeIDLoc[i];
        elmID_orjStrTag = curCtls_obj.elmID_orjStrTag;
        elmID_orjStr = curCtls_obj.elmID_orjStr;
        elmID_repStrTag = curCtls_obj.elmID_repStrTag;
        elmID_repStr = curCtls_obj.elmID_repStr;

        curOrgCtl = modalWindowCtl.querySelector(elmID_orjStrTag+"#"+elmID_orjStr);
        curRepCtl = modalWindowCtl.querySelector(elmID_repStrTag+"#"+elmID_repStr);
        
        curOrgCtl.scrollIntoView({behavior: "smooth", block: "center", inline: "nearest"});
        curOrgCtl.focus();
        if (curOrgCtl.style.display == "none") {
            curOrgCtl.innerText = "";
        }
        if (curRepCtl.style.display == "none") {
            curRepCtl.innerText = "";
        }
    }
    var outputStr = modalWindowCtl.innerHTML = modalWindowCtl.innerHTML.replace(RegExp(g_ResultObj.padCharToRemove,"g"), "");
    getSetContent_TextAreas_Adv (g_outputEditorControl, false, outputStr, true, modalWindowCtl);

    modalWindowCtl.innerHTML = "All review complete!";
    //setButtonStatus (true, false, true);
}
function updateCatDescription(){
    
}
function onEnableCatBrowse(enableCatBrowseStr,categoryLocatorSelectStr){
    var enableCatBrowseCtl= document.getElementById(enableCatBrowseStr);
    var categoryLocatorSelectCtl = document.getElementById(categoryLocatorSelectStr);

    if (enableCatBrowseCtl.checked) {
        g_bBrowseByCat = true;
        categoryLocatorSelectCtl.disabled = false;
        //var jumpLoc = categoryLocatorSelectCtl.options[categoryLocatorSelectCtl.selectedIndex].value;
        g_ResultObj.currentMapLocator = g_ResultObj.categoriesChange[categoryLocatorSelectCtl.selectedIndex].catStartLoc;
        g_ResultObj.nextMapLocator = g_ResultObj.currentMapLocator;
        g_ResultObj.prevMapLocator = g_ResultObj.categoriesChange[categoryLocatorSelectCtl.selectedIndex].catEndLoc;    
        onCategoryLocatorSelect(categoryLocatorSelectStr);
    } else {
        g_bBrowseByCat = false;
        categoryLocatorSelectCtl.disabled = true;
        if (g_ResultObj.bAllChangesReadyToCommit == false) {
            g_ResultObj.currentMapLocator = 0;
            g_ResultObj.nextMapLocator = g_ResultObj.currentMapLocator;
        
            g_ResultObj.prevMapLocator = g_ResultObj.nChangesMade_Total;
            g_catCurCatSel = categoryLocatorSelectCtl.selectedIndex;
            setButtonStatus (false, false, false, [BTN_PREV, BTN_NEXT, BTN_ACCEPT, BTN_REJECT]); // enable the controls for this category
            } else {
                setButtonStatus (false, true, false, [BTN_PREV, BTN_NEXT, BTN_ACCEPT, BTN_REJECT]); // disable the prev/next controls
            }
    }
//    showNextChange ("mainWindowModal1", 1); // scroll to the first change
}
function onCategoryLocatorSelect(categoryLocatorSelectStr){
    var categoryLocatorSelectCtl = document.getElementById(categoryLocatorSelectStr);
    g_catCurCatSel = categoryLocatorSelectCtl.selectedIndex;
    var labelNode = null;
    labelNode = document.getElementById("toolTipText1");
    labelNode.innerHTML = g_ResultObj.categoriesChange[g_catCurCatSel].tooltipText_Desc;

    if (g_ResultObj.categoriesChange[g_catCurCatSel].numAccepted == g_ResultObj.categoriesChange[g_catCurCatSel].numItemsChanged){
        setButtonStatus (false, true, false, [BTN_PREV, BTN_NEXT, BTN_ACCEPT, BTN_REJECT, BTN_ACCEPT_ALL]);//disable all others including accept all
        setButtonStatus (false, false, false, [BTN_REJECT_ALL]);//enable reject all
        } else {
            if(g_ResultObj.categoriesChange[g_catCurCatSel].numRejected == 0)
                setButtonStatus (false, false, false, [BTN_PREV, BTN_NEXT, BTN_ACCEPT, BTN_REJECT, BTN_ACCEPT_ALL]);//enable all others including accept all
        }
    if (g_ResultObj.categoriesChange[g_catCurCatSel].numRejected == g_ResultObj.categoriesChange[g_catCurCatSel].numItemsChanged) {
        setButtonStatus (false, true, false, [BTN_PREV, BTN_NEXT, BTN_ACCEPT, BTN_REJECT, BTN_REJECT_ALL]);//disable all others including reject all
        setButtonStatus (false, false, false, [BTN_ACCEPT_ALL]);//enable accept all
        } else {
            if (g_ResultObj.categoriesChange[g_catCurCatSel].numAccepted == 0)
                setButtonStatus (false, false, false, [BTN_PREV, BTN_NEXT, BTN_ACCEPT, BTN_REJECT, BTN_REJECT_ALL]);//disable all others including accept all
        }
g_ResultObj.currentMapLocator = g_ResultObj.categoriesChange[categoryLocatorSelectCtl.selectedIndex].catStartLoc;
    g_ResultObj.nextMapLocator = g_ResultObj.currentMapLocator+1;
    g_ResultObj.prevMapLocator = g_ResultObj.categoriesChange[categoryLocatorSelectCtl.selectedIndex].catEndLoc;
    setFocusOnCurrentChange ("mainWindowModal1");
    adjustMapLocators ();

//    showNextChange ("mainWindowModal1", 1); // scroll to the first change
}
function setFocusOnCurrentChange (modalWindowCtlStr) {
    var modalWindowCtl = document.getElementById(modalWindowCtlStr);
    var curCtls_obj = g_ResultObj.mapChangeIDLoc[g_ResultObj.currentMapLocator]; // get current location control's information
    var elmID_orjStrTag = "", elmID_orjStr = "", elmID_repStrTag = "", elmID_repStr = "", curOrgCtl = null, curRepCtl = null;
    var elmID_TTTextStr ="", elmID_TTTextTag ="", tt_Ctl = null, curCat_obj = null;

    elmID_orjStrTag = curCtls_obj.elmID_orjStrTag;
    elmID_orjStr = curCtls_obj.elmID_orjStr;
    elmID_repStrTag = curCtls_obj.elmID_repStrTag;
    elmID_repStr = curCtls_obj.elmID_repStr;

    curOrgCtl = modalWindowCtl.querySelector(elmID_orjStrTag+"#"+elmID_orjStr);
    curRepCtl = modalWindowCtl.querySelector(elmID_repStrTag+"#"+elmID_repStr);
    curCat_obj = g_ResultObj.categoriesChange[curCtls_obj.categoryLocator];
    elmID_TTTextTag = curCat_obj.elmID_toolTipTag;
    elmID_TTTextStr = curCtls_obj.elmID_toolTipStr;
    tt_Ctl = modalWindowCtl.querySelector(elmID_TTTextTag+"#"+elmID_TTTextStr);
    tt_Ctl.style.top="95%";
    g_ResultObj.curOrgCtl = curOrgCtl;
    g_ResultObj.curRepCtl = curRepCtl;


    g_ResultObj.curOrgCtl.scrollIntoView({behavior: "smooth", block: "center", inline: "nearest"});
    g_ResultObj.curOrgCtl.focus();
    if (!(curCtls_obj.bChangeAccepted == false && curCtls_obj.bChangeRejected == false)){
        if (curCtls_obj.bChangeAccepted == true) {
            g_ResultObj.curRepCtl.style.display = "initial";
        } else if (curCtls_obj.bChangeRejected == true) {
            g_ResultObj.curOrgCtl.style.display = "initial";
        }
        g_ResultObj.curOrgCtl.scrollIntoView({behavior: "smooth", block: "center", inline: "nearest"});
        g_ResultObj.curOrgCtl.focus();
        return;
    }
    g_ResultObj.curOrgCtl.style.display = "initial";
    g_ResultObj.curRepCtl.style.display = "initial"
    g_ResultObj.curOrgCtl.scrollIntoView({behavior: "smooth", block: "center", inline: "nearest"});
    g_ResultObj.curOrgCtl.focus();
    g_ResultObj.curOrgCtl.style.background = "cyan";
    g_ResultObj.curRepCtl.style.background = "yellow";
    g_ResultObj.curOrgCtl.style.borderStyle = "dotted";
    g_ResultObj.curRepCtl.style.borderStyle = "solid";

    if (g_ResultObj.prevRepCtl!=null && g_ResultObj.prevOrgCtl!=null && g_ResultObj.prevRepCtl!=g_ResultObj.curRepCtl && g_ResultObj.prevOrgCtl!=g_ResultObj.curOrgCtl) {
        g_ResultObj.prevOrgCtl.style.background = "none";
        g_ResultObj.prevRepCtl.style.background = "none";    
        g_ResultObj.prevOrgCtl.style.borderStyle = "none";
        g_ResultObj.prevRepCtl.style.borderStyle = "none";
        }
    g_ResultObj.prevOrgCtl = g_ResultObj.curOrgCtl;
    g_ResultObj.prevRepCtl = g_ResultObj.curRepCtl;
    //tt_Ctl.innerHTML = curCat_obj.tooltipText_Desc;




}
function adjustMapLocators () {
    if (g_bBrowseByCat==false) {
        if (g_ResultObj.nextMapLocator>=g_ResultObj.nChangesMade_Total) {
            g_ResultObj.nextMapLocator = 0; // wrap around
        }
        if (g_ResultObj.prevMapLocator<0) {
            g_ResultObj.prevMapLocator = g_ResultObj.nChangesMade_Total-1; // wrap around
        }
    } else {
        var catStart = g_ResultObj.categoriesChange[g_ResultObj.mapChangeIDLoc[g_ResultObj.currentMapLocator].categoryLocator].catStartLoc;
        var catEnd = g_ResultObj.categoriesChange[g_ResultObj.mapChangeIDLoc[g_ResultObj.currentMapLocator].categoryLocator].catEndLoc;
        if (g_ResultObj.nextMapLocator>catEnd) {
            g_ResultObj.nextMapLocator = catStart; // wrap around
        }
        if (g_ResultObj.prevMapLocator<catStart) {
            g_ResultObj.prevMapLocator = catEnd; // wrap around
        }
    }
}
function showNextChange (modalWindowCtlStr, nDirection){

    nDirection>=0 ? 
    g_ResultObj.currentMapLocator = g_ResultObj.nextMapLocator
    :g_ResultObj.currentMapLocator = g_ResultObj.prevMapLocator;
    if (g_ResultObj.currentMapLocator == -1 || g_ResultObj.currentMapLocator >= g_ResultObj.mapChangeIDLoc.length) {
        // reset the locators and return
        g_ResultObj.currentMapLocator = g_ResultObj.nextMapLocator = g_ResultObj.prevMapLocator = 0;
        return;
    }
    var curCtls_obj = g_ResultObj.mapChangeIDLoc[g_ResultObj.currentMapLocator]; // get current location control's information

    if (!(curCtls_obj.bChangeAccepted == false && curCtls_obj.bChangeRejected == false)){
        nDirection>0?g_ResultObj.nextMapLocator = g_ResultObj.currentMapLocator+1:
        g_ResultObj.prevMapLocator = g_ResultObj.currentMapLocator-1;
        adjustMapLocators ();
        if (g_ResultObj.bAllChangesReadyToCommit == false)
            showNextChange (modalWindowCtlStr, nDirection);
        return;
            
    }
    setFocusOnCurrentChange (modalWindowCtlStr);
    g_ResultObj.nextMapLocator = g_ResultObj.currentMapLocator+1;
    g_ResultObj.prevMapLocator = g_ResultObj.currentMapLocator-1;
    adjustMapLocators ();

}
function dragElement(elmnt) {
    var pos1 = 0,
        pos2 = 0,
        pos3 = 0,
        pos4 = 0;
    if ("ontouchstart" in document.documentElement) {
        var pos1touch = 0,
            pos2touch = 0,
            pos3touch = 0,
            pos4touch = 0;
    }
    if (document.getElementById(elmnt.id + "header")) {
        document.getElementById(elmnt.id + "header").onmousedown = dragMouseDown;
        document.getElementById(elmnt.id + "header").ontouchstart = dragMouseDown;
    }

    function dragMouseDown(e) {
        if (!"ontouchstart" in document.documentElement) {
            e.preventDefault();
        }
        pos3 = e.clientX;
        pos4 = e.clientY;
        if ("ontouchstart" in document.documentElement) {
            try {
                pos3touch = e.touches[0].clientX;
                pos4touch = e.touches[0].clientY;
            } catch(error) {}
        }
        document.onmouseup = closeDragElement;
        document.onmousemove = elementDrag;
        document.ontouchend = closeDragElement;
        document.ontouchmove = elementDrag;
        activeWindow(document.getElementById(elmnt.id));
    }

    function elementDrag(e) {
        e.preventDefault();
        var tmpLeft = 10, tmpTop = 10;  
        if ("ontouchstart" in document.documentElement) {
            pos1touch = pos3touch - e.touches[0].clientX;
            pos2touch = pos4touch - e.touches[0].clientY;
            pos3touch = e.touches[0].clientX;
            pos4touch = e.touches[0].clientY;
            tmpTop = (elmnt.offsetTop - pos2touch);
            tmpLeft = (elmnt.offsetLeft - pos1touch);
        } else {
            pos1 = pos3 - e.clientX;
            pos2 = pos4 - e.clientY;
            pos3 = e.clientX;
            pos4 = e.clientY;
            tmpTop = (elmnt.offsetTop - pos2);
            tmpLeft = (elmnt.offsetLeft - pos1);
        }
        elmnt.style.top = tmpTop>10?1:tmpTop + "px";
        elmnt.style.left = tmpLeft>10?10:tmpLeft + "px";
//        elmnt.style.display = "block";
}

    function closeDragElement() {
        document.onmouseup = null;
        document.onmousemove = null;
        document.ontouchend = null;
        document.ontouchmove = null;
    }
}

function fadeIn(elmnt) {
    elmnt.style.opacity = 0;
    elmnt.style.display = "block";
    if (elmnt.classList.contains("fade")) {
        var opacity = 0;
        var timer = setInterval(function () {
            opacity += 30 / 70;
            if (opacity >= 1) {
                clearInterval(timer);
                opacity = 0.9;
            }
            elmnt.style.opacity = opacity;
            activeWindow(elmnt);
        }, 50);
    } else {
        elmnt.style.opacity = "0.9";
        activeWindow(elmnt);
    }
}

function fadeOut(elmnt) {
    if (elmnt.classList.contains("fade")) {
        var opacity = 1;
        var timer = setInterval(function () {
            opacity -= 30 / 70;
            if (opacity <= 0) {
                clearInterval(timer);
                opacity = 0;
                elmnt.style.display = "none";
            }
            elmnt.style.opacity = opacity;
        }, 50);
    } else {
        elmnt.style.display = "none";
        activeWindow(elmnt);
    }
}

function activeWindow(elmnt) {
    for (let i = g_activePopupClass.length - 1; i > -1; i--) {
        g_activePopupClass[i].classList.remove("windowActive");
        elmnt.className += " windowActive";
    }
}
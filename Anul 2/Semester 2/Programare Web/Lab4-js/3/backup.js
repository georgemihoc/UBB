let cells = document.getElementsByClassName('cell');
let elements = document.getElementsByClassName('elem');

let opened = [];
var gasit  = false;

function start() {
    opened = [];
    for(let i = 0; i < cells.length; i++) {
        cells[i].onclick = function () {
            showCell(i);
        };
    }
    flash();

}
function showCell(i) {

    if(elements[i].style.visibility === "hidden" && opened.length < 2) {
        if(opened.length === 0)
            gasit = false;
        opened.push(i);
        elements[i].style.visibility = "visible";
        var timeouts = [];
//then, store when you create them
        timeouts.push(
            setTimeout(function () {
                if (gasit === false) {
                    elements[i].style.visibility = "hidden";
                }
                setTimeout(function () {
                    opened =[]
                },30);
                // opened=[]
            }, 500));
        if(opened.length === 2) {
            if (elements[opened[0]].innerHTML === elements[opened[1]].innerHTML) {
                gasit = true;
            }
            else{
                gasit = false;
            }
        }
    }
}
function flash() {
    for(i=0; i<elements.length; i++) {
        elements[i].style.visibility = "visible";
    }
    setTimeout(function(){
        for(i=0; i<elements.length; i++) {
            elements[i].style.visibility = "hidden";
        }
    }, 1000)
}

//Remove double-clicked element from the selected list and add it to the other list
function myFunction(id1,id2) {

    var list1 = document.getElementById(id1);
    var list2 = document.getElementById(id2);

    var option = document.createElement("option");
    option.text = list1.options[list1.selectedIndex].text;;
    list2.add(option);
    list1.remove(list1.selectedIndex);
}
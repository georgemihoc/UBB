function tableSort(n) {
    var table, columns, switching, i, x, y, swap;
    table = document.getElementById("tableId");
    switching = true;
    while (switching) {
        switching = false;
        columns = table.rows[n].cells;
        for (i = 1; i < (columns.length - 1); i++) {
            swap = false;

            x = columns[i];
            y = columns[i + 1];
            // alert(x.textContent);

            if (x.textContent > y.textContent) {
                swap= true;
                break;
            }
        }
        if (swap) {
            columns[i].parentNode.insertBefore(columns[i + 1], columns[i]);

            switching = true;
        }
    }
}
function getAllCells(table) {
    var result = [];

    for(var i = 0, j = 0, l = table.rows.length, l2 = 0; i < l; i++) {
        for(j = 0, l2 = table.rows[i].cells.length; j < l2; j++) {
            result.push(table.rows[i].cells[j].innerText);
        }
    }

    return result.join(',');
}
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

            if (x.innerHTML > y.innerHTML) {
                swap= true;
                switching = true;
                swapColumns(table,i,i+1);
                break;
            }
        }
    }
}

function swapColumns (table, colIndex1, colIndex2) {
    if (table && table.rows && table.insertBefore && colIndex1 !==colIndex2) {
        for (var i=0, len=table.rows.length; i<len; ++i) {
            var row = table.rows[i];
            var cell1 = row.cells[colIndex1];
            var cell2 = row.cells[colIndex2];
            row.insertBefore(cell2, cell1);
            row.insertBefore(cell1, row.cells[colIndex2]);
        }
    }
}

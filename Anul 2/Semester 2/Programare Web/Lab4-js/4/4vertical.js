var direction = 1;
function tableSort(n) {
    var table, rows, switching, i, x, y,swap;
    table = document.getElementById("tableId");
    switching = true;
    // direction = 1;
    while (switching) {
        switching = false;
        rows = table.rows;
        for (i = 1; i < (rows.length - 1); i++) {
            swap = false;
            x = rows[i].getElementsByTagName("td")[n];
            y = rows[i + 1].getElementsByTagName("td")[n];
            if(direction === 1) {
                if (x.innerHTML > y.innerHTML) {
                    swap = true;
                    break;
                }
            }else if (direction === -1){
                if (x.innerHTML < y.innerHTML) {
                    swap = true;
                    break;
                }
            }
        }
        if (swap) {
            rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);
            switching = true;
        }
    }
    if(direction === 1){
        direction = -1;
    }
    else direction = 1;
}
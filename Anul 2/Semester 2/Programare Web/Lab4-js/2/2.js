function validateForm() {
    var name = document.forms["myForm"]["fname"].value;
    var date = document.forms["myForm"]["fdate"].value;
    var varsta = document.forms["myForm"]["fage"].value;
    var email = document.forms["myForm"]["femail"].value;
    var message = "Campurile";

    // alert(getAge(date))

    if (name === "") {
        document.forms["myForm"]["fname"].style.borderColor = "red";
        message = message.concat(" nume");
    }
    if (date === "") {
        document.forms["myForm"]["fdate"].style.borderColor = "red";
        if(message !== "Campurile")
            message = message.concat(" si data nasterii");
        else
        message = message.concat(" data nasterii")
    }
    if (varsta === "" || varsta < 1) {
        document.forms["myForm"]["fage"].style.borderColor = "red";
        if(message !== "Campurile")
            message = message.concat(" si varsta");
        else
            message = message.concat(" varsta")
    }
    if (emailCheck(email) === false) {
        document.forms["myForm"]["femail"].style.borderColor = "red";
        if(message !== "Campurile")
            message = message.concat(" si email");
        else
            message = message.concat(" email")
    }
    if(message !== "Campurile") {
        message = message.concat(" nu sunt completate sau  nu sunt completate corect")
        alert(message);
        return false;
    }
    if(parseInt(getAge(date)) !== parseInt(varsta)){
        document.forms["myForm"]["fage"].style.borderColor = "red";
        document.forms["myForm"]["fdate"].style.borderColor = "red";
        alert("Varsta nu corespunde datei de nastere")
        return false;
    }

    alert("Datele sunt completate corect")
}
function getAge(dateString) {
    var today = new Date();
    var birthDate = new Date(dateString);
    var age = today.getFullYear() - birthDate.getFullYear();
    var m = today.getMonth() - birthDate.getMonth();
    if (m < 0 || (m === 0 && today.getDate() < birthDate.getDate())) {
        age--;
    }
    return age;
}
function emailCheck(email) {
    return email.includes("@");
}
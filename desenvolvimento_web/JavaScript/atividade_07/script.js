function ajax(nome, camada) {
    let url = 'https://httpbin.org/get?text=' + nome;
    let xmlhttp = new XMLHttpRequest();
    xmlhttp.onreadystatechange = function() {
        if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
            let resp = xmlhttp.responseText;
            document.getElementById(camada).innerHTML = resp;
        }
    }
    xmlhttp.open("GET", url, true);
    xmlhttp.send();
}
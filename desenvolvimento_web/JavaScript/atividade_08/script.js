const url = 'https://randomuser.me/api/?results=10'; //randomuser é uma API gratuita que gera dados (fake) de usuários aleatórios
//"results=10" no final da url, significa que vc está solicitando dados de 10 usuários

async function getUsers(lista) {
    const resp = await fetch(url);
    const objeto = await resp.json();
    let itens = "";
    for(let pessoa of objeto.results){
        itens += `<li>${pessoa.name.first} ${pessoa.name.last}</li>`;
    }
    document.getElementById(lista).innerHTML = itens;
}
firebase.database().ref("Capacidad").on("child_changed",function(s) {
    $('#personas').empty();
    user = s.val();
    $('#personas').append(user+"/5")
    console.log(user)
    porc = 100/5*user 
    bporc = 180/5*user
    barra = '<div class="barra" style = "transform: rotate('+bporc+'deg);"><div class="cont" style="background-color: rgb(230, 225, 225);"></div><div class="cont" style="background-color: rgb(87, 219, 105);"></div></div>'
    $('#porcentaje').empty();
    $('#porcentaje').append(porc+'%')
    $('#bporcentaje').empty();
    $('#bporcentaje').append(barra);
})

firebase.database().ref("Capacidad").on("child_added",function(s) {
    $('#personas').empty();
    user = s.val();
    $('#personas').append(user+"/5")
    porc = 100/5*user
    bporc = 180/5*user
    barra = '<div class="barra" style = "transform: rotate('+bporc+'deg);"><div class="cont" style="background-color: rgb(230, 225, 225);"></div><div class="cont" style="background-color: rgb(87, 219, 105);"></div></div>'
    $('#porcentaje').empty();
    $('#porcentaje').append(porc+'%')
    $('#bporcentaje').empty();
    $('#bporcentaje').append(barra);
})

$('#reinicio').click(function(){
    firebase.database().ref("Capacidad")
    .set({
        Contador: 0,
        });  
});


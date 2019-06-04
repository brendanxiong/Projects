/*outputs to console in inspect element

function sayHelloWorld() {
    console.log("Hello world")
}

sayHelloWorld()
sayHelloWorld() //can also call this in function

//try to add a button to switch theme (use javascrip and css classes) - define two classes of stying one dark one light
//java script will swap out the classes

*/
function toggleDarkMode(){
    //1. find the section #dark-mode-section
   const section = document.getElementById('dark-mode-section')


    //console.log(section)        //no types in javascript
    //2. check if it has the .dark-mode class
    const inDarkMode = section.classList.contains('dark-mode');

    //2.1. If it does, remove it
    if (inDarkMode){
        section.classList.remove('dark-mode')
    }

    //2.2. If it doesn't, add it
    else{
        section.classList.add('dark-mode')
        document.body.style.backgroundColor = '#000000'
    }
}

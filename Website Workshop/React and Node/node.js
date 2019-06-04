//create a variable in javascript (no type) (node is javascript interpreter)

var x = "Hello World"
var y = "GoodBye"

//how to log things into console 
console.log(x)

//do node index.js to run the file

//arrays are dynamic in java
var myArray = ["Hello", "World", "awesome"]

//create an object (powerful) use curly braces
var myObject = {
    name: "Brendan Xiong",
    age: 19,
    graduated: false,        //these are all keyname types?? adding nested arrays after this, DON'T FORGET COMMA
    ClassesTaking: ["cs", "ling"]
}

//making functions
function printDetails() {
    console.log("Hello from function printDetails")
}

//call function
printDetails()

//give function parameters, no need for type at first in javascript
function printDetails2(person){
    console.log("Hello from printDetails with person")
    console.log("Person's name is:", person.name)    //comma gives automatic space?
    console.log("Person's age is:", person.age)
}

printDetails2(myObject)
//myObject will print everything so specify the person


//powerful: javascript function arrays(?)
//loop print all array elements (use var for javascript key words)
/*
for (var i = 0; i< myArray.length; i++) {
    console.log(myArray[i])
}*/

//accepts as argument: every element in the array
function printElement(element){
    console.log(element)
}

function printElement2(element, idx) {
    if (idx % 2 === 0) {
        console.log(element, idx)       //use triple equal???
    }
}


myArray.forEach(printElement)        //forEach is method on arrays - you can pass something called a callBack, calls each element/acts on each element in array(?)
//so now no need for loop basically; javascript passes every element in the array to the function (printElement)


printElement("test", 4)
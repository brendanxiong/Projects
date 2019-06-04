console.log(mockHistory)
//code we write needs to loop through array
for (let i = 0; i <mockHistory.length; i +=1){
    const historyEvent = mockHistory[i]

    //make a div to represent each don't create each one in html (not scalable)

    //create the div with h1/p inside it
    //create div
    const eventDiv = document.createElement('div')


    //create h1
    const eventTitle = document.createElement('a')
    eventTitle.innerText =   historyEvent.title   //can use innerhtml too
    eventTitle.href = historyEvent.links.article   //adding links to title, must change h1 to a


    //create p 
    const eventDetails = document.createElement('p')//the <p> in html
    eventDetails.innerText = historyEvent.details


  


    //put the h1 and p inside div
    eventDiv.appendChild(eventTitle)
    eventDiv.appendChild(eventDetails)


  //2. insert this div inot the history-wrapper
   const wrapper =  document.getElementById('history-wrapper')  //stored history-wrapper using const wrapper

   wrapper.appendChild(eventDiv)

}
using System; 

//Namespace
namespace NumberGuesser
{
    // Main class
    class Program
    {
        // Entry pointmethod
        static void Main(string[] args)
        {
            /*
            string name = "Brendan Xiong";
            int age = 19;

            //   Console.WriteLine("Hello World");
            // Console.Write("Same Line Hello World");

            Console.WriteLine("Hello " + name);
            // Console.WriteLine("I am " + age + " years old");
            Console.WriteLine(name + " is " + age);

            //better way to do this
            Console.WriteLine("{0} is {1}", name, age);// so 0 referenced to name since name is first
            Console.WriteLine("{0} is {1} write {2}", name, "testing", age);*/

            //set app vars

            GetAppInfo();

            GreetUser();

            while (true)
            {


                //Set correct number
                // int correctNumber = 7;

                //create random object
                Random random = new Random();

                int correctNumber = random.Next(1, 10);

                // Init guess var
                int guess = 0;      //set to 0 by default (it's not between 1 and 10)

                // Ask user for guess

                // Doing it my own way now
                Console.ForegroundColor = ConsoleColor.Blue;
                Console.WriteLine("Guess an integer between 1 and 10");
                Console.ResetColor();

                // Need loop since if number doesn't match, ask again



                while (guess != correctNumber)
                {
                    //string input = Console.ReadLine(); //this is buggy but o well; jk not buggy
                    string input = Console.ReadLine(); //string here is better automatically inputs


                    if (!int.TryParse(input, out guess))
                    {
                        PrintColorMessage(ConsoleColor.Red, "Try again; not an integer");
                        continue;   //move through loop
                    }

                    guess = Int32.Parse(input);

                    if (guess != correctNumber)
                    {
                       PrintColorMessage(ConsoleColor.Red, "Try again; wrong number");
                    }

                    // input = Console.ReadLine();
                    //guess = Int32.Parse(input);

                    // Parse into integer (Cast to int and put in guess)
                    //IF STATEMENT   saying if guess != might be better because no neeed to take two
                    //input checks

                    // Match guess to correct Number 

                }

                //If correct
                PrintColorMessage(ConsoleColor.Green, "You guessed it");    //no inpute name for now {0}
             

                //Ask if would like to paly again
                Console.WriteLine("Play again? [Y or N]");
                string playAgain = Console.ReadLine().ToUpper();

                if (playAgain == "Y")
                {
                    continue;
                }
               
                else if(playAgain == "N")
                {
                    return; //returns outside loop
                }

                else
                {
                    return; //only continue if answer Y
                }
            }
 
        }


        //put functin outside main
        static void GetAppInfo()
        {
            string appName = "Number Guesser";
            string appVersion = "1.0.0";
            string appAuthor = "Brendan Xiong";

            // Change text color (comment for every single line of code is good)
            Console.ForegroundColor = ConsoleColor.DarkGreen;

            // Write out app info
            Console.WriteLine("{0}: Version: {1} by {2}", appName, appVersion, appAuthor);

            // Reset text color
            // Console.ForegroundColor = ConsoleColor.White; use reset color
            Console.ResetColor();
        }

        static void GreetUser()
        {
            //Ask user's name
            Console.Write("What is your name? ");

            //Get user input
            string inputName = Console.ReadLine();

            //Write out hello use
            Console.ForegroundColor = ConsoleColor.DarkGray;
            Console.WriteLine("Hello {0} let's play a game... \n", inputName);
        }

        static void PrintColorMessage(ConsoleColor color, string message)
        {
            Console.ForegroundColor = color;
            Console.WriteLine(message);
            Console.ResetColor();
        }

       

    }
}

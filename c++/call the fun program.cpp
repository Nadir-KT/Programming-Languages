(1) #include <iostream>

using namespace std;
void myFunction() //create a function
{
  cout << "executed"<<" ";
}

int main() //initialize
{
  myFunction(); // call the function
  myFunction();
  return 0;
}

(2) #include <iostream>

using namespace std;
void myfunction(string fname) //create a function (parameter with argument)
{
    cout<<fname<<endl; //print 
}
int main()
{
    myfunction("embedded"); //call the function
    myfunction("design");
    myfunction("engineer");
}

(3) #include <iostream>

using namespace std;
void myfunction(string city = "pune") //create a function (fun without argument default parameter value)
{
    cout<<city<<'\n';
}
int main()
{
    myfunction("aurngabad");
    myfunction();
    myfunction("washim");
    myfunction("chikhali");
}

(4) #include <iostream>

using namespace std;
void myfunction(string fname, int age) //create a function(multiple parameter)
{
    cout<<fname<<age<<" year old. \n"; //print name & age
}
int main() //initialization
{
    myfunction("pooja. ", 3); //call the function
    myfunction("ankita. ", 14);
    myfunction("shradha. ", 22);
}

(5) #include <iostream>

using namespace std;
int myfunction(int x, int y) //create a function(with return value)
{
    return x+y; //sum of x & y
}
int main() //initialization

{
cout<<myfunction(3, 5); //call a function
return 0;
}

(6) #include <iostream>
using namespace std;
void myfunction(int myNumber[5]) //create a function(Pass Arrays as function parameters)
{
    for (int i=0; i<5; i++)
    {
        cout<<myNumber[i]<<endl;
    }
}
int main()
{
    int myNumber[5]={10, 20, 30, 40, 50};
    myfunction(myNumber); //call the function
    return 0;
}
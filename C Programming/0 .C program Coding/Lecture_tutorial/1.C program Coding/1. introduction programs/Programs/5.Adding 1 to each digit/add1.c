    #include<stdio.h>

    #include<conio.h>

    main()

    {

    int num,a,b,c,d,e,f,g,h,new;

    printf("Please enter a five digit number: ");

    scanf("%d", &num);

    a=num/10000; // retrives the first digit(left most digit)

    b=num%10000;

    c=b/1000; //retrieves the second digit

    d=b%1000;

    e=d/100; //retrieves the third digit

    f=d%100;

    g=f/10; //retrieves the fourth digit

    h=f%10; //retrieves the fifth digit(right most digit)

    a=(a+1)*10000;

    c=(c+1)*1000;

    e=(e+1)*100;

    g=(g+1)*10;

    h=(h+1)*1;

    new=a+c+e+g+h;

    printf("The new number is is %d", new);

    getch();

    }

 

 

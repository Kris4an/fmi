#include <iostream>
#include <fstream>
#include <cmath>

bool isPrime(int a){
    if(a%2 != 0) return true;
    for(int i = 3; i <= sqrt(a); i+=2){
        if(a%i == 0) return false;
    }
    return true;
}
void zad1(){
    std::ofstream myFile("zad1.txt");
    
    if(!myFile){
        std::cerr<<"Error!";
        return;
    }

    int n;
    std::cin>>n;

    myFile<<2<<'\n';
    for(int i = 3; n>0; i+=2, --n){
        if(isPrime(i)){
            myFile<<i<<'\n';
        }
    }
    myFile.close();
}
void zad2(){
    std::ifstream inFile;

    inFile.open("zad2.txt");

    if(!inFile){
        std::cerr<<"Error!";
        return;
    }
    int sum = 0;
    while(!inFile.eof()){
        int a;
        inFile >> a;
        sum+=a;
    }
    inFile.close();
    std::cout<<sum;
}
void zad3(){
    std::ifstream inFile;
    std::ofstream outFile("zad3Out.txt");
    inFile.open("zad3In.txt");

    if(!inFile || !outFile){
        std::cerr<<"Error!";
        return;
    }

    while(!inFile.eof()){
        char a;
        a = inFile.get();
       
        if(a < 0) break;

        if(a>='A' && a<='Z') a+=32;
        else if(a>='a' && a<='z') a-=32;
        
        outFile<<a;
    }
    inFile.close();
    outFile.close();
}
void zad4(){
    std::fstream myFile("zad4.txt", std::fstream::out | std::ios::in);
    
    if(!myFile){
        std::cerr<<"Error!";
        return;
    }

    for(int i = 0; i < 10; ++i){
        char c;
        std::cin>>c;
        myFile<<c;
    }
    //system("cls");
    myFile.seekg(0, std::ios::beg);

    while(!myFile.eof()){
        char ch;
        ch = myFile.get();

        switch (ch)
        {
            //fall through intended
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'u':
            case 'U':
            case 'o':
            case 'O':
            case 'i':
            case 'I':
                std::cout<<ch<<'\n';
            break;
        }
    }
    myFile.close();
}
void zad5(){
    std::ifstream inFile;

    inFile.open("zad5.txt");

    if(!inFile){
        std::cerr<<"Error!";
        return;
    }
    int sum = 0;
    for(int i = 0; i < 4; ++i){
        for(int j = 0;  j < 4; ++j){
            int el;
            if(i == j) {
                inFile>>el;
                sum+=el;
            }
            if(i == 4-j){
                inFile>>el;
                sum-=el;
            }
        }
    }
    std::cout<<(abs(sum));
    inFile.close();
}
int binToInt(char* number){
    int n = 0, res = 0;
    for(;number[n] !=0; ++n);
    for(int i = 0; i < n; ++i){
        res+=number[i]*pow(2, n-i);
    }

    return res;
}
void zad6(){
    std::ofstream outFile("zad6.bin", std::fstream::out | std::ios::binary);

    if(!outFile){
        std::cout<<"Error!";
        return;
    }

    int n;
    std::cin>>n;
    int* A = new int[n];

    outFile.write((char*) &n, sizeof(n));

    for(int i = 0; i < n; ++i){
        std::cin>>A[i];
    }

    outFile.write(reinterpret_cast<char*>(A), sizeof(A[0]) * n);

    if(!outFile){
        std::cout<<"Could not write to file!";
        return;
    }

    delete A;
    outFile.close();


    std::ifstream inFile("zad6.bin", std::ifstream::in | std::ios::binary);

    if(!inFile){
        std::cout<<"Could not open file!";
        return;
    }

    int N, sum = 0, min, max;
    inFile.read((char*) &N, sizeof(N));

    int* B = new int[N];

    inFile.read(reinterpret_cast<char*>(B), sizeof(B[0]) * n);

    if(!inFile){
        std::cout<<"Could not read file!";
        return;
    }

    min = B[0];
    max = B[0];
    for(int i = 0; i < N; ++i){
        if(min > B[i]) min = B[i];
        if(max < B[i]) max = B[i];
        sum += B[i];
        std::cout<<B[i]<<" ";
    }
    std::cout<<"\naverage = "<<(sum/N)<<"\nmin = "<<min<<"\nmax = "<<max;

    delete B;
    inFile.close();
}
void zad6s(){
    std::ofstream outFile("zad6s.bin", std::ios::out | std::ios::binary);

    if(!outFile){
        std::cout<<"Error!";
        return;
    }

    int n = 5;
    int A[n] = {10, 20, -30, 40, 52};
    int B[n];

    //outFile<<n<<std::endl;

    // for(int i = 0; i < n; ++i){
    //     std::cin>>A[i];
    // }
    outFile.write(reinterpret_cast<char*>(A), sizeof(A));

    if(!outFile){
        std::cout<<"Could not write to file!";
        return;
    }

    outFile.close();


    std::ifstream inFile("zad6s.bin", std::ios::in | std::ios::binary);

    if(!inFile){
        std::cout<<"Could not open file!";
        return;
    }

    int N = n, sum = 0, min, max;
    //inFile>>N;

    //int* B = new int[N];

    inFile.read(reinterpret_cast<char*>(B), sizeof(B));

    if(!inFile){
        std::cout<<"Could not read file!";
        return;
    }

    min = B[0];
    max = B[0];
    for(int i = 0; i < N; ++i){
        if(min > B[i]) min = B[i];
        if(max < B[i]) max = B[i];
        sum += B[i];
        std::cout<<B[i]<<" ";
    }
    std::cout<<"\naverage = "<<(sum/N)<<"\nmin = "<<min<<"\nmax = "<<max;

    inFile.close();
}

int main(){
    zad6();
    return 0;
}
#include <iostream>

using namespace std;
class plansza{
 public:
    char kwadratPlanszy[10] = "123456789";

 public:
    void rysuj(){
        std::cout << kwadratPlanszy[0] << "|" << kwadratPlanszy[1] << "|" << kwadratPlanszy[2] << std::endl;
		std::cout << "-+-+-"<< std::endl;
		std::cout << kwadratPlanszy[3] << "|" << kwadratPlanszy[4] << "|" << kwadratPlanszy[5] << std::endl;
		std::cout << "-+-+-"<< std::endl;
		std::cout << kwadratPlanszy[6] << "|" << kwadratPlanszy[7] << "|" << kwadratPlanszy[8] << std::endl;
    }

    bool wygrana(plansza x){
       
        if (x.kwadratPlanszy[0] == x.kwadratPlanszy[1] == x.kwadratPlanszy[2]){ //== kwadratPlanszy[2]){
            return true;
        }
        else if (x.kwadratPlanszy[0] == x.kwadratPlanszy[3] == x.kwadratPlanszy[6]){ //== kwadratPlanszy[6]){
            return true;
        }
        else if (x.kwadratPlanszy[0] == x.kwadratPlanszy[4] == x.kwadratPlanszy[8]){ //== kwadratPlanszy[8]){
            return true;
        }
        else if (x.kwadratPlanszy[2] == x.kwadratPlanszy[5] == x.kwadratPlanszy[8]){
           return true; 
        }//&& kwadratPlanszy[5] == kwadratPlanszy[8])
        else if (x.kwadratPlanszy[2] == x.kwadratPlanszy[4] == x.kwadratPlanszy[6]){
            return true;   
        }
        else if (x.kwadratPlanszy[6] == x.kwadratPlanszy[7] == x.kwadratPlanszy[8]){
            return true;
        }
        
        return false;
    }
};

class X {

    char c = 'X';

    public:
        void zamienX(plansza x, int a){

            x.kwadratPlanszy[a-1] = c;         

        }
};

class O {

    char o = 'O';

    public:
        void zamienO(plansza x, int a){
            
            x.kwadratPlanszy[a-1] = o;
        }
};

bool check(plansza x, int a){
    
    if(x.kwadratPlanszy[a-1] == 'X' || x.kwadratPlanszy[a-1] == 'O'){
        return true;
    }
    
    return false;
}

bool check_error(plansza x){
    for (int i = 0; i < 9; i++){
        if (x.kwadratPlanszy[i] == 'X' || x.kwadratPlanszy[i] == 'O'){
            continue;
        }
        else{
        return false;
        }
        
    }
    return true;   
    
}



int main(){

    plansza plansza1;
    O O1;
    X X1;

    cout << "Witajcie w grze w kółko i krzyżyk! Podajcie swoje imiona" << endl;

    string gracz1;
    string gracz2;

    cout << "Gracz1: "; cin >> gracz1;
    cout << "Gracz2: "; cin >> gracz2;

    int iPlayerTurn = 0;
    bool koniecGry = false;    


    do {
        plansza1.rysuj();

        if(iPlayerTurn %2 == 0){
            
            int x;
            cout << "Gracz " << gracz1 <<" twój ruch, wybierz pole na które chcesz postawić krzyżyk" << endl;
            cin >> x;
            bool check1 = check(plansza1, x);

            if (check1 == true){
                cout << "To pole jest już zajęte! Tracisz kolejkę" << endl;
            }
            else{
                X1.zamienX(plansza1, x);
            }

        }
        else{
            int x;
            cout << "Gracz " << gracz2 <<" twój ruch, wybierz pole na które chcesz postawić krzyżyk" << endl;
            cin >> x;
            bool check1 = check(plansza1, x);

            if (check1 == true){
                cout << "To pole jest już zajęte! Tracisz kolejkę" << endl;
            }
            else{
                O1.zamienO(plansza1, x);
            }

            }
                bool wygrana = plansza1.wygrana(plansza1);

                if(wygrana == true){
                    koniecGry == true;
                }

                bool error = check_error(plansza1);

                if(error == true){
                    cout << "Wszystkie pola zapełnione!" << endl;
                    koniecGry == true;
                } 
        
        iPlayerTurn ++;

        cout << endl;
    } while (koniecGry == false);

    cout << "KONIEC GRY!!" << endl;
 

    
    


    return 0;
}

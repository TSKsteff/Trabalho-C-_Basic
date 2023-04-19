#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <time.h>
using namespace std;

int main()
{

   setlocale(LC_ALL, "portuguese");
    int c,e=0;
do{
///   _______Apresentaçao do Jogo________/

    cout << " ____________";
    cout << " \n\n";
    cout << " BEM VINDO!! | Campo Minado| "<< endl;
    cout << " 1.Iniciar"<<endl;
    cout << " 2.escolher dificuldade"<<endl;
    cout << " 3.sobre o Jogo"<<endl;
    cout << " ____________" << endl;

    cin>>c;
    system("pause");
    system("cls");

    if(c==2){
        cout<< "1.facil matriz 4x4"<<endl;
        cout<< "2.facil matriz 6x6"<<endl;
        cout<< "3.facil matriz 8x8"<<endl;
        cout<< "4.Aleatorio"<<endl;
        cin>>e;
        system("pause");
        system("cls");
    }else if(c==3){
        cout << "\n\t\tSOBRE " << endl
                             << "\n\t Desenvolvido por Mateus Gomes. " <<endl
                             << "\t Ciencias da Computacao. " << endl
                             << "\t UNIVALI - Universidade do Vale do Itajai. " << endl
                             << "\t Algoritimos e programacao. " << endl
                             << "\t Professor e Cordenador:" << endl
                             << "\t EDUARDO ALVEZ DA SILVA" << endl << endl

                             << "\t CRIADO EM NOVEMBRO DE 2022" << endl << endl;
                        system("pause");
                        system("cls");

    }
    if(e==0 || c!=1 || c!=2){
        break;
    }
}while(e==0 || c!=1 || c!=2);


    int mtr_fcl[4][4]={1,1,1,2, /// MATRIZ PRINCIPAL
                       1,1,1,1,
                       2,1,1,1,
                       1,1,2,1};
    int mtr_mdio[6][6]={1,1,1,1,1,2,
                        1,1,1,1,1,1,
                        2,1,1,1,2,2,
                        1,1,1,1,1,1,
                        1,1,1,1,2,1,
                        1,2,1,1,1,1};

    int mtr_dcl[8][8]={1,2,1,1,1,2,1,1,
                       1,1,1,2,1,1,1,1,
                       2,1,1,1,2,2,1,1,
                       1,1,2,1,1,1,1,1,
                       1,1,1,1,2,1,1,1,
                       1,2,1,1,1,1,2,1};


    int linha1, coluna1, linha2,coluna2;
    int escolha1, escolha2;
    int total=1, fim=0;
    int num=0, k=3;
    int tnva=24, jogadas=0, pontos=0;
    int err=0;

    ///_______ Rand para escolher aleatoriamente qual matriz montar o jogo______/

 srand(time(NULL));

 switch(e){
case 1 :num=e;break;
case 2 :num=e;break;
case 3 :num=e;break;
case 4 :num=1+rand()%3;break;
}

 switch(num){
case 1:for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            mtr1[i][j]=mtr_fcl[i][j];}
    }cout<<"fcl";
    break;
case 2: for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            mtr1[i][j]=mtr_mdio[i][j];}
    }cout<<"fcl";
    break;
case 3:for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            mtr1[i][j]=mtr_dcl[i][j];}
    }cout<<"fcl";
    break;
}

///_____ INICIO DO JOGO______


cout << " |X| |X| |X| |X| \n |X| |X| |X| |X| \n |X| |X| |X| |X| \n |X| |X| |X| |X|" << endl;

while(total<=24){

  cout << "ESCOLHE UMA LINHA & CORDENADA DE |0 a 3|  : " << endl;
     cin >> linha1>>coluna1;

            while(linha1 > 3 || linha1 < 0 || coluna1 > 3 || coluna1 < 0 || mtr2[linha1][coluna1]!=0){
                cout << "ESCOLHE UMA LINHA & CORDENADA VALIDA DE|0 a 3| : " << endl;
                    cin >> linha1>>coluna1;
            }

   for (int i=0; i<4; i++){
     for (int j=0; j<4; j++){
        if (i==linha1 && j==coluna1){
            cout <<"|"<<mtr1[i][j]<<"|";
                    linha1=i;
                    coluna1=j;
                    escolha1=mtr1[i][j];
        }else{ cout << "|x|";
        }
    }
    cout << endl;
  }

cout << escolha1;

 cout << "\n ESCOLHE OUTRA LINHA & CORDENADA |0 a 3|  : " << endl;
    cin>>linha2>>coluna2;

            while(linha2 > 3 || linha2 < 0 || coluna2 > 3 || coluna2 < 0 || mtr2[linha2][coluna2]!=0){
                cout << "ESCOLHE OUTRA LINHA & CORDENADA VALIDA DE|0 a 3| : " << endl;
                   cin >> linha2>>coluna2;
            }

            while(linha1 == linha2 && coluna1 == coluna2){
                cout << "CORDENADA JA FOI ESCOLINHO ANTERIORMENTE, ESCOLHE OUTRA LINHA & CORDENADA VALIDA DE|0 a 3| :  " << endl;
                   cin >> linha2>>coluna2;
             }

   for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i==linha2 && j==coluna2){
                cout << "|"<<mtr1[i][j]<<"|";
                escolha2=mtr1[i][j];
            }
            else if(linha1==i && coluna1==j){
                cout << "|"<<mtr1[linha1][coluna1]<<"|";
            }else{cout<<"|x|";
        }
        }cout<<endl;
   }

        tnva = tnva - 1;
        jogadas+=1;
   if (escolha1 == escolha2){
       pontos+=1;
        cout << total <<"º TENTIVA"<< endl;
    cout << "JOGADA OK!!\n FALTAM " << tnva << " TENTAVAS "<<endl;

        system("pause");
        system("cls");

      for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if (mtr1[i][j]==escolha1){
                cout << "|"<<mtr1[i][j]<<"|";
                mtr2[i][j]=mtr1[i][j];

            }else if(mtr1[i][j] == escolha2){

                cout << "|"<<mtr1[i][j];
                mtr2[i][j]=mtr1[i][j];

            }else{cout<<"|x|";
        }
        }cout<<endl;
     }
    system("cls");

   }else if (escolha1 != escolha2){
       err+=1;
       cout << total <<"º TENTIVA"<< endl;
       cout << " JOGADA NOK\n TENTE DE NOVO"<<endl;
       cout << "FALTAM " <<tnva << " JOGADAS"<< endl;
        system("pause");
        system("cls");
   }

           for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){

                    if(mtr2[i][j]==0){
                        cout<<"|X|";
                    }else {
                        cout<<"|"<<mtr2[i][j]<<"|";
                    }
                }
                cout<<endl;
            }

   total++;
 }
 if(pontos==8){
        cout << "PARABENS VOCE VENCEUU!!!"<<endl;
        cout << "JOGO CONCLUIDO"<< endl;
        cout << "TENTATIVAS = " <<jogadas<<endl;
        cout << "ACERTOS = " << pontos << endl;
        cout << "ERROS = " << err <<endl;
 }else if (pontos<8 || pontos ==0){
        cout << "NÃO FOI DESSA VEZ| GAME OVER" <<endl;
        cout << "JOGO CONCLUIDO"<< endl;
        cout << "TENTATIVAS = " <<jogadas<<endl;
        cout << "ACERTOS = " << pontos << endl;
        cout << "ERROS = " << err <<endl;

 }
  string nv;
 cout << " QUER JOGAR NOVAMENTE, DIGITE 'S' | 'N' "<<endl;
 cin >> nv;
 if (nv=="s"){
      system("cls");
    return main();

 }else if (nv=="n"){
     return 0;
 }
    return 0;
}

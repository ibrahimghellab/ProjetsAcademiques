#include "project_I.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {

  cout << endl << "------------------------------------------------------------------------" << endl;
  int b;
  cout << "Souhaitez vous ouvrir un fichier ppm ou creer une image par vous meme ? Selectionnez 1 ou 2." << endl;
  cin >> b;
  if(b==1){
    string fich = saisirNomFichier();
    Image image(fich);
    Image img = image;
    menu();
    int resp;
    do{
      resp = choixUtilisateur();
      modification(resp, image, img);
      image = img;
      }while(resp != QUITTER);
    img.savePicture();
  }else{
    cout << "Entrer le nombre de lignes et de colonnes du vecteur : ";
    int n, m;
    cin >> n >> m;
    cout << "Entrez les valeurs du vecteur de la couleur rouge" << endl;
    vector<vector<int>> ro = saisirVecteur(n,m);
    cout << "Entrez les valeurs du vecteur de la couleur vert" << endl;
    vector<vector<int>> ve = saisirVecteur(n,m);
    cout << "Entrez les valeurs du vecteur de la couleur bleu" << endl;
    vector<vector<int>> bl = saisirVecteur(n,m);
    Image image(ro, ve, bl);
    Image img = image;
    menu();
    int resp;
    do{
      resp = choixUtilisateur();
      modification(resp, image, img);
      image = img;
      }while(resp != QUITTER);
    img.savePicture();
  }
  return 0;
}


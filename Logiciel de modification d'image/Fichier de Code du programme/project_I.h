#include <iostream>
#include <string>
#include <vector>
#include <cmath>

const int IMAGENOIRBLANC = 1;
const int IMAGEGRIS = 2;
const int IMAGEROUGENOIR = 3;
const int BAISSERLUMINOSITE = 4;
const int AUGMENTERLUMINOSITE = 5;
const int BAISSERCONTRASTE = 6;
const int AUGMENTERCONTRASTE = 7;
const int DEUTERANOPIE = 8;
const int PROTANOPIE = 9;
const int TRITANOPIE = 10;
const int ROGNERG = 11;
const int ROGNERD = 12;
const int ROGNERH = 13;
const int ROGNERB = 14;
const int ROTATIOND = 15;
const int ROTATIONG = 16;
const int RETOURNEMENTH = 17;
const int RETOURNEMENTV = 18;
const int AGRANDISSEMENT = 19;
const int RETRECISSEMENT = 20;
const int ROTATIONCOULEUR = 21;
const int BLANCHIRCOULEUR = 22;
const int FLOU = 23;
const int QUITTER = 24;

using namespace std;

class Image {
private:
  vector<vector<int>> rouge;
  vector<vector<int>> vert;
  vector<vector<int>> bleu;
  int longueur;
  int largeur;

public:

  vector<vector<int>> getRouge()const { return rouge; }
  vector<vector<int>> getVert()const { return vert; }
  vector<vector<int>> getBleu()const { return bleu; }
  int getLongueur() const;
  int getLargeur() const;
  Image(const string &);
  Image(const vector<vector<int>>&, const vector<vector<int>>&,
        const vector<vector<int>>&);
  void couleurPixel(int, int) const;
  void affichevecteur() const;
  Image composanteRouge()const;
  bool detection(int, int, int) const;
  Image niveauxGris() const;
  Image noirEtBlanc(int x) const;
  vector<int> histogrammeGris();
  vector<vector<vector<int>>> histogrammeCouleur();
  Image luminosityUp(float x) const;
  Image luminosityDown(float x) const;
  Image contrasteUp(float x) const;
  Image contrasteDown(float x) const;
  Image visionDeuteranopie() const;
  Image visionProtanopie() const;
  Image visionTritanopie() const;
  void loadPicture(const string &picture, vector<vector<int>> &red,
                   vector<vector<int>> &green, vector<vector<int>> &blue);

  void savePicture() const;
  Image rognerD()const;
  Image rognerG()const;
  Image rognerB()const;
  Image rognerH()const;
  Image rotationD()const;
  Image rotationG()const;
  Image retournementH()const;
  Image retournementV()const;
  Image agrandissement(int n)const;
  Image retrecissement(int n)const;
  //Prototype de la nouvelle fonctionnalités rotationCouleur
  Image rotationCouleur()const;
  //Prototype de la nouvelle fonctionnalités blanchirCouleur
  Image blanchirCouleur(int, int, int)const;
  Image contourSobel(const vector<vector<float>>& fx,vector<vector<float>>& fy)const;
  Image zoomAvant();
};

class Filtre{
  vector<vector<float>> _action;
  int _rayon;
public:
  Filtre(const vector<vector<float>> &, int);
  Image applicationNormalisation(const Image &)const;
  Image applicationSansNormalisation(const Image &)const;
};
vector<vector<int>> saisirVecteur(int, int);
string saisirNomFichier();
void menu();
int choixUtilisateur();
void modification(int, const Image&, Image&);
vector<vector<float>> produitMatrix(float, const vector<vector<int>>&);
float multiplicationFloat(float,float);
string normalisation(const string&);

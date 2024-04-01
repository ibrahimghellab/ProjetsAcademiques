#include "project_I.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

Image::Image(const string &nomImageppm) {
  loadPicture(nomImageppm, rouge, vert, bleu);
  largeur = rouge.size();
  longueur = rouge[0].size();

}

Image::Image(const vector<vector<int>> &r, const vector<vector<int>> &v, const vector<vector<int>> &b) {

  cout << "Appel du constructeur" << endl;
  if (r.size() != v.size() || r.size() != b.size() || v.size() != b.size() || r[0].size() != v[0].size() || r[0].size() != b[0].size() || v[0].size() != b[0].size()) {
    throw invalid_argument("Les dimensions des trois vecteurs ne sont pas identiques");
  }
  largeur = r.size();
  longueur = r[0].size();
  rouge = r;
  vert = v;
  bleu = b;

}

void Image::couleurPixel(int x, int y) const {

  if (x <= 0 || y <= 0) {
    throw invalid_argument("Les coordonnees doivent etre superieur a 0");
  }

  cout << rouge[x - 1][y - 1] << " " << vert[x - 1][y - 1] << " "
       << bleu[x - 1][y - 1] << endl;
}

void Image::affichevecteur() const {
  cout << "rouge : " << endl;
  for (int i = 0; i < rouge.size(); i++) {
    for (int j = 0; j < rouge[i].size(); j++) {
      cout << rouge[i][j] << " ";
    }
    cout << endl;
  }

  cout << "vert : " << endl;
  for (int i = 0; i < vert.size(); i++) {
    for (int j = 0; j < vert[i].size(); j++) {
      cout << vert[i][j] << " ";
    }
    cout << endl;
  }

  cout << "bleu : " << endl;
  for (int i = 0; i < bleu.size(); i++) {
    for (int j = 0; j < bleu[i].size(); j++) {
      cout << bleu[i][j] << " ";
    }
    cout << endl;
  }
}

Image Image::composanteRouge()const {
  vector<vector<int>> vide;
  for (int i = 0; i < largeur; i++) {
    vide.push_back(vector<int>(longueur));
  }
  Image img(rouge, vide, vide);
  return (img);
}

bool Image::detection(int x, int y, int z) const {
  bool trouve = false;
  int i = 0;
  while (!trouve && i < rouge.size()) {
    int j = 0;
    while (!trouve && j < rouge[i].size()) {
      if (rouge[i][j] == x && vert[i][j] == y && bleu[i][j] == z) {
        trouve = true;
      }
      j++;
    }
    i++;
  }
  return (trouve);
}

Image Image::niveauxGris() const {
  vector<vector<int>> vide;
  for (int i = 0; i < largeur; i++) {
    vide.push_back(vector<int>(longueur));
  }

  for (int i = 0; i < largeur; i++) {
    for (int j = 0; j < longueur; j++) {
      int moy = (rouge[i][j] + vert[i][j] + bleu[i][j]) / 3;
      vide[i][j] = moy;
    }
  }
  Image img(vide, vide, vide);
  return (img);
}

Image Image::noirEtBlanc(int x) const {
  vector<vector<int>> noir_blanc;
  for (int i = 0; i < largeur; i++) {
    noir_blanc.push_back(vector<int>(longueur));
  }

  Image g = niveauxGris();
  for (int i = 0; i < largeur; i++) {
    for (int j = 0; j < longueur; j++) {
      if (g.rouge[i][j] < x) {
        noir_blanc[i][j] = 0;
      } else {
        noir_blanc[i][j] = 255;
      }
    }
  }
  Image img(noir_blanc, noir_blanc, noir_blanc);
  return (img);
}

vector<int> Image::histogrammeGris() {
  vector<int> hist(256, 0);
  Image g = niveauxGris();
  for (int i = 0; i < largeur; i++) {
    for (int j = 0; j < longueur; j++) {
      hist[g.rouge[i][j]]++;
    }
  }
  return (hist);
}

vector<vector<vector<int>>> Image::histogrammeCouleur() {
  vector<vector<vector<int>>> hist(
      256, vector<vector<int>>(256, vector<int>(256, 0)));
  for (int i = 0; i < largeur; i++) {
    for (int j = 0; j < longueur; j++) {
      hist[rouge[i][j]][vert[i][j]][bleu[i][j]]++;
    }
  }
  return (hist);
}

Image Image::luminosityUp(float x) const {
  vector<vector<int>> vide1;
  vector<vector<int>> vide2;
  vector<vector<int>> vide3;

  if (x < 1) {
    throw invalid_argument("x doit etre superieur ou egal a 1");
  }

  if (x == 1) {
    return (Image(rouge, vert, bleu));
  } else {

    for (int i = 0; i < largeur; i++) {
      vide1.push_back(vector<int>(longueur));
      vide2.push_back(vector<int>(longueur));
      vide3.push_back(vector<int>(longueur));
    }

    for (int i = 0; i < largeur; i++) {
      for (int j = 0; j < longueur; j++) {
        if (rouge[i][j] * x <= 255) {
          vide1[i][j] = rouge[i][j] * x;
        } else {
          vide1[i][j] = 255;
        }
        if (vert[i][j] * x <= 255) {
          vide2[i][j] = vert[i][j] * x;
        } else {
          vide2[i][j] = 255;
        }
        if (bleu[i][j] * x <= 255) {
          vide3[i][j] = bleu[i][j] * x;
        } else {
          vide3[i][j] = 255;
        }
      }
    }

    Image img(vide1, vide2, vide3);
    return (img);
  }
}

Image Image::luminosityDown(float x) const {
  vector<vector<int>> vide1;
  vector<vector<int>> vide2;
  vector<vector<int>> vide3;

  if (x > 1 || x < 0) {
    throw invalid_argument("x doit etre compris entre 0 et 1");
  }

  if (x == 1) {
    return (Image(rouge, vert, bleu));
  } else {

    for (int i = 0; i < largeur; i++) {
      vide1.push_back(vector<int>(longueur));
      vide2.push_back(vector<int>(longueur));
      vide3.push_back(vector<int>(longueur));
    }

    for (int i = 0; i < largeur; i++) {
      for (int j = 0; j < longueur; j++) {
        vide1[i][j] = rouge[i][j] * x;
        vide2[i][j] = vert[i][j] * x;
        vide3[i][j] = bleu[i][j] * x;
      }
    }

    Image img(vide1, vide2, vide3);
    return (img);
  }
}

Image Image::contrasteUp(float x) const {
  vector<vector<int>> vide1;
  vector<vector<int>> vide2;
  vector<vector<int>> vide3;

  if (x < 1) {
    throw invalid_argument("x doit etre superieur ou egal a 1");
  }

  if (x == 1) {
    return (Image(rouge, vert, bleu));
  } else {
    for (int i = 0; i < largeur; i++) {
      vide1.push_back(vector<int>(longueur));
      vide2.push_back(vector<int>(longueur));
      vide3.push_back(vector<int>(longueur));
    }

    for (int i = 0; i < largeur; i++) {
      for (int j = 0; j < longueur; j++) {
        vide1[i][j] = 128 + (x * (rouge[i][j] - 128));
        if (vide1[i][j] <= 0) {
          vide1[i][j] = 0;
        } else {
          vide1[i][j] = 255;
        }
        vide2[i][j] = 128 + (x * (vert[i][j] - 128));
        if (vide2[i][j] <= 0) {
          vide2[i][j] = 0;
        } else {
          vide2[i][j] = 255;
        }
        vide3[i][j] = 128 + (x * (bleu[i][j] - 128));
        if (vide3[i][j] <= 0) {
          vide3[i][j] = 0;
        } else {
          vide3[i][j] = 255;
        }
      }
    }
    Image img(vide1, vide2, vide3);
    return (img);
  }
}

Image Image::contrasteDown(float x) const {
  vector<vector<int>> vide1;
  vector<vector<int>> vide2;
  vector<vector<int>> vide3;

  if (x < 0 || x > 1) {
    throw invalid_argument("x doit etre compris entre 0 et 1");
  }

  if (x == 1) {
    return (Image(rouge, vert, bleu));
  } else {
    for (int i = 0; i < largeur; i++) {
      vide1.push_back(vector<int>(longueur));
      vide2.push_back(vector<int>(longueur));
      vide3.push_back(vector<int>(longueur));
    }

    for (int i = 0; i < largeur; i++) {
      for (int j = 0; j < longueur; j++) {
        vide1[i][j] = 128 + (x * (rouge[i][j] - 128));
        vide2[i][j] = 128 + (x * (vert[i][j] - 128));
        vide3[i][j] = 128 + (x * (bleu[i][j] - 128));
      }
    }
    Image img(vide1, vide2, vide3);
    return (img);
  }
}

Image Image::visionDeuteranopie() const {
  vector<vector<int>> vide;

  for (int i = 0; i < largeur; i++) {
    vide.push_back(vector<int>(longueur));
  }

  Image img(rouge, vide, bleu);
  return (img);
}

Image Image::visionProtanopie() const {
  vector<vector<int>> vide;

  for (int i = 0; i < largeur; i++) {
    vide.push_back(vector<int>(longueur));
  }

  Image img(vide, vert, bleu);
  return (img);
}

Image Image::visionTritanopie() const {
  vector<vector<int>> vide;

  for (int i = 0; i < largeur; i++) {
    vide.push_back(vector<int>(longueur));
  }

  Image img(rouge, vert, vide);
  return (img);
}

string saisirNomFichier() {
  string nom;
  cout << "Saisir le nom du fichier : ";
  cin >> nom;
  return (nom);
}

void menu() {
  cout << "Menu des fonctionnalités : " << endl;
  cout << "1. Passer l'image en noir et blanc" << endl;
  cout << "2. Passer l'image en gris" << endl;
  cout << "3. Passer l'image en rouge et noir" << endl;
  cout << "4. Baisser la luminosité" << endl;
  cout << "5. Augmenter la luminosité" << endl;
  cout << "6. Baisser le contraste" << endl;
  cout << "7. Augmenter le contraste" << endl;
  cout << "8. Passer l'image en deuteranopie" << endl;
  cout << "9. Passer l'image en protanopie" << endl;
  cout << "10. Passer l'image en tritanopie" << endl;
  cout << "11. Rogner l'image a gauche" << endl;
  cout << "12. Rogner l'image a droite" << endl;
  cout << "13. Rogner l'image en haut" << endl;
  cout << "14. Rogner l'image en bas" << endl;
  cout << "15. Rotation de l'image vers la droite" << endl;
  cout << "16. Rotation de l'image vers la gauche" << endl;
  cout << "17. Retournement horizontal (symetrie d'axe verticale)" << endl;
  cout << "18. Retournement vertical (symetrie d'axe horizontale)" << endl;
  cout << "19. Agrandissement de l'image selon un facteur x" << endl;
  cout << "20. Retrecissement de l'image selon un facteur x" << endl;
  cout << "21. Rotation des couleurs de l'image" << endl;
  cout << "22. Blanchir une couleur" << endl;
  cout << "23. Flou de l'image" << endl;
  cout << "24. Quitter" << endl;
}

int choixUtilisateur() {
  int choix;

  cout << "Saisir votre modifications : ";
  cin >> choix;
  while (choix > 24 || choix < 1) {
    cout << "Veuillier saisir une modififcation valide : " << endl;
    cin >> choix;
  }
  return (choix);
}

void Image::loadPicture(const string &picture, vector<vector<int>> &red,
                        vector<vector<int>> &green, vector<vector<int>> &blue) {
  // Declaration des variables
  string line; // pour recuperer les lignes du fichier image au format .ppm, qui
               // est code en ASCII.
  string format; // pour recuperer le format de l'image : celui-ci doit être de
                 // la forme P3
  string name;   // au cas où l'utilisateur se trompe dans le nom de l'image a
                 // charger, on redemande le nom.
  int taille;
  vector<int> mypixels; // pour recuperer les donnees du fichier de maniere
                        // lineaire. On repartira ensuite ces donnees dans les
                        // tableaux correspondants
  ifstream entree; // Declaration d'un "flux" qui permettra ensuite de lire les
                   // donnees de l'image.
  int hauteur;     // pour bien verifier que l'image est carree, et de taille
                   // respectant les conditions fixees par l'enonce
  // Initialisation des variables
  name = picture;
  // Permet d'ouvrir le fichier portant le nom picture
  // ouverture du fichier portant le nom picture
  entree.open(name);
  // On verifie que le fichier a bien ete ouvert. Si cela n'est pas le cas, on
  // redemande un nom de fichier valide
  while (!entree) {
    // cin.rdbuf(oldbuf);
    cerr << "Erreur! Impossible de lire de fichier " << name << " ! " << endl;
    cerr << "Redonnez le nom du fichier a ouvrir SVP. Attention ce fichier "
            "doit avoir un nom du type nom.ppm."
         << endl;
    cin >> name;
    entree.open(name); // relance
  }
  // Lecture du nombre definissant le format (ici P3)
  entree >> format;
  // on finit de lire la ligne (caractere d'espacement)
  getline(entree, line);
  // Lecture du commentaire
  getline(entree, line);
  // lecture des dimensions
  entree >> taille >> hauteur;
  getline(entree, line); // on finit de lire la ligne (caractere d'espacement)
  // On verifie que l'image a une taille qui verifie bien les conditions
  // requises par l'enonce. Si cela n'est pas le cas, on redemande un fichier
  // valide, et ce, tant que necessaire.
  while (format != "P3") {
    if (format != "P3") {
      cerr << "Erreur! L'image que vous nous avez donnee a un format ne "
              "verifiant pas les conditions requises."
           << endl;
      cerr << "L'image que vous nous avez donnee doit etre codee en ASCII et "
              "non en brut."
           << endl;
    }
    entree.close();
    // On va redemander un nom de fichier valide.
    do {
      cerr << "Veuillez redonner un nom de fichier qui respecte les conditions "
              "de format et de taille. Attention, ce nom doit etre de la forme "
              "nom.ppm."
           << endl;
      cin >> name;
      entree.open(name); // relance
    } while (!entree);
    // Lecture du nombre definissant le format (ici P3)
    entree >> format;
    getline(entree, line); // on finit de lire la ligne (caractere d'espacement)
    // Lecture du commentaire
    getline(entree, line);
    // lecture des dimensions
    entree >> taille >> hauteur; // relance
    getline(entree, line); // on finit de lire la ligne (caractere d'espacement)
  }
  // Lecture de la valeur max
  getline(entree, line);
  // Lecture des donnees et ecriture dans les tableaux :
  //  Pour plus de simplicite, on stocke d'abord toutes les donnees dans
  //  mypixels dans l'ordre de lecture puis ensuite on les repartira dans les
  //  differents tableaux.
  // Les donnees stockees dans mypixels sont de la forme RGB RGB RGB ....
  //  Il faudra donc repartir les valeurs R correspondant a la composante rouge
  //  de l'image dans le tableau red, de même pour G et B.
  int pix;
  mypixels.resize(3 * taille *
                  hauteur); // taille fixe : on alloue une fois pour toutes
  for (int i = 0; i < 3 * taille * hauteur; i++) {
    entree >> pix;
    mypixels[i] = pix;
  }
  // Remplissage des 3 tableaux : on repartit maintenant les valeurs dans les
  // bonnes composantes Comme dans mypixels, les donnees sont stockees de la
  // maniere suivante : RGB RGB RGB, il faut mettre les valeurs correspondant a
  // la composante rouge dans red, ... Ainsi, les valeurs de la composante rouge
  // correspondent aux valeurs stockes aux indices congrus a 0 mod 3 dans
  // mypixels, que les valeurs de la composante verte correspond aux valeurs
  // stockes aux indices sont congrus a 1 mod 3, ...
  // les valeurs d'une ligne
  int val;
  red.resize(hauteur);
  green.resize(hauteur);
  blue.resize(hauteur);
  for (int i = 0; i < hauteur; i++) {
    vector<int> ligneR(taille);
    vector<int> ligneB(taille); // les lignes ont toutes la même taille
    vector<int> ligneG(taille);
    for (int j = 0; j < taille; j++) {
      val = mypixels[3 * j + 3 * taille * i];
      ligneR[j] = val;
      val = mypixels[3 * j + 1 + 3 * taille * i];
      ligneG[j] = val;
      val = mypixels[3 * j + 2 + 3 * taille * i];
      ligneB[j] = val;
    }
    red[i] = ligneR;
    green[i] = ligneG;
    blue[i] = ligneB;
  }
  // Informations a l'utilisateur pour dire que tout s'est bien passe
  cout << " L'image " << name << " a bien ete chargee dans les tableaux ."
       << endl;
  entree.close();
}

int Image::getLongueur() const { return (longueur); }

int Image::getLargeur() const { return (largeur); }

void Image::savePicture() const {
  // Declaration des variables
  ofstream sortie;

  string nom = saisirNomFichier();
  nom=normalisation(nom);
  sortie.open(nom);
  // Ecriture du format de l'image
  while (!sortie) {
    // cin.rdbuf(oldbuf);
    cerr << "Erreur! Impossible de sauvegarder l'image " << nom << " ! "
         << endl;
    cerr << "Redonnez le nom du fichier a sauvegarder SVP. Attention ce "
            "fichier doit avoir un nom du type nom.ppm."
         << endl;
    cin >> nom;
    sortie.open(nom); // relance
  }

  // Ecriture du commentai
  sortie << "P3" << endl;
  sortie << longueur << " " << largeur << endl;
  sortie << "255" << endl;
  for (int i = 0; i < largeur; i++) {
    for (int j = 0; j < longueur; j++) {
      sortie << rouge[i][j] << " " << vert[i][j] << " " << bleu[i][j] << endl;
    }
  }
  sortie.close();
}

Image Image::rognerG() const {
  vector<vector<int>> vide1;
  vector<vector<int>> vide2;
  vector<vector<int>> vide3;

  for (int i = 0; i < largeur; i++) {
    vide1.push_back(vector<int>(longueur-1));
    vide2.push_back(vector<int>(longueur-1));
    vide3.push_back(vector<int>(longueur-1));
  }

  for (int i = 0; i < largeur; i++) {
    for (int j = 1; j < longueur; j++) {
      vide1[i][j] = rouge[i][j];
      vide2[i][j] = vert[i][j];
      vide3[i][j] = bleu[i][j];
    }
  }

  Image img(vide1, vide2, vide3);
  return (img);
}

Image Image::rognerD() const {
  vector<vector<int>> vide1;
  vector<vector<int>> vide2;
  vector<vector<int>> vide3;
  for (int i = 0; i < largeur; i++) {
    vide1.push_back(vector<int>(longueur-1));
    vide2.push_back(vector<int>(longueur-1));
    vide3.push_back(vector<int>(longueur-1));
  }
  for (int i = 0; i < largeur; i++) {
    for (int j = 0; j < longueur - 1; j++) {
      vide1[i][j] = rouge[i][j];
      vide2[i][j] = vert[i][j];
      vide3[i][j] = bleu[i][j];
    }
  }
  return (Image(vide1, vide2, vide3));
}

Image Image::rognerH() const {
  vector<vector<int>> vide1;
  vector<vector<int>> vide2;
  vector<vector<int>> vide3;
  for (int i = 0; i < largeur-1; i++) {
    vide1.push_back(vector<int>(longueur));
    vide2.push_back(vector<int>(longueur));
    vide3.push_back(vector<int>(longueur));
  }
  for (int i = 1; i < largeur; i++) {
    for (int j = 0; j < longueur; j++) {
      vide1[i][j] = rouge[i][j];
      vide2[i][j] = vert[i][j];
      vide3[i][j] = bleu[i][j];
    }
  }
  return (Image(vide1, vide2, vide3));
}

Image Image::rognerB() const {
  vector<vector<int>> vide1;
  vector<vector<int>> vide2;
  vector<vector<int>> vide3;
  for (int i = 0; i < largeur-1; i++) {
    vide1.push_back(vector<int>(longueur));
    vide2.push_back(vector<int>(longueur));
    vide3.push_back(vector<int>(longueur));
  }
  for (int i = 0; i < largeur - 1; i++) {
    for (int j = 0; j < longueur; j++) {
      vide1[i][j] = rouge[i][j];
      vide2[i][j] = vert[i][j];
      vide3[i][j] = bleu[i][j];
    }
  }
  return (Image(vide1, vide2, vide3));
}

Image Image::rotationD() const {
  vector<vector<int>> vide1(largeur);
  vector<vector<int>> vide2(largeur);
  vector<vector<int>> vide3(largeur);

  for (int i = 0; i < longueur; i++) {
    for (int j = largeur-1; j >=0 ; j--) {
      vide1[i].push_back(rouge[j][i]);
      vide2[i].push_back(vert[j][i]);
      vide3[i].push_back(bleu[j][i]);
    }
  }

  return (Image(vide1, vide2, vide3));
}

Image Image::rotationG() const {
  vector<vector<int>> vide1(largeur);
  vector<vector<int>> vide2(largeur);
  vector<vector<int>> vide3(largeur);
  int k=0;
  for (int i = longueur; i >=0; i--) {
    for (int j = largeur-1; j >=0 ; j--) {
      vide1[k].push_back(rouge[j][i]);
      vide2[k].push_back(vert[j][i]);
      vide3[k].push_back(bleu[j][i]);
    }
    k++;
  }

  return (Image(vide1, vide2, vide3));
}

Image Image::retournementH()const{
  vector<vector<int>> vide1(largeur);
  vector<vector<int>> vide2(largeur);
  vector<vector<int>> vide3(largeur);

  for (int i = 0; i < longueur; i++) {
    for (int j = largeur-1; j >=0 ; j--) {
      vide1[i].push_back(rouge[i][j]);
      vide2[i].push_back(vert[i][j]);
      vide3[i].push_back(bleu[i][j]);
    }
  }
  return (Image(vide1, vide2, vide3));
}

Image Image::retournementV()const{
  vector<vector<int>> vide1(largeur);
  vector<vector<int>> vide2(largeur);
  vector<vector<int>> vide3(largeur);

  int k=0;
  for (int i = longueur-1; i >= 0; i--) {
    for (int j = 0; j < largeur ; j++) {
      vide1[k].push_back(rouge[i][j]);
      vide2[k].push_back(vert[i][j]);
      vide3[k].push_back(bleu[i][j]);
    }
    k++;
  }
  return (Image(vide1, vide2, vide3));
}

Image Image::agrandissement(int n)const{
  vector<vector<int>> vide1(largeur*n);
  vector<vector<int>> vide2(largeur*n);
  vector<vector<int>> vide3(largeur*n);

  for (int i = 0; i < largeur; i++) {
    for (int k=0; k<n; k++) {
      for (int j = 0; j < longueur; j++) {
        for (int l=0; l<n; l++) {
          vide1[i*n+k].push_back(rouge[i][j]);
          vide2[i*n+k].push_back(vert[i][j]);
          vide3[i*n+k].push_back(bleu[i][j]);
        }
      }
    }
  }

  return (Image(vide1, vide2, vide3));
}

Image Image::retrecissement(int n) const {
  vector<vector<int>> vide1(largeur / n, vector<int>(longueur / n));
  vector<vector<int>> vide2(largeur / n, vector<int>(longueur / n));
  vector<vector<int>> vide3(largeur / n, vector<int>(longueur / n));
  for (int i = 0; i < largeur / n; i++) {
    for (int j = 0; j < longueur / n; j++) {
      int sumR = 0;
      int sumG = 0;
      int sumB = 0;
      for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
          sumR += rouge[i*n + x][j*n + y];
          sumG += vert[i*n + x][j*n + y];
          sumB += bleu[i*n + x][j*n + y];
        }
      }
      vide1[i][j] = sumR / (n*n);
      vide2[i][j] = sumG / (n*n);
      vide3[i][j] = sumB / (n*n);
    }
  }
  return Image(vide1, vide2, vide3);
}

void modification(int choix,const Image & image, Image& image1){
  int x;

  switch (choix) {
    case IMAGENOIRBLANC:
      cout << "Choisissez un facteur de passage au blanc ou noir : ";
      cin >> x;
      image1 = image.noirEtBlanc(x);
      break;
    case IMAGEGRIS : image1 = image.niveauxGris(); break;
    case IMAGEROUGENOIR: image1 = image.composanteRouge(); break;
    case BAISSERLUMINOSITE:
      cout << " Diminuer la luminosite de l'image de : ";
      cin >> x;
      image1 = image.luminosityDown(x); break;
    case AUGMENTERLUMINOSITE:
      cout << " Augmenter la luminosite de l'image de : ";
      cin >> x;
      image1 = image.luminosityUp(x); break;
    case BAISSERCONTRASTE:
      cout << "Baisser le contraste de l'image de : ";
      cin >> x;
      image1 = image.contrasteDown(x); break;
    case AUGMENTERCONTRASTE:
      cout << "Augmenter le contraste de l'image de : ";
      cin >> x;
      image1 = image.contrasteUp(x); break;
    case DEUTERANOPIE: image1 = image.visionDeuteranopie(); break;
    case PROTANOPIE: image1 = image.visionProtanopie(); break;
    case TRITANOPIE: image1 = image.visionTritanopie(); break;
    case ROGNERG : image1 = image.rognerG(); break;
    case ROGNERD : image1 = image.rognerD(); break;
    case ROGNERH : image1 = image.rognerH(); break;
    case ROGNERB : image1 = image.rognerB(); break;
    case ROTATIOND : image1 = image.rotationD(); break;
    case ROTATIONG : image1 = image.rotationG(); break;
    case RETOURNEMENTH : image1 = image.retournementH(); break;
    case RETOURNEMENTV : image1 = image.retournementV(); break;
    case AGRANDISSEMENT :
      cout << "Choisissez un facteur d'agrandissement : ";
      cin >> x;
      image1 = image.agrandissement(x); break;
    case RETRECISSEMENT :
      cout << "Choisissez un facteur de retrecissement : ";
      cin >> x;
      image1 = image.retrecissement(x); break;
    case ROTATIONCOULEUR:
        image1 = image.rotationCouleur(); break;
    case BLANCHIRCOULEUR:
        int i, j, k;
        cout << " entrer la couleur a blanchir" << endl;
        cin >> i >> j >> k;
        image1 = image.blanchirCouleur(i,j,k); break;
    case FLOU :
      cout << "Choisissez un type de flou ( 1=flouG3, 2=flougaussien, 3=contoursobel) : ";
      cin >> x;
      switch(x){
        case 1 :{
          vector<vector<float>> filtre1 = {{1.0 / 16.0, 1.0 / 8.0, 1.0 / 16.0}, {1.0 / 8.0, 1.0 / 4.0, 1.0 / 8.0}, {1.0 / 16.0, 1.0 / 8.0, 1.0 / 16.0}};
          Filtre flouG3(filtre1,1);
          image1 = flouG3.applicationNormalisation(image); break;
        }
        case 2 :{
          vector<vector<int>> filtre2 = {{1, 4, 6, 4, 1}, {4, 16, 24, 16, 4}, {6, 24, 36, 24, 6}, {4, 16, 24, 16, 4}, {1, 4, 6, 4}};
          Filtre flouG5(produitMatrix(1.0/256.0, filtre2), 2);
          image1 = flouG5.applicationNormalisation(image); break;
        }
        case 3 :
          vector<vector<float>> filtreX = {{-1.0, 0.0, 1.0}, {-2.0, 0.0, 2.0}, {-1.0, 0.0, 1.0}};
          vector<vector<float>> filtreY = {{-1.0, -2.0, -1.0}, {0.0, 0.0, 0.0}, {1.0, 2.0, 1.0}};
          image1 = image.contourSobel(filtreX, filtreY); break;
    }
    case QUITTER : cout << "Fin du programme et sauvegarde de l'image" << endl; break;
    default: cout << "ERREUR" ;
  }
}

Filtre::Filtre(const vector<vector<float>>& a, int r){
  _action = a;
  _rayon = r;
}

float multiplicationFloat(float x, float y) {
  return (x * y);
}

Image Filtre::applicationNormalisation(const Image &image) const {
  int largeur = image.getLargeur();
  int longueur = image.getLongueur();

  vector<vector<int>> vide1(largeur, vector<int>(longueur, 0));
  vector<vector<int>> vide2(largeur, vector<int>(longueur, 0));
  vector<vector<int>> vide3(largeur, vector<int>(longueur, 0));

  for (int i = 0; i < largeur; i++) {
    for (int j = 0; j < longueur; j++) {
      for (int k = -_rayon; k <= _rayon; k++) {
        for (int l = -_rayon; l <= _rayon; l++) {
          if (i + k >= 0 && i + k < largeur && j + l >= 0 && j + l < longueur) {
            vide1[i][j] += multiplicationFloat(image.getRouge()[i + k][j + l], _action[k + _rayon][l + _rayon]);
            vide2[i][j] += multiplicationFloat(image.getVert()[i + k][j + l], _action[k + _rayon][l + _rayon]);
            vide3[i][j] += multiplicationFloat(image.getBleu()[i + k][j + l], _action[k + _rayon][l + _rayon]);
            if(vide1[i][j]<0){
              vide1[i][j]=0;
            }else{
              if(vide1[i][j]>255){
                vide1[i][j]=255;
              }
            }
            if(vide2[i][j]<0){
              vide2[i][j]=0;
            }else{
              if(vide2[i][j]>255){
                vide2[i][j]=255;
              }
            }
            if(vide3[i][j]<0){
              vide3[i][j]=0;
            }else{
              if(vide3[i][j]>255){
                vide3[i][j]=255;
              }
            }
          }
        }
      }
    }
  }

  return Image(vide1, vide2, vide3);
}


Image Filtre::applicationSansNormalisation(const Image & image) const {
  int largeur = image.getLargeur();
  int longueur = image.getLongueur();

  vector<vector<int>> vide1(largeur, vector<int>(longueur, 0));
  vector<vector<int>> vide2(largeur, vector<int>(longueur, 0));
  vector<vector<int>> vide3(largeur, vector<int>(longueur, 0));

  for (int i = 0; i < largeur; i++) {
    for (int j = 0; j < longueur; j++) {
      for (int k = -_rayon; k <= _rayon; k++) {
        for (int l = -_rayon; l <= _rayon; l++) {
          if (i + k >= 0 && i + k < largeur && j + l >= 0 && j + l < longueur) {
            vide1[i][j] += multiplicationFloat(image.getRouge()[i + k][j + l], _action[k + _rayon][l + _rayon]);
            vide2[i][j] += multiplicationFloat(image.getVert()[i + k][j + l], _action[k + _rayon][l + _rayon]);
            vide3[i][j] += multiplicationFloat(image.getBleu()[i + k][j + l], _action[k + _rayon][l + _rayon]);
          }
        }
      }
    }
  }
  return Image(vide1, vide2, vide3);
}

vector<vector<float>> produitMatrix(float f, const vector<vector<int>>& v){
  vector<vector<float>> vide(v.size(), vector<float>(v[0].size()));
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      vide[i][j] = f * v[i][j];
    }
  }
  return vide;
}



Image Image::contourSobel(const vector<vector<float>>& fx,vector<vector<float>>& fy)const{
  int largeur = getLargeur();
  int longueur = getLongueur();

  Filtre grX(fx, 1);
  Filtre grY(fy, 1);
  Image Gx = grX.applicationSansNormalisation(*this);
  Image Gy = grY.applicationSansNormalisation(*this);

  vector<vector<int>> vide1(largeur, vector<int>(longueur, 0));
  vector<vector<int>> vide2(largeur, vector<int>(longueur, 0));
  vector<vector<int>> vide3(largeur, vector<int>(longueur, 0));
  for(int i=0;i<largeur;i++){
    for(int j=0;j<longueur;j++){
      vide1[i][j]= sqrt((Gx.getRouge()[i][j]*Gx.getRouge()[i][j])*(Gy.getRouge()[i][j]*Gy.getRouge()[i][j]));
      vide2[i][j]= sqrt((Gx.getVert()[i][j]*Gx.getVert()[i][j])*(Gy.getVert()[i][j]*Gy.getVert()[i][j]));
      vide3[i][j]= sqrt((Gx.getBleu()[i][j]*Gx.getBleu()[i][j])*(Gy.getBleu()[i][j]*Gy.getBleu()[i][j]));
    }
  }
  return Image(vide1, vide2, vide3);
}

vector<vector<int>> saisirVecteur(int l, int c){
  vector<vector<int>> vect(l, vector<int>(c));
  for (int i = 0; i < l; i++) {
    for(int j = 0; j < c; j++) {
      cout << "Entrer la valeur de la case [" << i << "][" << j << "] : ";
      int x;
      cin >> x;
      vect[i][j] = x ;
    }
  }
  return(vect);
}

string normalisation(const string& nomfichier){
  if(nomfichier[nomfichier.size()-4] == '.' && nomfichier[nomfichier.size()-3] == 'p' && nomfichier[nomfichier.size()-2] == 'p' && nomfichier[nomfichier.size()-1] == 'm'){
    return nomfichier;
  }
  else{
    return nomfichier + ".ppm";
  }
}

Image Image::rotationCouleur()const{
  vector<vector<int>> vide1(largeur, vector<int>(longueur, 0));
  vector<vector<int>> vide2(largeur, vector<int>(longueur, 0));
  vector<vector<int>> vide3(largeur, vector<int>(longueur, 0));

  for (int i = 0; i < largeur; i++) {
    for (int j = 0; j < longueur; j++) {
        // Inversement des couleurs
        vide1[i][j] = bleu[i][j];
        vide2[i][j] = rouge[i][j];
        vide3[i][j] = vert[i][j];
    }
  }

  Image img(vide1, vide2, vide3);
  return(img);
}

Image Image::blanchirCouleur(int r, int v, int b)const{
  vector<vector<int>> vide1(largeur, vector<int>(longueur, 0));
  vector<vector<int>> vide2(largeur, vector<int>(longueur, 0));
  vector<vector<int>> vide3(largeur, vector<int>(longueur, 0));

  for (int i = 0; i < largeur; i++) {
    for (int j = 0; j < longueur; j++) {
        //test de verification de la condition de blanchissement
      if ( (sqrt(pow((rouge[i][j]-r),2.0) + pow((vert[i][j]-v),2.0) + pow((bleu[i][j]-r),2.0)) / sqrt(pow((rouge[i][j]),2.0) + pow((vert[i][j]),2.0) + pow((bleu[i][j]),2.0))) <= 0.1 ){
            vide1[i][j] = 255;
            vide2[i][j] = 255;
            vide2[i][j] = 255;
      }else{
            vide1[i][j] = rouge[i][j];
            vide2[i][j] = vert[i][j];
            vide2[i][j] = bleu[i][j];
      }
    }
  }

  return( Image(vide1, vide2, vide3));
}





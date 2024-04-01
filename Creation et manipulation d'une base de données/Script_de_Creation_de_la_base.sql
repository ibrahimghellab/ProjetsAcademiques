CREATE TABLE CLIENT(
   compteClient INT,
   nomClient VARCHAR(50) NOT NULL,
   prenomClient VARCHAR(50) NOT NULL,
   telephoneClient INT NOT NULL,
   categorieClient VARCHAR(10),
   dateNaissanceClient DATE,
   PRIMARY KEY(compteClient)
);

CREATE TABLE VILLE(
   numVille INT,
   nomVille VARCHAR(50) NOT NULL,
   adresseClient VARCHAR(50),
   PRIMARY KEY(numVille)
);

CREATE TABLE PAYS(
   numPays INT,
   nomPays VARCHAR(50) NOT NULL,
   PRIMARY KEY(numPays)
);

CREATE TABLE OFFRE(
   numOffre INT,
   NomOffre VARCHAR(50) NOT NULL,
   typeOffre VARCHAR(50) NOT NULL,
   prixOffre INT NOT NULL,
   PRIMARY KEY(numOffre)
);

CREATE TABLE SERVICES(
   numServices INT,
   NomService VARCHAR(50) NOT NULL,
   description VARCHAR(80) NOT NULL,
   coutMensuel INT NOT NULL,
   numOffre INT,
   PRIMARY KEY(numServices),
   FOREIGN KEY(numOffre) REFERENCES OFFRE(numOffre)
);

CREATE TABLE FACTURE(
   compteClient INT,
   numFacture INT,
   dateFacture DATE NOT NULL,
   statutPaiement VARCHAR(50) NOT NULL,
   methodePaiement VARCHAR(50),
   PRIMARY KEY(compteClient, numFacture),
   FOREIGN KEY(compteClient) REFERENCES CLIENT(compteClient)
);

CREATE TABLE CONTRAT(
   numContrat INT,
   typeContrat VARCHAR(50) NOT NULL,
   montantMensuel INT NOT NULL,
   statutContrat VARCHAR(50) NOT NULL,
   compteClient INT NOT NULL,
   PRIMARY KEY(numContrat),
   FOREIGN KEY(compteClient) REFERENCES CLIENT(compteClient)
);

CREATE TABLE EQUIPEMENT(
   numSerie INT,
   typeEquipement VARCHAR(50) NOT NULL,
   numContrat INT,
   PRIMARY KEY(numSerie),
   FOREIGN KEY(numContrat) REFERENCES CONTRAT(numContrat)
);

CREATE TABLE DUREE(
   numDate INT,
   dateDebut DATE NOT NULL,
   dateFin DATE NOT NULL,
   PRIMARY KEY(numDate)
);

CREATE TABLE EMPLOYE(
   numEmploye INT,
   nomEmploye VARCHAR(50) NOT NULL,
   prenomEmploye VARCHAR(50) NOT NULL,
   posteEmploye VARCHAR(50),
   dateEmbauche DATE,
   dateDepart DATE,
   PRIMARY KEY(numEmploye)
);

CREATE TABLE habite(
   compteClient INT,
   numVille INT,
   PRIMARY KEY(compteClient, numVille),
   FOREIGN KEY(compteClient) REFERENCES CLIENT(compteClient),
   FOREIGN KEY(numVille) REFERENCES VILLE(numVille)
);

CREATE TABLE se_trouve_dans(
   numVille INT,
   numPays INT,
   PRIMARY KEY(numVille, numPays),
   FOREIGN KEY(numVille) REFERENCES VILLE(numVille),
   FOREIGN KEY(numPays) REFERENCES PAYS(numPays)
);

CREATE TABLE comporte(
   numServices INT,
   numContrat INT,
   PRIMARY KEY(numServices, numContrat),
   FOREIGN KEY(numServices) REFERENCES SERVICES(numServices),
   FOREIGN KEY(numContrat) REFERENCES CONTRAT(numContrat)
);

CREATE TABLE dure(
   numContrat INT,
   numDate INT,
   PRIMARY KEY(numContrat, numDate),
   FOREIGN KEY(numContrat) REFERENCES CONTRAT(numContrat),
   FOREIGN KEY(numDate) REFERENCES DUREE(numDate)
);

CREATE TABLE dispose(
   compteClient INT,
   numSerie INT,
   etatEquipement VARCHAR(50),
   PRIMARY KEY(compteClient, numSerie),
   FOREIGN KEY(compteClient) REFERENCES CLIENT(compteClient),
   FOREIGN KEY(numSerie) REFERENCES EQUIPEMENT(numSerie)
);

CREATE TABLE gere(
   numContrat INT,
   numEmploye INT,
   PRIMARY KEY(numContrat, numEmploye),
   FOREIGN KEY(numContrat) REFERENCES CONTRAT(numContrat),
   FOREIGN KEY(numEmploye) REFERENCES EMPLOYE(numEmploye)
);

CREATE TABLE s_occupe(
   compteClient INT,
   numEmploye INT,
   PRIMARY KEY(compteClient, numEmploye),
   FOREIGN KEY(compteClient) REFERENCES CLIENT(compteClient),
   FOREIGN KEY(numEmploye) REFERENCES EMPLOYE(numEmploye)
);
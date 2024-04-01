--Nombre de particuliers et d entreprise qui sont client chez orange
 SELECT categorieClient,COUNT(compteClient) AS nombreClients
  FROM CLIENT
  GROUP BY categorieClient;


--Combien de contrats sont inactifs/actifs
SELECT statutContrat,COUNT(numContrat) AS nombreContrats
  FROM CONTRAT
  GROUP BY statutContrat;

-- Quel sont  les 3  pays avec le plus de clients
  SELECT P.nomPays,COUNT(CO.compteClient) AS nombreClients
  FROM PAYS P
  INNER JOIN se_trouve_dans std ON std.numPays=P.numPays
  INNER JOIN VILLE V ON V.numVille=std.numVille
  INNER JOIN habite h ON h.numVille=V.numVille
  INNER JOIN CLIENT CL ON CL.compteClient=h.compteClient
  INNER JOIN CONTRAT CO ON CO.compteClient=CL.compteClient
  GROUP BY P.nomPays
  ORDER BY COUNT(CO.compteClient) DESC
  LIMIT 3;


--Quel sont les clients qui ont des etatequipement déféctueux pour leur réparer
  SELECT nomClient,prenomClient
  FROM CLIENT C
  INNER JOIN dispose d ON C.compteClient=d.compteClient
  WHERE d.etatEquipement='Défectueux';


--Quel sont les factures non payées
SELECT nomClient,prenomClient
 FROM CLIENT C
 INNER JOIN FACTURE F ON C.compteClient=F.compteClient
 WHERE F.statutPaiement='En attente de paiement' ;


-- Quel est le service le plus demandé
SELECT NomService AS ServiceLePlusDemande,COUNT(CO.numContrat) AS NombreDemande
 FROM SERVICES S
 INNER JOIN comporte c ON S.numServices=c.numServices
 INNER JOIN CONTRAT CO ON c.numContrat=CO.numContrat
 GROUP BY NomService
 ORDER BY COUNT(CO.numContrat) DESC
 LIMIT 1;


-- Quel est le chiffre d'affaire total mensuel
SELECT SUM(montantMensuel) AS ChiffreAffaireMensuel
 FROM CONTRAT 
 WHERE statutContrat='Actif';

--Méthodes de paiement les plus couramment utilisées.
  SELECT methodePaiement,COUNT(numFacture) AS nombredeClient
  FROM FACTURE 
  WHERE methodePaiement IS NOT NULL
  GROUP BY methodePaiement
  ORDER BY COUNT(numFacture) DESC;

--L'offre mobile la plus intérésante
  SELECT NomOffre AS MeilleurOffreMobile
  FROM OFFRE
  WHERE typeOffre='Mobile'
  ORDER BY prixOffre
  LIMIT 1;


--L'offre internet la plus intéressante
  SELECT NomOffre AS MeilleurOffreInternet
  FROM OFFRE
  WHERE typeOffre='Internet'
  ORDER BY prixOffre
  LIMIT 1;

--Lister tous les clients de l'entreprise
SELECT *
FROM CLIENT;

--Lister tous les offres
SELECT *
FROM OFFRE;

--Lister tous les employées
SELECT *
FROM EMPLOYE;

--Liste du nombre d équipements selon si ils sont déféctueux ou en bonne etat
SELECT etatEquipement, COUNT(DISTINCT numSerie)
FROM dispose
GROUP BY etatEquipement;

--La recette des derniers mois
SELECT strftime('%Y-%m', dateFacture) AS mois, SUM(prixOffre) AS recette
FROM FACTURE f
JOIN CLIENT c ON f.compteClient = c.compteClient
JOIN CONTRAT ct ON c.compteClient = ct.compteClient
INNER JOIN comporte co ON co.numContrat = ct.numContrat
INNER JOIN SERVICES s ON s.numServices = co.numServices
INNER JOIN OFFRE o ON s.numOffre = o.numOffre
GROUP BY mois
ORDER BY mois DESC;

--Chaque employé s'occupe de combien de client
SELECT E.numEmploye, E.nomEmploye, E.prenomEmploye, E.posteEmploye, COUNT(*) AS nombreClients
FROM EMPLOYE E
INNER JOIN s_occupe SO ON E.numEmploye = SO.numEmploye
WHERE E.posteEmploye != 'Patron'
GROUP BY E.numEmploye, E.nomEmploye, E.prenomEmploye, E.posteEmploye;

--Combien d'équipements dans chaque ville
SELECT VILLE.nomVille, COUNT(EQUIPEMENT.numSerie) AS NombreEquipements
FROM VILLE
INNER JOIN habite ON VILLE.numVille = habite.numVille
INNER JOIN dispose ON habite.compteClient = dispose.compteClient
INNER JOIN EQUIPEMENT ON dispose.numSerie = EQUIPEMENT.numSerie
GROUP BY VILLE.numVille
ORDER BY VILLE.nomVille;

--Pour chaque offre combien y a-il de contrat
SELECT OFFRE.NomOffre, COUNT(CONTRAT.numContrat) AS nombreContrats
FROM OFFRE
LEFT JOIN SERVICES ON OFFRE.numOffre = SERVICES.numOffre
LEFT JOIN comporte ON SERVICES.numServices = comporte.numServices
LEFT JOIN CONTRAT ON comporte.numContrat = CONTRAT.numContrat
GROUP BY OFFRE.NomOffre
HAVING nombreContrats >= 1;

--Combien d'argent depense chaque client de l'entreprise par an
SELECT c.compteClient, c.nomClient, c.categorieClient, SUM(o.prixOffre) AS DepenseAnnuelle
FROM CLIENT c
INNER JOIN CONTRAT ct ON c.compteClient = ct.compteClient
INNER JOIN comporte co ON co.numContrat = ct.numContrat
INNER JOIN SERVICES s ON s.numServices = co.numServices
INNER JOIN OFFRE o ON s.numOffre = o.numOffre
INNER JOIN FACTURE f ON c.compteClient = f.compteClient
WHERE f.statutPaiement = 'Payée' AND strftime('%Y',f.dateFacture) = strftime('%Y',CURRENT_DATE)
GROUP BY c.compteClient;

--Nombre de contrats gérés par chaque employé
SELECT EMPLOYE.nomEmploye, EMPLOYE.prenomEmploye, COUNT(gere.numContrat) AS nombreContrats
FROM EMPLOYE
INNER JOIN gere ON EMPLOYE.numEmploye = gere.numEmploye
GROUP BY EMPLOYE.numEmploye;

--Affichage de l'historique des factures d'un client ( A remplacer par le compteClient du client que l'on recherche)
SELECT *
FROM FACTURE f
WHERE f.compteClient = 5
ORDER BY dateFacture DESC;

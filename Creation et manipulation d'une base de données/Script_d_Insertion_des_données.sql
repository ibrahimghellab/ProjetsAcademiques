INSERT INTO `CLIENT` 
VALUES
  (1,"Serina","Joyner","07 34 49 44 78","Particulier","04/01/88"),
  (2,"Sawyer","Chen","02 57 27 81 26","Particulier","01/31/81"),
  (3,"Joy","Hopkins","05 39 68 17 44","Entreprise","08/20/82"),
  (4,"Ivory","Lambert","03 52 51 74 62","Particulier","02/16/64"),
  (5,"Xenos","Miranda","04 47 14 45 23","Entreprise","11/06/84"),
  (6,"Noble","Donaldson","08 06 54 71 76","Entreprise","07/01/88"),
  (7,"Aaron","Duffy","08 24 75 41 75","Particulier","06/20/67"),
  (8,"Leigh","Maynard","05 38 27 83 37","Entreprise","12/17/61"),
  (9,"Audra","Diaz","07 14 55 45 27","Entreprise","04/02/93"),
  (10,"Lunea","Meyer","08 38 66 77 87","Entreprise","03/11/62"),
   (11,"Deacon","Cobb","07 83 71 82 21","Entreprise","02/01/51"),
  (12,"Eliana","Guy","02 36 97 26 75","Entreprise","10/13/66"),
  (13,"Graiden","Cunningham","06 16 54 14 41","Particulier","03/24/00"),
  (14,"Dean","Hale","08 67 25 46 38","Particulier","09/27/50"),
  (15,"Ethan","Knowles","07 89 66 55 71","Entreprise","01/21/86");



  INSERT INTO `DUREE` 
VALUES
  (1,"2020-10-08","2023-05-15"),
  (2,"2021-03-29","2024-01-05"),
  (3,"2021-02-28","2023-02-24"),
  (4,"2017-08-05","2023-06-22"),
  (5,"2022-10-18","2023-12-06"),
  (6,"2017-02-06","2024-09-21"),
  (7,"2017-06-11","2024-03-11"),
  (8,"2018-03-27","2023-02-21"),
  (9,"2018-11-22","2024-11-06"),
  (10,"2021-06-19","2023-08-27"),
  (11,"2017-03-10","2024-04-16"),
  (12,"2021-08-05","2023-10-12"),
  (13,"2019-04-21","2023-06-28"),
  (14,"2021-05-15","2023-12-10"),
  (15,"2018-08-19","2023-08-01");


INSERT INTO `EMPLOYE` 
VALUES
  (1,"Jacob","Steele","Patron","07/10/2019","21/12/2024"),
  (2,"Claire","Mcclain","Conseiller","26/08/2022",NULL),
  (3,"Daphne","Holt","Conseiller","08/11/2017",NULL),
  (4,"Yoshi","Cooke","Conseiller","08/01/2016","16/05/2024"),
  (5,"Hilda","Dixon","Patron","08/12/2013","06/10/2019"),
  (6,"Lee","Pitts","Conseiller","04/01/2020",NULL),
  (7,"Dennis","Perkins","Conseiller","29/04/2015","26/11/2023"),
  (8,"Hop","Flowers","Conseiller","11/01/2023","22/12/2023"),
  (9,"Dorothy","Gillespie","Conseiller","07/09/2023",NULL),
  (10,"Hollee","Adams","Conseiller","30/01/2015","11/12/2023"),
  (11,"Rosalyn","Leach","Conseiller","27/08/2019","30/01/2024"),
  (12,"Benedict","Mejia","Conseiller","25/02/2019","25/04/2023"),
  (13,"Ella","Ayers","Conseiller","25/12/2018",NULL),
  (14,"Josephine","Beach","Conseiller","26/06/2018","25/03/2023"),
  (15,"Tanisha","Schmidt","Conseiller","22/02/2019",NULL);






INSERT INTO `CONTRAT` VALUES
  (1, "Contrat Mobile", 50, "Actif", 5),
  (2, "Contrat Internet", 60, "Inactif", 6),
  (3, "Contrat TV", 45, "Actif", 8),
  (4, "Contrat Fibre Optique", 55, "Inactif", 10),
  (5, "Contrat Mobile", 55, "Actif", 12),
  (6, "Contrat Internet", 70, "Inactif", 14),
  (7, "Contrat TV", 60, "Actif", 2),
  (8, "Contrat Fibre Optique", 50, "Inactif", 4),
  (9, "Contrat Mobile", 65, "Actif", 9),
  (10, "Contrat Internet", 80, "Inactif", 11),
  (11, "Contrat TV", 70, "Actif", 1),
  (12, "Contrat Fibre Optique", 45, "Inactif", 3),
  (13, "Contrat Mobile", 75, "Actif", 7),
  (14, "Contrat TV", 65, "Inactif", 13),
  (15, "Contrat Internet", 80, "Actif", 15);

INSERT INTO `EQUIPEMENT` VALUES
  (1, "Routeur WiFi", 1),
  (2, "Décodeur TV", 2),
  (3, "Modem DSL", 3),
  (4, "Smartphone", 4),
  (5, "Switch Ethernet", 5),
  (6, "Antenne 4G", 6),
  (7, "Câble Ethernet", 7),
  (8, "Répéteur WiFi", 8),
  (9, "Décodeur TV", 9),
  (10, "Routeur WiFi", 10),
  (11, "Modem DSL", 11),
  (12, "Smartphone", 12),
  (13, "Switch Ethernet", 13),
  (14, "Antenne 4G", 14),
  (15, "Câble Ethernet", 15);

INSERT INTO `FACTURE` VALUES
  (1, 1, "2023-01-15", "Payée", "Carte de crédit"),
  (2, 2, "2023-02-10", "En attente de paiement", NULL),
  (3, 3, "2023-03-05", "Payée", "Virement bancaire"),
  (4, 4, "2023-04-20", "En attente de paiement", NULL),
  (5, 5, "2023-05-15", "Payée", "Chèque"),
  (6, 6, "2023-06-10", "En attente de paiement", NULL),
  (7, 7, "2023-07-05", "Payée", "Carte de crédit"),
  (8, 8, "2023-08-20", "En attente de paiement", NULL),
  (9, 9, "2023-09-15", "Payée", "Virement bancaire"),
  (10, 10, "2023-10-10", "En attente de paiement", NULL),
  (11, 11, "2023-11-05", "Payée", "Chèque"),
  (12, 12, "2023-12-20", "En attente de paiement", NULL),
  (13, 13, "2024-01-15", "Payée", "Carte de crédit"),
  (14, 14, "2024-02-10", "En attente de paiement", NULL),
  (15, 15, "2024-03-05", "Payée", "Virement bancaire");

INSERT INTO `OFFRE` VALUES
  (1, "Forfait Mobile Illimité", "Mobile", 30),
  (2, "Internet Haut Débit", "Internet", 40),
  (3, "Forfait TV Premium", "TV", 20),
  (4, "Forfait Combiné", "Combinaison", 70),
  (5, "Internet Fibre Optique", "Internet", 50),
  (6, "Forfait Famille", "Combinaison", 80),
  (7, "Forfait Entreprise", "Entreprise", 100),
  (8, "Forfait Étudiant", "Mobile", 25),
  (9, "Forfait Sénior", "Mobile", 20),
  (10, "Internet Illimité", "Internet", 60);

INSERT INTO `PAYS` VALUES
  (1, "France"),
  (2, "Espagne"),
  (3, "Italie"),
  (4, "Allemagne"),
  (5, "Royaume-Uni"),
  (6, "États-Unis"),
  (7, "Canada"),
  (8, "Japon"),
  (9, "Chine"),
  (10, "Brésil");


INSERT INTO SERVICES VALUES
  (1, "Service Premium de Messagerie", "Messagerie électronique sécurisée avec stockage illimité", 20, 1),
  (2, "Service de Sécurité Avancée", "Protection antivirus, pare-feu et surveillance proactive", 30, 2),
  (3, "Chaînes TV Ultra Premium", "Accès exclusif à des chaînes haut de gamme et à la demande", 25, 3),
  (4, "Forfait Entreprise Premium", "Solutions avancées de communication et de connectivité", 50, 4),
  (5, "Service VoIP Entreprise", "Appels vocaux sur Internet avec fonctionnalités professionnelles", 40, 5),
  (6, "Service de Streaming 4K", "Accès à une bibliothèque étendue de contenu en ultra haute définition", 35, 6),
  (7, "Service de Connexion Internationale VIP", "Options d'appels et de données à l'étranger avec service prioritaire", 60, 7),
  (8, "Forfait Étudiant Premium", "Offre exclusive pour les étudiants avec des avantages haut de gamme", 50, 8),
  (9, "Service Télétravail Avancé", "Solutions avancées pour faciliter le travail à distance", 70, 9),
  (10, "Service de Support Client VIP", "Assistance clientèle 24/7 avec traitement VIP", 45, 10);

INSERT INTO VILLE VALUES
  (1, "Paris", "123 Rue de la République"),
  (2, "Barcelone", "456 Carrer de Mallorca"),
  (3, "Rome", "789 Via del Corso"),
  (4, "Berlin", "101 Unter den Linden"),
  (5, "Londres", "456 Oxford Street"),
  (6, "New York", "789 Fifth Avenue"),
  (7, "Toronto", "123 Yonge Street"),
  (8, "Tokyo", "456 Shibuya Crossing"),
  (9, "Pékin", "789 Wangfujing Street"),
  (10, "Rio de Janeiro", "123 Copacabana Beach");
  
INSERT INTO comporte VALUES
  (1, 15),
  (2, 3),
  (3, 3),
  (4, 4),
  (5, 5),
  (6, 12),
  (7, 7),
  (8, 8),
  (9, 11),
  (10, 10);
  
  INSERT INTO dispose VALUES
  (1, 6, "En bon état"),
  (2, 5, "Défectueux"),
  (3, 12, "En bon état"),
  (4, 4, "En bon état"),
  (5, 5, "Défectueux"),
  (6, 9, "En bon état"),
  (7, 7, "En bon état"),
  (8, 8, "Défectueux"),
  (9, 9, "En bon état"),
  (10, 4, "Défectueux"),
  (11, 11, "En bon état"),
  (12, 1, "En bon état"),
  (13, 5, "Défectueux"),
  (14, 14, "En bon état"),
  (15, 13, "En bon état");
  
  
  INSERT INTO dure VALUES
  (1, 1),
  (2, 2),
  (3, 3),
  (4, 4),
  (5, 5),
  (6, 6),
  (7, 7),
  (8, 8),
  (9, 9),
  (10, 10),
  (11, 11),
  (12, 12),
  (13, 13),
  (14, 14),
  (15, 15);
  
  INSERT INTO gere VALUES
  (1, 1),
  (2, 2),
  (3, 3),
  (4, 4),
  (5, 5),
  (6, 6),
  (7, 7),
  (8, 8),
  (9, 9),
  (10, 10),
  (11, 11),
  (12, 12),
  (13, 13),
  (14, 14),
  (15, 15);

  
  INSERT INTO habite VALUES
  (1, 1),
  (2, 2),
  (3, 3),
  (4, 4),
  (5, 5),
  (6, 6),
  (7, 7),
  (8, 8),
  (9, 9),
  (10, 10),
  (11, 1),
  (12, 2),
  (13, 3),
  (14, 4),
  (15, 5);
  
  INSERT INTO s_occupe VALUES
  (1, 1),
  (1, 2),
  (2, 3),
  (2, 4),
  (3, 5),
  (3, 6),
  (4, 7),
  (4, 8),
  (5, 9),
  (5, 10),
  (6, 11),
  (6, 12),
  (7, 13),
  (7, 14),
  (8, 15);
  
  INSERT INTO se_trouve_dans VALUES
  (1, 1),
  (2, 2),
  (3, 3),
  (4, 4),
  (5, 5),
  (6, 6),
  (7, 7),
  (8, 8),
  (9, 9),
  (10, 10);  

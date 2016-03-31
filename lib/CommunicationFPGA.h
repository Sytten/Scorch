/*
*   CommunicationFPGA est une classe d'interface à la pour la communication
*   avec la carte FPGA de la session S2. Pour les details de l'utilisation
*   de cette classe, consultez le guide d'utilisation.
*   
*   $Author: bruc2001 $
*   $Date: 2014-12-18 11:43:08 -0500 (jeu., 18 déc. 2014) $
*   $Revision: 103 $
*   $Id: CommunicationFPGA.h 103 2014-12-18 16:43:08Z bruc2001 $
*
*   Copyright 2013 Département de génie électrique et génie informatique
*                  Université de Sherbrooke  
*/

#ifndef COMMUNICATIONFPGA_H
#define COMMUNICATIONFPGA_H

#include <windows.h>

using namespace std;

enum Registre {SW=8, BTN=9, LD=10, AN0=11, AN1=12, AN2=13, AN3=14};

class CommunicationFPGA {
public:
    CommunicationFPGA();
	~CommunicationFPGA();

	bool lireRegistre(int registre, int &valeur);
	bool ecrireRegistre(int registre, int valeur);
	void sleep(unsigned int millisecondes = 10);

	bool estOk();
	const char * messageErreur();
private:
	bool erreur;
    char msgErreur[1024];
	unsigned long hif;
};

#endif

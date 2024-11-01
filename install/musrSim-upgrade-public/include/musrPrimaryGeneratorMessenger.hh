/***************************************************************************
 *  musrSim - the program for the simulation of (mainly) muSR instruments. *
 *          More info on http://lmu.web.psi.ch/simulation/index.html .     *
 *          musrSim is based od Geant4 (http://geant4.web.cern.ch/geant4/) *
 *                                                                         *
 *  Copyright (C) 2009 by Paul Scherrer Institut, 5232 Villigen PSI,       *
 *                                                       Switzerland       *
 *                                                                         *
 *  This program is free software; you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation; either version 2 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This program is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with this program; if not, write to the Free Software            *
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.              *
 ***************************************************************************/

#ifndef musrPrimaryGeneratorMessenger_h
#define musrPrimaryGeneratorMessenger_h 1

#include "G4UImessenger.hh"
#include "globals.hh"
#include "G4UIcmdWithABool.hh"

class musrPrimaryGeneratorAction;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithADouble;
class G4UIcmdWithAnInteger;
class G4UIcmdWith3VectorAndUnit;
class G4UIcmdWith3Vector;
class G4UIcmdWithoutParameter;
class G4UIcommand;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class musrPrimaryGeneratorMessenger: public G4UImessenger
{
  public:
    musrPrimaryGeneratorMessenger(musrPrimaryGeneratorAction*);
   ~musrPrimaryGeneratorMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
  private:
    musrPrimaryGeneratorAction* musrAction;
    G4UIcmdWithAString*        setPrimaryParticleCmd; 
    G4UIcmdWith3VectorAndUnit* setvertexCmd;
    G4UIcmdWith3VectorAndUnit* setvertexSigmaCmd;
    G4UIcmdWith3VectorAndUnit* setvertexBoundaryCmd;
    G4UIcmdWithADoubleAndUnit* setvertexRelativeRCmd;
    G4UIcmdWithADoubleAndUnit* setMeanArrivalTimeCmd;
    G4UIcmdWithADoubleAndUnit* setStarttimeCmd;           //P.B. 13 May 2009
    G4UIcmdWithADoubleAndUnit* setStarttimeSigmaCmd;      //P.B. 13 May 2009
    G4UIcmdWith3VectorAndUnit* setboxBoundaryCmd;         //P.B. 15 Dec 2009
    G4UIcmdWith3VectorAndUnit* setboxBoundaryCentreCmd;   //P.B. 15 Dec 2009
    G4UIcmdWithADoubleAndUnit* setKEnergyCmd;
    G4UIcmdWithADoubleAndUnit* setMomentumCmd;

    G4UIcmdWithABool*          setCosmicMuonCmd;          // Added by Meng Lv to introduce cosmic muon energy distribution. Aug 5 2022

    G4UIdirectory*             cryDir;                    // Added by Y. ZENG 23 Apr 2024
    G4UIcmdWithABool*          setCRYCmd;                 // Added by Y. ZENG 23 Apr 2024
    G4UIcmdWithAString*        setCRYInputCmd;            // Added by Y. ZENG 23 Apr 2024
    G4UIcmdWithoutParameter*   updateCRYCmd;              // Added by Y. ZENG 23 Apr 2024
    std::string* MessInput;                               // Added by Y. ZENG 23 Apr 2024
    G4UIcmdWithAString*        setCRYFileCmd;             // Added by Y. ZENG 23 Apr 2024

    G4UIdirectory*             ecomugDir;                 // Added by Y. ZENG 25 Apr 2024
    G4UIcmdWithABool*          setEcoMugCmd;              // Added by Y. ZENG 25 Apr 2024
    G4UIcommand*               setShapeConstructCmd;      // Added by Y. ZENG 25 Apr 2024
    G4UIcommand*               setConstraintsCmd;         // Added by Y. ZENG 25 Apr 2024

    G4UIcmdWithADoubleAndUnit* setMomentumSmearingCmd;
    G4UIcmdWith3VectorAndUnit* setMomentumBoundaryCmd;
    G4UIcmdWith3VectorAndUnit* setTiltAngleCmd;
    G4UIcmdWith3VectorAndUnit* setSigmaTiltAngleCmd;
    G4UIcmdWithADoubleAndUnit* setPitchCmd;
    G4UIcmdWith3Vector*        setMuonPolarizCmd;
    G4UIcmdWith3Vector*        setDirectionCmd;
    G4UIcmdWithADouble*        setMuonPolarizFractionCmd;
    G4UIcmdWith3VectorAndUnit* setMuonDecayTimeCmd;
    G4UIcmdWithAString*        setTurtleCmd;
    G4UIcmdWithADoubleAndUnit* setTurtleZ0Cmd;
    G4UIcmdWithAString*        setTurtleInterpretAxesCmd;
    G4UIcmdWith3Vector*        setTurtleMomentumBite;
    G4UIcmdWithADouble*        setTurtleMomentumScalingFactor;
    G4UIcmdWithAnInteger*      setTurtleEventNrCmd;
};
#endif


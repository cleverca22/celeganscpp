// Yippee! My first ever C program is a Connectome of the C. Elegans!
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

typedef struct {
    void (*fireNeuron)();
    int values[2];
} neuron;

enum {
  nADAL,nADAR,nADEL,nADER,nADFL,nADFR,nADL,nADLL,nADLR,nAFDL,nAFDR,nAIAL,nAIAR,nAIBL,nAIBR,nAIML,nAIMR,nAINL,nAINR,nAIYL,nAIYR,nAIZL,nAIZR,nALA,nALML,nALMR,nALNL,nALNR,nAQR,nAS1,nAS10,nAS11,nAS2,nAS3,nAS4,nAS5,nAS6,nAS7,nAS8,nAS9,nASEL,nASER,nASGL,nASGLL,nASGR,nASHL,nASHR,nASIL,nASIR,nASJL,nASJR,nASKL,nASKR,nAUAL,nAUAR,nAVAL,nAVAR,nAVBL,nAVBR,nAVDL,nAVDR,nAVEL,nAVER,nAVFL,nAVFR,nAVG,nAVHL,nAVHR,nAVJL,nAVJR,nAVKL,nAVKR,nAVL,nAVM,nAWAL,nAWAR,nAWBL,nAWBR,nAWCL,nAWCR,nBAGL,nBAGR,nBDUL,nBDUR,nCEPDL,nCEPDR,nCEPVL,nCEPVR,nDA1,nDA2,nDA3,nDA4,nDA5,nDA6,nDA7,nDA8,nDA9,nDB1,nDB2,nDB3,nDB4,nDB5,nDB6,nDB7,nDD1,nDD2,nDD3,nDD4,nDD5,nDD6,nDVA,nDVB,nDVC,nFLPL,nFLPR,nHSNL,nHSNR,nI1L,nI1R,nI2L,nI2R,nI3,nI4,nI5,nI6,nIL1DL,nIL1DR,nIL1L,nIL1R,nIL1VL,nIL1VR,nIL2DL,nIL2DR,nIL2L,nIL2R,nIL2VL,nIL2VR,nLUAL,nLUAR,nM1,nM2L,nM2R,nM3L,nM3R,nM4,nM5,nMANAL,nMCL,nMCR,
  nMDL01,nMDL02,nMDL03,nMDL04,nMDL05,nMDL06,nMDL07,nMDL08,nMDL09,nMDL10,nMDL11,nMDL12,nMDL13,nMDL14,nMDL15,nMDL16,nMDL17,nMDL18,nMDL19,nMDL20,nMDL21,nMDL22,nMDL23,nMDL24,
  nMDR01,nMDR02,nMDR03,nMDR04,nMDR05,nMDR06,nMDR07,nMDR08,nMDR09,nMDR10,nMDR11,nMDR12,nMDR13,nMDR14,nMDR15,nMDR16,nMDR17,nMDR18,nMDR19,nMDR20,nMDR21,nMDR22,nMDR23,nMDR24,
  nMI,
  nMVL01,nMVL02,nMVL03,nMVL04,nMVL05,nMVL06,nMVL07,nMVL08,nMVL09,nMVL10,nMVL11,nMVL12,nMVL13,nMVL14,nMVL15,nMVL16,nMVL17,nMVL18,nMVL19,nMVL20,nMVL21,nMVL22,nMVL23,
  nMVR01,nMVR02,nMVR03,nMVR04,nMVR05,nMVR06,nMVR07,nMVR08,nMVR09,nMVR10,nMVR11,nMVR12,nMVR13,nMVR14,nMVR15,nMVR16,nMVR17,nMVR18,nMVR19,nMVR20,nMVR21,nMVR22,nMVR23,nMVR24,
  nMVULVA,nNSML,nNSMR,nOLLL,nOLLR,nOLQDL,nOLQDR,nOLQVL,nOLQVR,nPDA,nPDB,nPDEL,nPDER,nPHAL,nPHAR,nPHBL,nPHBR,nPHCL,nPHCR,nPLML,nPLMR,nPLNL,nPLNR,nPQR,nPVCL,nPVCR,nPVDL,nPVDR,nPVM,nPVNL,nPVNR,nPVPL,nPVPR,nPVQL,nPVQR,nPVR,nPVT,nPVWL,nPVWR,nRIAL,nRIAR,nRIBL,nRIBR,nRICL,nRICR,nRID,nRIFL,nRIFR,nRIGL,nRIGR,nRIH,nRIML,nRIMR,nRIPL,nRIPR,nRIR,nRIS,nRIVL,nRIVR,nRMDDL,nRMDDR,nRMDL,nRMDR,nRMDVL,nRMDVR,nRMED,nRMEL,nRMER,nRMEV,nRMFL,nRMFR,nRMGL,nRMGR,nRMHL,nRMHR,nSAADL,nSAADR,nSAAVL,nSAAVR,nSABD,nSABVL,nSABVR,nSDQL,nSDQR,nSIADL,nSIADR,nSIAVL,nSIAVR,nSIBDL,nSIBDR,nSIBVL,nSIBVR,nSMBDL,nSMBDR,nSMBVL,nSMBVR,nSMDDL,nSMDDR,nSMDVL,nSMDVR,nURADL,nURADR,nURAVL,nURAVR,nURBL,nURBR,nURXL,nURXR,nURYDL,nURYDR,nURYVL,nURYVR,nVA1,nVA10,nVA11,nVA12,nVA2,nVA3,nVA4,nVA5,nVA6,nVA7,nVA8,nVA9,nVB1,nVB10,nVB11,nVB2,nVB3,nVB4,nVB5,nVB6,nVB7,nVB8,nVB9,nVC1,nVC2,nVC3,nVC4,nVC5,nVC6,nVD1,nVD10,nVD11,nVD12,nVD13,nVD2,nVD3,nVD4,nVD5,nVD6,nVD7,nVD8,nVD9,
  neuron_count
};

neuron postSynaptic[neuron_count];

int thisState = 0;
int nextState = 1;

const int fireThreshold = 30;

int accumLeft = 0;
int accumRight = 0;

bool stimulateHungerNeurons = true;
bool stimulateNoseTouchNeurons = false;
bool stimulateFoodSenseNeurons = false;

void ADAL() {
    postSynaptic[nADAR].values[nextState] += 2;
    postSynaptic[nADFL].values[nextState] += 1;
    postSynaptic[nAIBL].values[nextState] += 1;
    postSynaptic[nAIBR].values[nextState] += 2;
    postSynaptic[nASHL].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 2;
    postSynaptic[nAVBL].values[nextState] += 4;
    postSynaptic[nAVBR].values[nextState] += 7;
    postSynaptic[nAVDL].values[nextState] += 1;
    postSynaptic[nAVDR].values[nextState] += 2;
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nAVJR].values[nextState] += 5;
    postSynaptic[nFLPR].values[nextState] += 1;
    postSynaptic[nPVQL].values[nextState] += 1;
    postSynaptic[nRICL].values[nextState] += 1;
    postSynaptic[nRICR].values[nextState] += 1;
    postSynaptic[nRIML].values[nextState] += 3;
    postSynaptic[nRIPL].values[nextState] += 1;
    postSynaptic[nSMDVR].values[nextState] += 2;
}

void ADAR() {
    postSynaptic[nADAL].values[nextState] += 1;
    postSynaptic[nADFR].values[nextState] += 1;
    postSynaptic[nAIBL].values[nextState] += 1;
    postSynaptic[nAIBR].values[nextState] += 1;
    postSynaptic[nASHR].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 5;
    postSynaptic[nAVDL].values[nextState] += 2;
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nAVJL].values[nextState] += 3;
    postSynaptic[nPVQR].values[nextState] += 1;
    postSynaptic[nRICL].values[nextState] += 1;
    postSynaptic[nRIMR].values[nextState] += 5;
    postSynaptic[nRIPR].values[nextState] += 1;
    postSynaptic[nRIVR].values[nextState] += 1;
    postSynaptic[nSMDVL].values[nextState] += 2;
}

void ADEL() {
    postSynaptic[nADAL].values[nextState] += 1;
    postSynaptic[nADER].values[nextState] += 1;
    postSynaptic[nAINL].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 2;
    postSynaptic[nAVAR].values[nextState] += 3;
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nAVKR].values[nextState] += 1;
    postSynaptic[nAVL].values[nextState] += 1;
    postSynaptic[nBDUL].values[nextState] += 1;
    postSynaptic[nCEPDL].values[nextState] += 1;
    postSynaptic[nFLPL].values[nextState] += 1;
    postSynaptic[nIL1L].values[nextState] += 1;
    postSynaptic[nIL2L].values[nextState] += 1;
    postSynaptic[nMDL05].values[nextState] += 1;
    postSynaptic[nOLLL].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 1;
    postSynaptic[nRIFL].values[nextState] += 1;
    postSynaptic[nRIGL].values[nextState] += 5;
    postSynaptic[nRIGR].values[nextState] += 3;
    postSynaptic[nRIH].values[nextState] += 2;
    postSynaptic[nRIVL].values[nextState] += 1;
    postSynaptic[nRIVR].values[nextState] += 1;
    postSynaptic[nRMDL].values[nextState] += 2;
    postSynaptic[nRMGL].values[nextState] += 1;
    postSynaptic[nRMHL].values[nextState] += 1;
    postSynaptic[nSIADR].values[nextState] += 1;
    postSynaptic[nSIBDR].values[nextState] += 1;
    postSynaptic[nSMBDR].values[nextState] += 1;
    postSynaptic[nURBL].values[nextState] += 1;
}

void ADER() {
    postSynaptic[nADAR].values[nextState] += 1;
    postSynaptic[nADEL].values[nextState] += 2;
    postSynaptic[nALA].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 5;
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nAVDR].values[nextState] += 2;
    postSynaptic[nAVER].values[nextState] += 1;
    postSynaptic[nAVJR].values[nextState] += 1;
    postSynaptic[nAVKL].values[nextState] += 2;
    postSynaptic[nAVKR].values[nextState] += 1;
    postSynaptic[nCEPDR].values[nextState] += 1;
    postSynaptic[nFLPL].values[nextState] += 1;
    postSynaptic[nFLPR].values[nextState] += 1;
    postSynaptic[nOLLR].values[nextState] += 2;
    postSynaptic[nPVR].values[nextState] += 1;
    postSynaptic[nRIGL].values[nextState] += 7;
    postSynaptic[nRIGR].values[nextState] += 4;
    postSynaptic[nRIH].values[nextState] += 1;
    postSynaptic[nRMDR].values[nextState] += 2;
    postSynaptic[nSAAVR].values[nextState] += 1;
}

void ADFL() {
    postSynaptic[nADAL].values[nextState] += 2;
    postSynaptic[nAIZL].values[nextState] += 12;
    postSynaptic[nAUAL].values[nextState] += 5;
    postSynaptic[nOLQVL].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 15;
    postSynaptic[nRIGL].values[nextState] += 1;
    postSynaptic[nRIR].values[nextState] += 2;
    postSynaptic[nSMBVL].values[nextState] += 2;
}

void ADFR() {
    postSynaptic[nADAR].values[nextState] += 2;
    postSynaptic[nAIAR].values[nextState] += 1;
    postSynaptic[nAIYR].values[nextState] += 1;
    postSynaptic[nAIZR].values[nextState] += 8;
    postSynaptic[nASHR].values[nextState] += 1;
    postSynaptic[nAUAR].values[nextState] += 4;
    postSynaptic[nAWBR].values[nextState] += 1;
    postSynaptic[nPVPR].values[nextState] += 1;
    postSynaptic[nRIAR].values[nextState] += 16;
    postSynaptic[nRIGR].values[nextState] += 3;
    postSynaptic[nRIR].values[nextState] += 3;
    postSynaptic[nSMBDR].values[nextState] += 1;
    postSynaptic[nSMBVR].values[nextState] += 2;
    postSynaptic[nURXR].values[nextState] += 1;
}

void ADLL() {
    postSynaptic[nADLR].values[nextState] += 1;
    postSynaptic[nAIAL].values[nextState] += 6;
    postSynaptic[nAIBL].values[nextState] += 7;
    postSynaptic[nAIBR].values[nextState] += 1;
    postSynaptic[nALA].values[nextState] += 2;
    postSynaptic[nASER].values[nextState] += 3;
    postSynaptic[nASHL].values[nextState] += 2;
    postSynaptic[nAVAL].values[nextState] += 2;
    postSynaptic[nAVAR].values[nextState] += 3;
    postSynaptic[nAVBL].values[nextState] += 2;
    postSynaptic[nAVDL].values[nextState] += 1;
    postSynaptic[nAVDR].values[nextState] += 1;
    postSynaptic[nAVJL].values[nextState] += 1;
    postSynaptic[nAVJR].values[nextState] += 3;
    postSynaptic[nAWBL].values[nextState] += 2;
    postSynaptic[nOLQVL].values[nextState] += 2;
    postSynaptic[nRIPL].values[nextState] += 1;
    postSynaptic[nRMGL].values[nextState] += 1;
}

void ADLR() {
    postSynaptic[nADLL].values[nextState] += 1;
    postSynaptic[nAIAR].values[nextState] += 10;
    postSynaptic[nAIBR].values[nextState] += 10;
    postSynaptic[nASER].values[nextState] += 1;
    postSynaptic[nASHR].values[nextState] += 3;
    postSynaptic[nAVAR].values[nextState] += 2;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 2;
    postSynaptic[nAVDL].values[nextState] += 5;
    postSynaptic[nAVDR].values[nextState] += 2;
    postSynaptic[nAVJR].values[nextState] += 1;
    postSynaptic[nAWCR].values[nextState] += 3;
    postSynaptic[nOLLR].values[nextState] += 1;
    postSynaptic[nPVCL].values[nextState] += 1;
    postSynaptic[nRICL].values[nextState] += 1;
    postSynaptic[nRICR].values[nextState] += 1;
}

void AFDL() {
    postSynaptic[nAFDR].values[nextState] += 1;
    postSynaptic[nAIBL].values[nextState] += 1;
    postSynaptic[nAINR].values[nextState] += 1;
    postSynaptic[nAIYL].values[nextState] += 7;
}

void AFDR() {
    postSynaptic[nAFDL].values[nextState] += 1;
    postSynaptic[nAIBR].values[nextState] += 1;
    postSynaptic[nAIYR].values[nextState] += 13;
    postSynaptic[nASER].values[nextState] += 1;
}

void AIAL() {
    postSynaptic[nADAL].values[nextState] += 1;
    postSynaptic[nAIAR].values[nextState] += 1;
    postSynaptic[nAIBL].values[nextState] += 10;
    postSynaptic[nAIML].values[nextState] += 2;
    postSynaptic[nAIZL].values[nextState] += 1;
    postSynaptic[nASER].values[nextState] += 3;
    postSynaptic[nASGL].values[nextState] += 1;
    postSynaptic[nASHL].values[nextState] += 1;
    postSynaptic[nASIL].values[nextState] += 2;
    postSynaptic[nASKL].values[nextState] += 3;
    postSynaptic[nAWAL].values[nextState] += 1;
    postSynaptic[nAWCR].values[nextState] += 1;
    postSynaptic[nHSNL].values[nextState] += 1;
    postSynaptic[nRIFL].values[nextState] += 1;
    postSynaptic[nRMGL].values[nextState] += 1;
}

void AIAR() {
    postSynaptic[nADAR].values[nextState] += 1;
    postSynaptic[nADFR].values[nextState] += 1;
    postSynaptic[nADLR].values[nextState] += 2;
    postSynaptic[nAIAL].values[nextState] += 1;
    postSynaptic[nAIBR].values[nextState] += 14;
    postSynaptic[nAIZR].values[nextState] += 1;
    postSynaptic[nASER].values[nextState] += 1;
    postSynaptic[nASGR].values[nextState] += 1;
    postSynaptic[nASIR].values[nextState] += 2;
    postSynaptic[nAWAR].values[nextState] += 2;
    postSynaptic[nAWCL].values[nextState] += 1;
    postSynaptic[nAWCR].values[nextState] += 3;
    postSynaptic[nRIFR].values[nextState] += 2;
}

void AIBL() {
    postSynaptic[nAFDL].values[nextState] += 1;
    postSynaptic[nAIYL].values[nextState] += 1;
    postSynaptic[nASER].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 2;
    postSynaptic[nAVBL].values[nextState] += 5;
    postSynaptic[nDVC].values[nextState] += 1;
    postSynaptic[nFLPL].values[nextState] += 1;
    postSynaptic[nPVT].values[nextState] += 1;
    postSynaptic[nRIBR].values[nextState] += 4;
    postSynaptic[nRIFL].values[nextState] += 1;
    postSynaptic[nRIGR].values[nextState] += 3;
    postSynaptic[nRIML].values[nextState] += 2;
    postSynaptic[nRIMR].values[nextState] += 1;
    postSynaptic[nRIVL].values[nextState] += 1;
    postSynaptic[nSAADL].values[nextState] += 2;
    postSynaptic[nSAADR].values[nextState] += 2;
    postSynaptic[nSMDDR].values[nextState] += 4;
}

void AIBR() {
    postSynaptic[nAFDR].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 3;
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nDB1].values[nextState] += 1;
    postSynaptic[nDVC].values[nextState] += 2;
    postSynaptic[nPVT].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 1;
    postSynaptic[nRIBL].values[nextState] += 4;
    postSynaptic[nRIGL].values[nextState] += 3;
    postSynaptic[nRIML].values[nextState] += 1;
    postSynaptic[nRIMR].values[nextState] += 1;
    postSynaptic[nRIS].values[nextState] += 1;
    postSynaptic[nRIVR].values[nextState] += 1;
    postSynaptic[nSAADL].values[nextState] += 1;
    postSynaptic[nSMDDL].values[nextState] += 3;
    postSynaptic[nSMDVL].values[nextState] += 1;
    postSynaptic[nVB1].values[nextState] += 3;
}

void AIML() {
    postSynaptic[nAIAL].values[nextState] += 5;
    postSynaptic[nALML].values[nextState] += 1;
    postSynaptic[nASGL].values[nextState] += 2;
    postSynaptic[nASKL].values[nextState] += 2;
    postSynaptic[nAVBR].values[nextState] += 2;
    postSynaptic[nAVDL].values[nextState] += 1;
    postSynaptic[nAVDR].values[nextState] += 1;
    postSynaptic[nAVER].values[nextState] += 1;
    postSynaptic[nAVFL].values[nextState] += 4;
    postSynaptic[nAVFR].values[nextState] += 1;
    postSynaptic[nAVHL].values[nextState] += 2;
    postSynaptic[nAVHR].values[nextState] += 1;
    postSynaptic[nAVJL].values[nextState] += 1;
    postSynaptic[nPVQL].values[nextState] += 1;
    postSynaptic[nRIFL].values[nextState] += 1;
    postSynaptic[nSIBDR].values[nextState] += 1;
    postSynaptic[nSMBVL].values[nextState] += 1;
}

void AIMR() {
    postSynaptic[nAIAR].values[nextState] += 5;
    postSynaptic[nASGR].values[nextState] += 2;
    postSynaptic[nASJR].values[nextState] += 2;
    postSynaptic[nASKR].values[nextState] += 3;
    postSynaptic[nAVDR].values[nextState] += 1;
    postSynaptic[nAVFL].values[nextState] += 1;
    postSynaptic[nAVFR].values[nextState] += 1;
    postSynaptic[nHSNL].values[nextState] += 1;
    postSynaptic[nHSNR].values[nextState] += 2;
    postSynaptic[nOLQDR].values[nextState] += 1;
    postSynaptic[nPVNR].values[nextState] += 1;
    postSynaptic[nRIFR].values[nextState] += 1;
    postSynaptic[nRMGR].values[nextState] += 1;
}

void AINL() {
    postSynaptic[nADEL].values[nextState] += 1;
    postSynaptic[nAFDR].values[nextState] += 5;
    postSynaptic[nAINR].values[nextState] += 2;
    postSynaptic[nASEL].values[nextState] += 3;
    postSynaptic[nASGR].values[nextState] += 2;
    postSynaptic[nAUAR].values[nextState] += 2;
    postSynaptic[nBAGL].values[nextState] += 3;
    postSynaptic[nRIBL].values[nextState] += 1;
    postSynaptic[nRIBR].values[nextState] += 2;
}

void AINR() {
    postSynaptic[nAFDL].values[nextState] += 4;
    postSynaptic[nAFDR].values[nextState] += 1;
    postSynaptic[nAIAL].values[nextState] += 2;
    postSynaptic[nAIBL].values[nextState] += 2;
    postSynaptic[nAINL].values[nextState] += 2;
    postSynaptic[nASEL].values[nextState] += 1;
    postSynaptic[nASER].values[nextState] += 1;
    postSynaptic[nASGL].values[nextState] += 1;
    postSynaptic[nAUAL].values[nextState] += 1;
    postSynaptic[nAUAR].values[nextState] += 1;
    postSynaptic[nBAGR].values[nextState] += 3;
    postSynaptic[nRIBL].values[nextState] += 2;
    postSynaptic[nRID].values[nextState] += 1;
}

void AIYL() {
    postSynaptic[nAIYR].values[nextState] += 1;
    postSynaptic[nAIZL].values[nextState] += 13;
    postSynaptic[nAWAL].values[nextState] += 3;
    postSynaptic[nAWCL].values[nextState] += 1;
    postSynaptic[nAWCR].values[nextState] += 1;
    postSynaptic[nHSNR].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 7;
    postSynaptic[nRIBL].values[nextState] += 4;
    postSynaptic[nRIML].values[nextState] += 1;
}

void AIYR() {
    postSynaptic[nADFR].values[nextState] += 1;
    postSynaptic[nAIYL].values[nextState] += 1;
    postSynaptic[nAIZR].values[nextState] += 8;
    postSynaptic[nAWAR].values[nextState] += 1;
    postSynaptic[nHSNL].values[nextState] += 1;
    postSynaptic[nRIAR].values[nextState] += 6;
    postSynaptic[nRIBR].values[nextState] += 2;
    postSynaptic[nRIMR].values[nextState] += 1;
}

void AIZL() {
    postSynaptic[nAIAL].values[nextState] += 3;
    postSynaptic[nAIBL].values[nextState] += 2;
    postSynaptic[nAIBR].values[nextState] += 8;
    postSynaptic[nAIZR].values[nextState] += 2;
    postSynaptic[nASEL].values[nextState] += 1;
    postSynaptic[nASGL].values[nextState] += 1;
    postSynaptic[nASHL].values[nextState] += 1;
    postSynaptic[nAVER].values[nextState] += 5;
    postSynaptic[nDVA].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 8;
    postSynaptic[nRIGL].values[nextState] += 1;
    postSynaptic[nRIML].values[nextState] += 4;
    postSynaptic[nSMBDL].values[nextState] += 9;
    postSynaptic[nSMBVL].values[nextState] += 7;
    postSynaptic[nVB2].values[nextState] += 1;
}

void AIZR() {
    postSynaptic[nAIAR].values[nextState] += 1;
    postSynaptic[nAIBL].values[nextState] += 8;
    postSynaptic[nAIBR].values[nextState] += 1;
    postSynaptic[nAIZL].values[nextState] += 2;
    postSynaptic[nASGR].values[nextState] += 1;
    postSynaptic[nASHR].values[nextState] += 1;
    postSynaptic[nAVEL].values[nextState] += 4;
    postSynaptic[nAVER].values[nextState] += 1;
    postSynaptic[nAWAR].values[nextState] += 1;
    postSynaptic[nDVA].values[nextState] += 1;
    postSynaptic[nRIAR].values[nextState] += 7;
    postSynaptic[nRIMR].values[nextState] += 4;
    postSynaptic[nSMBDR].values[nextState] += 5;
    postSynaptic[nSMBVR].values[nextState] += 3;
    postSynaptic[nSMDDR].values[nextState] += 1;
}

void ALA() {
    postSynaptic[nADEL].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVEL].values[nextState] += 2;
    postSynaptic[nAVER].values[nextState] += 1;
    postSynaptic[nRID].values[nextState] += 1;
    postSynaptic[nRMDR].values[nextState] += 1;
}

void ALML() {
    postSynaptic[nAVDR].values[nextState] += 1;
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nAVM].values[nextState] += 1;
    postSynaptic[nBDUL].values[nextState] += 6;
    postSynaptic[nCEPDL].values[nextState] += 3;
    postSynaptic[nCEPVL].values[nextState] += 2;
    postSynaptic[nPVCL].values[nextState] += 2;
    postSynaptic[nPVCR].values[nextState] += 1;
    postSynaptic[nPVR].values[nextState] += 1;
    postSynaptic[nRMDDR].values[nextState] += 1;
    postSynaptic[nRMGL].values[nextState] += 1;
    postSynaptic[nSDQL].values[nextState] += 1;
}

void ALMR() {
    postSynaptic[nAVM].values[nextState] += 1;
    postSynaptic[nBDUR].values[nextState] += 5;
    postSynaptic[nCEPDR].values[nextState] += 1;
    postSynaptic[nCEPVR].values[nextState] += 1;
    postSynaptic[nPVCR].values[nextState] += 3;
    postSynaptic[nRMDDL].values[nextState] += 1;
    postSynaptic[nSIADL].values[nextState] += 1;
}

void ALNL() {
    postSynaptic[nSAAVL].values[nextState] += 3;
    postSynaptic[nSMBDR].values[nextState] += 1;
    postSynaptic[nSMDVL].values[nextState] += 1;
}

void ALNR() {
    postSynaptic[nADER].values[nextState] += 1;
    postSynaptic[nRMHR].values[nextState] += 1;
    postSynaptic[nSAAVR].values[nextState] += 2;
    postSynaptic[nSMBDL].values[nextState] += 2;
    postSynaptic[nSMDDR].values[nextState] += 1;
    postSynaptic[nSMDVL].values[nextState] += 1;
}

void AQR() {
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 3;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 4;
    postSynaptic[nAVDL].values[nextState] += 1;
    postSynaptic[nAVDR].values[nextState] += 1;
    postSynaptic[nAVJL].values[nextState] += 1;
    postSynaptic[nAVKL].values[nextState] += 2;
    postSynaptic[nAVKR].values[nextState] += 1;
    postSynaptic[nBAGL].values[nextState] += 2;
    postSynaptic[nBAGR].values[nextState] += 2;
    postSynaptic[nPVCR].values[nextState] += 2;
    postSynaptic[nPVPL].values[nextState] += 7;
    postSynaptic[nPVPR].values[nextState] += 9;
    postSynaptic[nRIAL].values[nextState] += 3;
    postSynaptic[nRIAR].values[nextState] += 1;
    postSynaptic[nRIGL].values[nextState] += 2;
    postSynaptic[nRIGR].values[nextState] += 1;
    postSynaptic[nURXL].values[nextState] += 1;
}

void AS1() {
    postSynaptic[nAVAL].values[nextState] += 3;
    postSynaptic[nAVAR].values[nextState] += 2;
    postSynaptic[nDA1].values[nextState] += 2;
    postSynaptic[nMDL05].values[nextState] += 3;
    postSynaptic[nMDL08].values[nextState] += 3;
    postSynaptic[nMDR05].values[nextState] += 3;
    postSynaptic[nMDR08].values[nextState] += 4;
    postSynaptic[nVA3].values[nextState] += 1;
    postSynaptic[nVD1].values[nextState] += 5;
    postSynaptic[nVD2].values[nextState] += 1;
}

void AS2() {
    postSynaptic[nDA2].values[nextState] += 1;
    postSynaptic[nDB1].values[nextState] += 1;
    postSynaptic[nDD1].values[nextState] += 1;
    postSynaptic[nMDL07].values[nextState] += 3;
    postSynaptic[nMDL08].values[nextState] += 2;
    postSynaptic[nMDR07].values[nextState] += 3;
    postSynaptic[nMDR08].values[nextState] += 3;
    postSynaptic[nVA4].values[nextState] += 2;
    postSynaptic[nVD2].values[nextState] += 10;
}

void AS3() {
    postSynaptic[nAVAL].values[nextState] += 2;
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nDA2].values[nextState] += 1;
    postSynaptic[nDA3].values[nextState] += 1;
    postSynaptic[nDD1].values[nextState] += 1;
    postSynaptic[nMDL09].values[nextState] += 3;
    postSynaptic[nMDL10].values[nextState] += 3;
    postSynaptic[nMDR09].values[nextState] += 3;
    postSynaptic[nMDR10].values[nextState] += 3;
    postSynaptic[nVA5].values[nextState] += 2;
    postSynaptic[nVD2].values[nextState] += 1;
    postSynaptic[nVD3].values[nextState] += 15;
}

void AS4() {
    postSynaptic[nAS5].values[nextState] += 1;
    postSynaptic[nDA3].values[nextState] += 1;
    postSynaptic[nMDL11].values[nextState] += 2;
    postSynaptic[nMDL12].values[nextState] += 2;
    postSynaptic[nMDR11].values[nextState] += 3;
    postSynaptic[nMDR12].values[nextState] += 2;
    postSynaptic[nVD4].values[nextState] += 11;
}

void AS5() {
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nDD2].values[nextState] += 1;
    postSynaptic[nMDL11].values[nextState] += 2;
    postSynaptic[nMDL14].values[nextState] += 3;
    postSynaptic[nMDR11].values[nextState] += 2;
    postSynaptic[nMDR14].values[nextState] += 3;
    postSynaptic[nVA7].values[nextState] += 1;
    postSynaptic[nVD5].values[nextState] += 9;
}

void AS6() {
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nDA5].values[nextState] += 2;
    postSynaptic[nMDL13].values[nextState] += 3;
    postSynaptic[nMDL14].values[nextState] += 2;
    postSynaptic[nMDR13].values[nextState] += 3;
    postSynaptic[nMDR14].values[nextState] += 2;
    postSynaptic[nVA8].values[nextState] += 1;
    postSynaptic[nVD6].values[nextState] += 13;
}

void AS7() {
    postSynaptic[nAVAL].values[nextState] += 6;
    postSynaptic[nAVAR].values[nextState] += 5;
    postSynaptic[nAVBL].values[nextState] += 2;
    postSynaptic[nAVBR].values[nextState] += 2;
    postSynaptic[nMDL13].values[nextState] += 2;
    postSynaptic[nMDL16].values[nextState] += 3;
    postSynaptic[nMDR13].values[nextState] += 2;
    postSynaptic[nMDR16].values[nextState] += 3;
}

void AS8() {
    postSynaptic[nAVAL].values[nextState] += 4;
    postSynaptic[nAVAR].values[nextState] += 3;
    postSynaptic[nMDL15].values[nextState] += 2;
    postSynaptic[nMDL18].values[nextState] += 3;
    postSynaptic[nMDR15].values[nextState] += 2;
    postSynaptic[nMDR18].values[nextState] += 3;
}

void AS9() {
    postSynaptic[nAVAL].values[nextState] += 4;
    postSynaptic[nAVAR].values[nextState] += 2;
    postSynaptic[nDVB].values[nextState] += 7;
    postSynaptic[nMDL17].values[nextState] += 2;
    postSynaptic[nMDL20].values[nextState] += 3;
    postSynaptic[nMDR17].values[nextState] += 2;
    postSynaptic[nMDR20].values[nextState] += 3;
}

void AS10() {
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nMDL19].values[nextState] += 3;
    postSynaptic[nMDL20].values[nextState] += 2;
    postSynaptic[nMDR19].values[nextState] += 3;
    postSynaptic[nMDR20].values[nextState] += 2;
}

void AS11() {
    postSynaptic[nMDL21].values[nextState] += 1;
    postSynaptic[nMDL22].values[nextState] += 1;
    postSynaptic[nMDL23].values[nextState] += 1;
    postSynaptic[nMDL24].values[nextState] += 1;
    postSynaptic[nMDR21].values[nextState] += 1;
    postSynaptic[nMDR22].values[nextState] += 1;
    postSynaptic[nMDR23].values[nextState] += 1;
    postSynaptic[nMDR24].values[nextState] += 1;
    postSynaptic[nPDA].values[nextState] += 1;
    postSynaptic[nPDB].values[nextState] += 2;
    postSynaptic[nVD13].values[nextState] += 2;
}

void ASEL() {
    postSynaptic[nADFR].values[nextState] += 1;
    postSynaptic[nAIAL].values[nextState] += 3;
    postSynaptic[nAIBL].values[nextState] += 7;
    postSynaptic[nAIBR].values[nextState] += 2;
    postSynaptic[nAIYL].values[nextState] += 13;
    postSynaptic[nAIYR].values[nextState] += 6;
    postSynaptic[nAWCL].values[nextState] += 4;
    postSynaptic[nAWCR].values[nextState] += 1;
    postSynaptic[nRIAR].values[nextState] += 1;
}

void ASER() {
    postSynaptic[nAFDL].values[nextState] += 1;
    postSynaptic[nAFDR].values[nextState] += 2;
    postSynaptic[nAIAL].values[nextState] += 1;
    postSynaptic[nAIAR].values[nextState] += 3;
    postSynaptic[nAIBL].values[nextState] += 2;
    postSynaptic[nAIBR].values[nextState] += 10;
    postSynaptic[nAIYL].values[nextState] += 2;
    postSynaptic[nAIYR].values[nextState] += 14;
    postSynaptic[nAWAR].values[nextState] += 1;
    postSynaptic[nAWCL].values[nextState] += 1;
    postSynaptic[nAWCR].values[nextState] += 1;
}

void ASGL() {
    postSynaptic[nAIAL].values[nextState] += 9;
    postSynaptic[nAIBL].values[nextState] += 3;
    postSynaptic[nAINR].values[nextState] += 2;
    postSynaptic[nAIZL].values[nextState] += 1;
    postSynaptic[nASKL].values[nextState] += 1;
}

void ASGR() {
    postSynaptic[nAIAR].values[nextState] += 10;
    postSynaptic[nAIBR].values[nextState] += 2;
    postSynaptic[nAINL].values[nextState] += 1;
    postSynaptic[nAIYR].values[nextState] += 1;
    postSynaptic[nAIZR].values[nextState] += 1;
}

void ASHL() {
    postSynaptic[nADAL].values[nextState] += 2;
    postSynaptic[nADFL].values[nextState] += 3;
    postSynaptic[nAIAL].values[nextState] += 7;
    postSynaptic[nAIBL].values[nextState] += 5;
    postSynaptic[nAIZL].values[nextState] += 1;
    postSynaptic[nASHR].values[nextState] += 1;
    postSynaptic[nASKL].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 2;
    postSynaptic[nAVBL].values[nextState] += 6;
    postSynaptic[nAVDL].values[nextState] += 2;
    postSynaptic[nAVDR].values[nextState] += 2;
    postSynaptic[nRIAL].values[nextState] += 4;
    postSynaptic[nRICL].values[nextState] += 2;
    postSynaptic[nRIML].values[nextState] += 1;
    postSynaptic[nRIPL].values[nextState] += 1;
    postSynaptic[nRMGL].values[nextState] += 1;
}

void ASHR() {
    postSynaptic[nADAR].values[nextState] += 3;
    postSynaptic[nADFR].values[nextState] += 2;
    postSynaptic[nAIAR].values[nextState] += 10;
    postSynaptic[nAIBR].values[nextState] += 3;
    postSynaptic[nAIZR].values[nextState] += 1;
    postSynaptic[nASHL].values[nextState] += 1;
    postSynaptic[nASKR].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 5;
    postSynaptic[nAVBR].values[nextState] += 3;
    postSynaptic[nAVDL].values[nextState] += 5;
    postSynaptic[nAVDR].values[nextState] += 1;
    postSynaptic[nAVER].values[nextState] += 3;
    postSynaptic[nHSNR].values[nextState] += 1;
    postSynaptic[nPVPR].values[nextState] += 1;
    postSynaptic[nRIAR].values[nextState] += 2;
    postSynaptic[nRICR].values[nextState] += 2;
    postSynaptic[nRMGR].values[nextState] += 1;
}

void ASIL() {
    postSynaptic[nAIAL].values[nextState] += 2;
    postSynaptic[nAIBL].values[nextState] += 1;
    postSynaptic[nAIYL].values[nextState] += 2;
    postSynaptic[nAIZL].values[nextState] += 1;
    postSynaptic[nASER].values[nextState] += 1;
    postSynaptic[nASIR].values[nextState] += 1;
    postSynaptic[nASKL].values[nextState] += 2;
    postSynaptic[nAWCL].values[nextState] += 1;
    postSynaptic[nAWCR].values[nextState] += 1;
    postSynaptic[nRIBL].values[nextState] += 1;
}

void ASIR() {
    postSynaptic[nAIAL].values[nextState] += 1;
    postSynaptic[nAIAR].values[nextState] += 2;
    postSynaptic[nAIBR].values[nextState] += 1;
    postSynaptic[nASEL].values[nextState] += 2;
    postSynaptic[nASHR].values[nextState] += 1;
    postSynaptic[nASIL].values[nextState] += 1;
    postSynaptic[nAWCL].values[nextState] += 1;
    postSynaptic[nAWCR].values[nextState] += 1;
}

void ASJL() {
    postSynaptic[nASJR].values[nextState] += 1;
    postSynaptic[nASKL].values[nextState] += 4;
    postSynaptic[nHSNL].values[nextState] += 1;
    postSynaptic[nHSNR].values[nextState] += 1;
    postSynaptic[nPVQL].values[nextState] += 14;
}

void ASJR() {
    postSynaptic[nASJL].values[nextState] += 1;
    postSynaptic[nASKR].values[nextState] += 4;
    postSynaptic[nHSNR].values[nextState] += 1;
    postSynaptic[nPVQR].values[nextState] += 13;
}

void ASKL() {
    postSynaptic[nAIAL].values[nextState] += 11;
    postSynaptic[nAIBL].values[nextState] += 2;
    postSynaptic[nAIML].values[nextState] += 2;
    postSynaptic[nASKR].values[nextState] += 1;
    postSynaptic[nPVQL].values[nextState] += 5;
    postSynaptic[nRMGL].values[nextState] += 1;
}

void ASKR() {
    postSynaptic[nAIAR].values[nextState] += 11;
    postSynaptic[nAIMR].values[nextState] += 1;
    postSynaptic[nASHR].values[nextState] += 1;
    postSynaptic[nASKL].values[nextState] += 1;
    postSynaptic[nAWAR].values[nextState] += 1;
    postSynaptic[nCEPVR].values[nextState] += 1;
    postSynaptic[nPVQR].values[nextState] += 4;
    postSynaptic[nRIFR].values[nextState] += 1;
    postSynaptic[nRMGR].values[nextState] += 1;
}

void AUAL() {
    postSynaptic[nAINR].values[nextState] += 1;
    postSynaptic[nAUAR].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 3;
    postSynaptic[nAVDR].values[nextState] += 1;
    postSynaptic[nAVEL].values[nextState] += 3;
    postSynaptic[nAWBL].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 5;
    postSynaptic[nRIBL].values[nextState] += 9;
}

void AUAR() {
    postSynaptic[nAINL].values[nextState] += 1;
    postSynaptic[nAIYR].values[nextState] += 1;
    postSynaptic[nAUAL].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nAVER].values[nextState] += 4;
    postSynaptic[nAWBR].values[nextState] += 1;
    postSynaptic[nRIAR].values[nextState] += 6;
    postSynaptic[nRIBR].values[nextState] += 13;
    postSynaptic[nURXR].values[nextState] += 1;
}

void AVAL() {
    postSynaptic[nAS1].values[nextState] += 3;
    postSynaptic[nAS10].values[nextState] += 3;
    postSynaptic[nAS11].values[nextState] += 4;
    postSynaptic[nAS2].values[nextState] += 1;
    postSynaptic[nAS3].values[nextState] += 3;
    postSynaptic[nAS4].values[nextState] += 1;
    postSynaptic[nAS5].values[nextState] += 4;
    postSynaptic[nAS6].values[nextState] += 1;
    postSynaptic[nAS7].values[nextState] += 14;
    postSynaptic[nAS8].values[nextState] += 9;
    postSynaptic[nAS9].values[nextState] += 12;
    postSynaptic[nAVAR].values[nextState] += 7;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nAVDL].values[nextState] += 1;
    postSynaptic[nAVHL].values[nextState] += 1;
    postSynaptic[nAVJL].values[nextState] += 2;
    postSynaptic[nDA1].values[nextState] += 4;
    postSynaptic[nDA2].values[nextState] += 4;
    postSynaptic[nDA3].values[nextState] += 6;
    postSynaptic[nDA4].values[nextState] += 10;
    postSynaptic[nDA5].values[nextState] += 8;
    postSynaptic[nDA6].values[nextState] += 21;
    postSynaptic[nDA7].values[nextState] += 4;
    postSynaptic[nDA8].values[nextState] += 4;
    postSynaptic[nDA9].values[nextState] += 3;
    postSynaptic[nDB5].values[nextState] += 2;
    postSynaptic[nDB6].values[nextState] += 4;
    postSynaptic[nFLPL].values[nextState] += 1;
    postSynaptic[nLUAL].values[nextState] += 2;
    postSynaptic[nPVCL].values[nextState] += 12;
    postSynaptic[nPVCR].values[nextState] += 11;
    postSynaptic[nPVPL].values[nextState] += 1;
    postSynaptic[nRIMR].values[nextState] += 3;
    postSynaptic[nSABD].values[nextState] += 4;
    postSynaptic[nSABVR].values[nextState] += 1;
    postSynaptic[nSDQR].values[nextState] += 1;
    postSynaptic[nURYDL].values[nextState] += 1;
    postSynaptic[nURYVR].values[nextState] += 1;
    postSynaptic[nVA1].values[nextState] += 3;
    postSynaptic[nVA10].values[nextState] += 6;
    postSynaptic[nVA11].values[nextState] += 7;
    postSynaptic[nVA12].values[nextState] += 2;
    postSynaptic[nVA2].values[nextState] += 5;
    postSynaptic[nVA3].values[nextState] += 3;
    postSynaptic[nVA4].values[nextState] += 3;
    postSynaptic[nVA5].values[nextState] += 8;
    postSynaptic[nVA6].values[nextState] += 10;
    postSynaptic[nVA7].values[nextState] += 2;
    postSynaptic[nVA8].values[nextState] += 19;
    postSynaptic[nVA9].values[nextState] += 8;
    postSynaptic[nVB9].values[nextState] += 5;
}

void AVAR() {
    postSynaptic[nADER].values[nextState] += 1;
    postSynaptic[nAS1].values[nextState] += 3;
    postSynaptic[nAS10].values[nextState] += 2;
    postSynaptic[nAS11].values[nextState] += 6;
    postSynaptic[nAS2].values[nextState] += 2;
    postSynaptic[nAS3].values[nextState] += 2;
    postSynaptic[nAS4].values[nextState] += 1;
    postSynaptic[nAS5].values[nextState] += 2;
    postSynaptic[nAS6].values[nextState] += 3;
    postSynaptic[nAS7].values[nextState] += 8;
    postSynaptic[nAS8].values[nextState] += 9;
    postSynaptic[nAS9].values[nextState] += 6;
    postSynaptic[nAVAL].values[nextState] += 6;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVDL].values[nextState] += 1;
    postSynaptic[nAVDR].values[nextState] += 2;
    postSynaptic[nAVEL].values[nextState] += 2;
    postSynaptic[nAVER].values[nextState] += 2;
    postSynaptic[nDA1].values[nextState] += 8;
    postSynaptic[nDA2].values[nextState] += 4;
    postSynaptic[nDA3].values[nextState] += 5;
    postSynaptic[nDA4].values[nextState] += 8;
    postSynaptic[nDA5].values[nextState] += 7;
    postSynaptic[nDA6].values[nextState] += 13;
    postSynaptic[nDA7].values[nextState] += 3;
    postSynaptic[nDA8].values[nextState] += 9;
    postSynaptic[nDA9].values[nextState] += 2;
    postSynaptic[nDB3].values[nextState] += 1;
    postSynaptic[nDB5].values[nextState] += 3;
    postSynaptic[nDB6].values[nextState] += 5;
    postSynaptic[nLUAL].values[nextState] += 1;
    postSynaptic[nLUAR].values[nextState] += 3;
    postSynaptic[nPDEL].values[nextState] += 1;
    postSynaptic[nPDER].values[nextState] += 1;
    postSynaptic[nPVCL].values[nextState] += 7;
    postSynaptic[nPVCR].values[nextState] += 8;
    postSynaptic[nRIGL].values[nextState] += 1;
    postSynaptic[nRIML].values[nextState] += 2;
    postSynaptic[nRIMR].values[nextState] += 1;
    postSynaptic[nSABD].values[nextState] += 1;
    postSynaptic[nSABVL].values[nextState] += 6;
    postSynaptic[nSABVR].values[nextState] += 1;
    postSynaptic[nURYDR].values[nextState] += 1;
    postSynaptic[nURYVL].values[nextState] += 1;
    postSynaptic[nVA10].values[nextState] += 5;
    postSynaptic[nVA11].values[nextState] += 15;
    postSynaptic[nVA12].values[nextState] += 1;
    postSynaptic[nVA2].values[nextState] += 2;
    postSynaptic[nVA3].values[nextState] += 7;
    postSynaptic[nVA4].values[nextState] += 5;
    postSynaptic[nVA5].values[nextState] += 4;
    postSynaptic[nVA6].values[nextState] += 5;
    postSynaptic[nVA7].values[nextState] += 4;
    postSynaptic[nVA8].values[nextState] += 16;
    postSynaptic[nVB9].values[nextState] += 10;
    postSynaptic[nVD13].values[nextState] += 2;
}

void AVBL() {
    postSynaptic[nAQR].values[nextState] += 1;
    postSynaptic[nAS10].values[nextState] += 1;
    postSynaptic[nAS3].values[nextState] += 1;
    postSynaptic[nAS4].values[nextState] += 1;
    postSynaptic[nAS5].values[nextState] += 1;
    postSynaptic[nAS6].values[nextState] += 1;
    postSynaptic[nAS7].values[nextState] += 2;
    postSynaptic[nAS9].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 7;
    postSynaptic[nAVAR].values[nextState] += 7;
    postSynaptic[nAVBR].values[nextState] += 4;
    postSynaptic[nAVDL].values[nextState] += 1;
    postSynaptic[nAVDR].values[nextState] += 2;
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nAVER].values[nextState] += 2;
    postSynaptic[nAVL].values[nextState] += 1;
    postSynaptic[nDB3].values[nextState] += 1;
    postSynaptic[nDB4].values[nextState] += 1;
    postSynaptic[nDB5].values[nextState] += 1;
    postSynaptic[nDB6].values[nextState] += 2;
    postSynaptic[nDB7].values[nextState] += 2;
    postSynaptic[nDVA].values[nextState] += 1;
    postSynaptic[nPVNR].values[nextState] += 1;
    postSynaptic[nRIBL].values[nextState] += 1;
    postSynaptic[nRIBR].values[nextState] += 1;
    postSynaptic[nRID].values[nextState] += 1;
    postSynaptic[nSDQR].values[nextState] += 1;
    postSynaptic[nSIBVL].values[nextState] += 1;
    postSynaptic[nVA10].values[nextState] += 1;
    postSynaptic[nVA2].values[nextState] += 1;
    postSynaptic[nVA7].values[nextState] += 1;
    postSynaptic[nVB1].values[nextState] += 1;
    postSynaptic[nVB10].values[nextState] += 2;
    postSynaptic[nVB11].values[nextState] += 2;
    postSynaptic[nVB2].values[nextState] += 4;
    postSynaptic[nVB4].values[nextState] += 1;
    postSynaptic[nVB5].values[nextState] += 1;
    postSynaptic[nVB6].values[nextState] += 1;
    postSynaptic[nVB7].values[nextState] += 2;
    postSynaptic[nVB8].values[nextState] += 7;
    postSynaptic[nVB9].values[nextState] += 1;
    postSynaptic[nVC3].values[nextState] += 1;
}

void AVBR() {
    postSynaptic[nAS1].values[nextState] += 1;
    postSynaptic[nAS10].values[nextState] += 1;
    postSynaptic[nAS3].values[nextState] += 1;
    postSynaptic[nAS4].values[nextState] += 1;
    postSynaptic[nAS5].values[nextState] += 1;
    postSynaptic[nAS6].values[nextState] += 2;
    postSynaptic[nAS7].values[nextState] += 3;
    postSynaptic[nAVAL].values[nextState] += 6;
    postSynaptic[nAVAR].values[nextState] += 7;
    postSynaptic[nAVBL].values[nextState] += 4;
    postSynaptic[nDA5].values[nextState] += 1;
    postSynaptic[nDB1].values[nextState] += 3;
    postSynaptic[nDB2].values[nextState] += 1;
    postSynaptic[nDB3].values[nextState] += 1;
    postSynaptic[nDB4].values[nextState] += 1;
    postSynaptic[nDB5].values[nextState] += 1;
    postSynaptic[nDB6].values[nextState] += 1;
    postSynaptic[nDB7].values[nextState] += 1;
    postSynaptic[nDD1].values[nextState] += 1;
    postSynaptic[nDVA].values[nextState] += 1;
    postSynaptic[nHSNR].values[nextState] += 1;
    postSynaptic[nPVNL].values[nextState] += 2;
    postSynaptic[nRIBL].values[nextState] += 1;
    postSynaptic[nRIBR].values[nextState] += 1;
    postSynaptic[nRID].values[nextState] += 2;
    postSynaptic[nSIBVL].values[nextState] += 1;
    postSynaptic[nVA4].values[nextState] += 1;
    postSynaptic[nVA8].values[nextState] += 1;
    postSynaptic[nVA9].values[nextState] += 2;
    postSynaptic[nVB10].values[nextState] += 1;
    postSynaptic[nVB11].values[nextState] += 1;
    postSynaptic[nVB2].values[nextState] += 1;
    postSynaptic[nVB3].values[nextState] += 1;
    postSynaptic[nVB4].values[nextState] += 1;
    postSynaptic[nVB6].values[nextState] += 2;
    postSynaptic[nVB7].values[nextState] += 2;
    postSynaptic[nVB8].values[nextState] += 3;
    postSynaptic[nVB9].values[nextState] += 6;
    postSynaptic[nVD10].values[nextState] += 1;
    postSynaptic[nVD3].values[nextState] += 1;
}

void AVDL() {
    postSynaptic[nADAR].values[nextState] += 2;
    postSynaptic[nAS1].values[nextState] += 1;
    postSynaptic[nAS10].values[nextState] += 1;
    postSynaptic[nAS11].values[nextState] += 2;
    postSynaptic[nAS4].values[nextState] += 1;
    postSynaptic[nAS5].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 13;
    postSynaptic[nAVAR].values[nextState] += 19;
    postSynaptic[nAVM].values[nextState] += 2;
    postSynaptic[nDA1].values[nextState] += 1;
    postSynaptic[nDA2].values[nextState] += 1;
    postSynaptic[nDA3].values[nextState] += 4;
    postSynaptic[nDA4].values[nextState] += 1;
    postSynaptic[nDA5].values[nextState] += 1;
    postSynaptic[nDA8].values[nextState] += 1;
    postSynaptic[nFLPL].values[nextState] += 1;
    postSynaptic[nFLPR].values[nextState] += 1;
    postSynaptic[nLUAL].values[nextState] += 1;
    postSynaptic[nPVCL].values[nextState] += 1;
    postSynaptic[nSABD].values[nextState] += 1;
    postSynaptic[nSABVL].values[nextState] += 1;
    postSynaptic[nSABVR].values[nextState] += 1;
    postSynaptic[nVA5].values[nextState] += 1;
}

void AVDR() {
    postSynaptic[nADAL].values[nextState] += 2;
    postSynaptic[nADLL].values[nextState] += 1;
    postSynaptic[nAS10].values[nextState] += 1;
    postSynaptic[nAS5].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 16;
    postSynaptic[nAVAR].values[nextState] += 15;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVDL].values[nextState] += 2;
    postSynaptic[nAVJL].values[nextState] += 2;
    postSynaptic[nDA1].values[nextState] += 2;
    postSynaptic[nDA2].values[nextState] += 1;
    postSynaptic[nDA3].values[nextState] += 1;
    postSynaptic[nDA4].values[nextState] += 1;
    postSynaptic[nDA5].values[nextState] += 2;
    postSynaptic[nDA8].values[nextState] += 1;
    postSynaptic[nDA9].values[nextState] += 1;
    postSynaptic[nDB4].values[nextState] += 1;
    postSynaptic[nDVC].values[nextState] += 1;
    postSynaptic[nFLPR].values[nextState] += 1;
    postSynaptic[nLUAL].values[nextState] += 2;
    postSynaptic[nPQR].values[nextState] += 1;
    postSynaptic[nSABD].values[nextState] += 1;
    postSynaptic[nSABVL].values[nextState] += 3;
    postSynaptic[nSABVR].values[nextState] += 1;
    postSynaptic[nVA11].values[nextState] += 1;
    postSynaptic[nVA2].values[nextState] += 1;
    postSynaptic[nVA3].values[nextState] += 2;
    postSynaptic[nVA6].values[nextState] += 1;
}

void AVEL() {
    postSynaptic[nAS1].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 12;
    postSynaptic[nAVAR].values[nextState] += 7;
    postSynaptic[nAVER].values[nextState] += 1;
    postSynaptic[nDA1].values[nextState] += 5;
    postSynaptic[nDA2].values[nextState] += 1;
    postSynaptic[nDA3].values[nextState] += 3;
    postSynaptic[nDA4].values[nextState] += 1;
    postSynaptic[nPVCR].values[nextState] += 1;
    postSynaptic[nPVT].values[nextState] += 1;
    postSynaptic[nRIML].values[nextState] += 2;
    postSynaptic[nRIMR].values[nextState] += 3;
    postSynaptic[nRMDVR].values[nextState] += 1;
    postSynaptic[nRMEV].values[nextState] += 1;
    postSynaptic[nSABD].values[nextState] += 6;
    postSynaptic[nSABVL].values[nextState] += 7;
    postSynaptic[nSABVR].values[nextState] += 3;
    postSynaptic[nVA1].values[nextState] += 5;
    postSynaptic[nVA3].values[nextState] += 3;
    postSynaptic[nVD2].values[nextState] += 1;
    postSynaptic[nVD3].values[nextState] += 1;
}

void AVER() {
    postSynaptic[nAS1].values[nextState] += 3;
    postSynaptic[nAS2].values[nextState] += 2;
    postSynaptic[nAS3].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 7;
    postSynaptic[nAVAR].values[nextState] += 16;
    postSynaptic[nAVDR].values[nextState] += 1;
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nDA1].values[nextState] += 5;
    postSynaptic[nDA2].values[nextState] += 3;
    postSynaptic[nDA3].values[nextState] += 1;
    postSynaptic[nDB3].values[nextState] += 1;
    postSynaptic[nRIML].values[nextState] += 3;
    postSynaptic[nRIMR].values[nextState] += 2;
    postSynaptic[nRMDVL].values[nextState] += 1;
    postSynaptic[nRMDVR].values[nextState] += 1;
    postSynaptic[nRMEV].values[nextState] += 1;
    postSynaptic[nSABD].values[nextState] += 2;
    postSynaptic[nSABVL].values[nextState] += 3;
    postSynaptic[nSABVR].values[nextState] += 3;
    postSynaptic[nVA1].values[nextState] += 1;
    postSynaptic[nVA2].values[nextState] += 1;
    postSynaptic[nVA3].values[nextState] += 2;
    postSynaptic[nVA4].values[nextState] += 1;
    postSynaptic[nVA5].values[nextState] += 1;
}

void AVFL() {
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 2;
    postSynaptic[nAVFR].values[nextState] += 30;
    postSynaptic[nAVG].values[nextState] += 1;
    postSynaptic[nAVHL].values[nextState] += 4;
    postSynaptic[nAVHR].values[nextState] += 7;
    postSynaptic[nAVJL].values[nextState] += 1;
    postSynaptic[nAVJR].values[nextState] += 1;
    postSynaptic[nAVL].values[nextState] += 1;
    postSynaptic[nHSNL].values[nextState] += 1;
    postSynaptic[nMVL11].values[nextState] += 1;
    postSynaptic[nMVL12].values[nextState] += 1;
    postSynaptic[nPDER].values[nextState] += 1;
    postSynaptic[nPVNL].values[nextState] += 2;
    postSynaptic[nPVQL].values[nextState] += 1;
    postSynaptic[nPVQR].values[nextState] += 2;
    postSynaptic[nVB1].values[nextState] += 1;
}

void AVFR() {
    postSynaptic[nASJL].values[nextState] += 1;
    postSynaptic[nASKL].values[nextState] += 1;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 5;
    postSynaptic[nAVFL].values[nextState] += 24;
    postSynaptic[nAVHL].values[nextState] += 4;
    postSynaptic[nAVHR].values[nextState] += 2;
    postSynaptic[nAVJL].values[nextState] += 1;
    postSynaptic[nAVJR].values[nextState] += 1;
    postSynaptic[nHSNR].values[nextState] += 1;
    postSynaptic[nMVL14].values[nextState] += 2;
    postSynaptic[nMVR14].values[nextState] += 2;
    postSynaptic[nPVQL].values[nextState] += 1;
    postSynaptic[nVC4].values[nextState] += 1;
    postSynaptic[nVD11].values[nextState] += 1;
}

void AVG() {
    postSynaptic[nAVAR].values[nextState] += 3;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 2;
    postSynaptic[nAVDR].values[nextState] += 1;
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nAVER].values[nextState] += 1;
    postSynaptic[nAVFL].values[nextState] += 1;
    postSynaptic[nAVJL].values[nextState] += 1;
    postSynaptic[nAVL].values[nextState] += 1;
    postSynaptic[nDA8].values[nextState] += 1;
    postSynaptic[nPHAL].values[nextState] += 2;
    postSynaptic[nPVCL].values[nextState] += 1;
    postSynaptic[nPVNR].values[nextState] += 1;
    postSynaptic[nPVPR].values[nextState] += 1;
    postSynaptic[nPVQR].values[nextState] += 1;
    postSynaptic[nPVT].values[nextState] += 1;
    postSynaptic[nRIFL].values[nextState] += 1;
    postSynaptic[nRIFR].values[nextState] += 1;
    postSynaptic[nVA11].values[nextState] += 1;
}

void AVHL() {
    postSynaptic[nADFR].values[nextState] += 3;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nAVDL].values[nextState] += 1;
    postSynaptic[nAVFL].values[nextState] += 2;
    postSynaptic[nAVFR].values[nextState] += 5;
    postSynaptic[nAVHR].values[nextState] += 2;
    postSynaptic[nAVJL].values[nextState] += 1;
    postSynaptic[nAWBR].values[nextState] += 1;
    postSynaptic[nPHBR].values[nextState] += 1;
    postSynaptic[nPVPR].values[nextState] += 2;
    postSynaptic[nPVQL].values[nextState] += 1;
    postSynaptic[nPVQR].values[nextState] += 2;
    postSynaptic[nRIMR].values[nextState] += 1;
    postSynaptic[nRIR].values[nextState] += 3;
    postSynaptic[nSMBDR].values[nextState] += 1;
    postSynaptic[nSMBVR].values[nextState] += 1;
    postSynaptic[nVD1].values[nextState] += 1;
}

void AVHR() {
    postSynaptic[nADLL].values[nextState] += 1;
    postSynaptic[nADLR].values[nextState] += 2;
    postSynaptic[nAQR].values[nextState] += 2;
    postSynaptic[nAVBL].values[nextState] += 2;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nAVDR].values[nextState] += 1;
    postSynaptic[nAVFL].values[nextState] += 1;
    postSynaptic[nAVFR].values[nextState] += 2;
    postSynaptic[nAVHL].values[nextState] += 2;
    postSynaptic[nAVJR].values[nextState] += 4;
    postSynaptic[nPVNL].values[nextState] += 1;
    postSynaptic[nPVPL].values[nextState] += 3;
    postSynaptic[nRIGL].values[nextState] += 1;
    postSynaptic[nRIR].values[nextState] += 4;
    postSynaptic[nSMBDL].values[nextState] += 1;
    postSynaptic[nSMBVL].values[nextState] += 1;
}

void AVJL() {
    postSynaptic[nAVAL].values[nextState] += 2;
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 4;
    postSynaptic[nAVDL].values[nextState] += 1;
    postSynaptic[nAVDR].values[nextState] += 2;
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nAVFR].values[nextState] += 1;
    postSynaptic[nAVHL].values[nextState] += 2;
    postSynaptic[nAVJR].values[nextState] += 4;
    postSynaptic[nHSNR].values[nextState] += 1;
    postSynaptic[nPLMR].values[nextState] += 2;
    postSynaptic[nPVCL].values[nextState] += 2;
    postSynaptic[nPVCR].values[nextState] += 5;
    postSynaptic[nPVNR].values[nextState] += 1;
    postSynaptic[nRIFR].values[nextState] += 1;
    postSynaptic[nRIS].values[nextState] += 2;
}

void AVJR() {
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nAVBL].values[nextState] += 3;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nAVDL].values[nextState] += 1;
    postSynaptic[nAVDR].values[nextState] += 3;
    postSynaptic[nAVER].values[nextState] += 3;
    postSynaptic[nAVJL].values[nextState] += 5;
    postSynaptic[nPVCL].values[nextState] += 3;
    postSynaptic[nPVCR].values[nextState] += 4;
    postSynaptic[nPVQR].values[nextState] += 1;
    postSynaptic[nSABVL].values[nextState] += 1;
}

void AVKL() {
    postSynaptic[nADER].values[nextState] += 1;
    postSynaptic[nAQR].values[nextState] += 2;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVEL].values[nextState] += 2;
    postSynaptic[nAVER].values[nextState] += 1;
    postSynaptic[nAVKR].values[nextState] += 2;
    postSynaptic[nAVM].values[nextState] += 1;
    postSynaptic[nDVA].values[nextState] += 1;
    postSynaptic[nPDEL].values[nextState] += 3;
    postSynaptic[nPDER].values[nextState] += 1;
    postSynaptic[nPVM].values[nextState] += 1;
    postSynaptic[nPVPL].values[nextState] += 1;
    postSynaptic[nPVPR].values[nextState] += 1;
    postSynaptic[nPVT].values[nextState] += 2;
    postSynaptic[nRICL].values[nextState] += 1;
    postSynaptic[nRICR].values[nextState] += 1;
    postSynaptic[nRIGL].values[nextState] += 1;
    postSynaptic[nRIML].values[nextState] += 2;
    postSynaptic[nRIMR].values[nextState] += 1;
    postSynaptic[nRMFR].values[nextState] += 1;
    postSynaptic[nSAADR].values[nextState] += 1;
    postSynaptic[nSIAVR].values[nextState] += 1;
    postSynaptic[nSMBDL].values[nextState] += 1;
    postSynaptic[nSMBDR].values[nextState] += 1;
    postSynaptic[nSMBVR].values[nextState] += 1;
    postSynaptic[nSMDDR].values[nextState] += 1;
    postSynaptic[nVB1].values[nextState] += 4;
    postSynaptic[nVB10].values[nextState] += 1;
}

void AVKR() {
    postSynaptic[nADEL].values[nextState] += 1;
    postSynaptic[nAQR].values[nextState] += 1;
    postSynaptic[nAVKL].values[nextState] += 2;
    postSynaptic[nBDUL].values[nextState] += 1;
    postSynaptic[nMVL10].values[nextState] += 1;
    postSynaptic[nPVPL].values[nextState] += 6;
    postSynaptic[nPVQL].values[nextState] += 1;
    postSynaptic[nRICL].values[nextState] += 1;
    postSynaptic[nRIGR].values[nextState] += 1;
    postSynaptic[nRIML].values[nextState] += 2;
    postSynaptic[nRIMR].values[nextState] += 2;
    postSynaptic[nRMDR].values[nextState] += 1;
    postSynaptic[nRMFL].values[nextState] += 1;
    postSynaptic[nSAADL].values[nextState] += 1;
    postSynaptic[nSMBDL].values[nextState] += 2;
    postSynaptic[nSMBDR].values[nextState] += 2;
    postSynaptic[nSMBVR].values[nextState] += 1;
    postSynaptic[nSMDDL].values[nextState] += 1;
    postSynaptic[nSMDDR].values[nextState] += 2;
}

void AVL() {
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nAVFR].values[nextState] += 1;
    postSynaptic[nDA2].values[nextState] += 1;
    postSynaptic[nDD1].values[nextState] += 1;
    postSynaptic[nDD6].values[nextState] += 2;
    postSynaptic[nDVB].values[nextState] += 1;
    postSynaptic[nDVC].values[nextState] += 9;
    postSynaptic[nHSNR].values[nextState] += 1;
    postSynaptic[nMVL10].values[nextState] += -5;
    postSynaptic[nMVR10].values[nextState] += -5;
    postSynaptic[nPVM].values[nextState] += 1;
    postSynaptic[nPVPR].values[nextState] += 1;
    postSynaptic[nPVWL].values[nextState] += 1;
    postSynaptic[nSABD].values[nextState] += 5;
    postSynaptic[nSABVL].values[nextState] += 4;
    postSynaptic[nSABVR].values[nextState] += 3;
    postSynaptic[nVD12].values[nextState] += 4;
}

void AVM() {
    postSynaptic[nADER].values[nextState] += 1;
    postSynaptic[nALML].values[nextState] += 1;
    postSynaptic[nALMR].values[nextState] += 1;
    postSynaptic[nAVBL].values[nextState] += 6;
    postSynaptic[nAVBR].values[nextState] += 6;
    postSynaptic[nAVDL].values[nextState] += 2;
    postSynaptic[nAVJR].values[nextState] += 1;
    postSynaptic[nBDUL].values[nextState] += 3;
    postSynaptic[nBDUR].values[nextState] += 2;
    postSynaptic[nDA1].values[nextState] += 1;
    postSynaptic[nPVCL].values[nextState] += 4;
    postSynaptic[nPVCR].values[nextState] += 5;
    postSynaptic[nPVNL].values[nextState] += 1;
    postSynaptic[nPVR].values[nextState] += 3;
    postSynaptic[nRID].values[nextState] += 1;
    postSynaptic[nSIBVL].values[nextState] += 1;
    postSynaptic[nVA1].values[nextState] += 2;
}

void AWAL() {
    postSynaptic[nADAL].values[nextState] += 1;
    postSynaptic[nAFDL].values[nextState] += 5;
    postSynaptic[nAIAL].values[nextState] += 1;
    postSynaptic[nAIYL].values[nextState] += 1;
    postSynaptic[nAIZL].values[nextState] += 10;
    postSynaptic[nASEL].values[nextState] += 4;
    postSynaptic[nASGL].values[nextState] += 1;
    postSynaptic[nAWAR].values[nextState] += 1;
    postSynaptic[nAWBL].values[nextState] += 1;
}

void AWAR() {
    postSynaptic[nADFR].values[nextState] += 3;
    postSynaptic[nAFDR].values[nextState] += 7;
    postSynaptic[nAIAR].values[nextState] += 1;
    postSynaptic[nAIYR].values[nextState] += 2;
    postSynaptic[nAIZR].values[nextState] += 1;
    postSynaptic[nASEL].values[nextState] += 1;
    postSynaptic[nASER].values[nextState] += 2;
    postSynaptic[nAUAR].values[nextState] += 1;
    postSynaptic[nAWAL].values[nextState] += 1;
    postSynaptic[nAWBR].values[nextState] += 1;
    postSynaptic[nRIFR].values[nextState] += 2;
    postSynaptic[nRIGR].values[nextState] += 1;
    postSynaptic[nRIR].values[nextState] += 2;
}

void AWBL() {
    postSynaptic[nADFL].values[nextState] += 9;
    postSynaptic[nAIBR].values[nextState] += 1;
    postSynaptic[nAIZL].values[nextState] += 9;
    postSynaptic[nAUAL].values[nextState] += 1;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAWBR].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 3;
    postSynaptic[nRMGL].values[nextState] += 1;
    postSynaptic[nSMBDL].values[nextState] += 1;
}

void AWBR() {
    postSynaptic[nADFR].values[nextState] += 4;
    postSynaptic[nAIZR].values[nextState] += 4;
    postSynaptic[nASGR].values[nextState] += 1;
    postSynaptic[nASHR].values[nextState] += 2;
    postSynaptic[nAUAR].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 2;
    postSynaptic[nAWBL].values[nextState] += 1;
    postSynaptic[nRIAR].values[nextState] += 1;
    postSynaptic[nRICL].values[nextState] += 1;
    postSynaptic[nRIR].values[nextState] += 2;
    postSynaptic[nRMGR].values[nextState] += 1;
    postSynaptic[nSMBVR].values[nextState] += 1;
}

void AWCL() {
    postSynaptic[nAIAL].values[nextState] += 2;
    postSynaptic[nAIAR].values[nextState] += 4;
    postSynaptic[nAIBL].values[nextState] += 1;
    postSynaptic[nAIBR].values[nextState] += 1;
    postSynaptic[nAIYL].values[nextState] += 10;
    postSynaptic[nASEL].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAWCR].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 3;
}

void AWCR() {
    postSynaptic[nAIAR].values[nextState] += 1;
    postSynaptic[nAIBR].values[nextState] += 4;
    postSynaptic[nAIYL].values[nextState] += 4;
    postSynaptic[nAIYR].values[nextState] += 9;
    postSynaptic[nASEL].values[nextState] += 1;
    postSynaptic[nASGR].values[nextState] += 1;
    postSynaptic[nAWCL].values[nextState] += 5;
}

void BAGL() {
    postSynaptic[nAIBL].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nAVER].values[nextState] += 4;
    postSynaptic[nBAGR].values[nextState] += 2;
    postSynaptic[nRIAR].values[nextState] += 5;
    postSynaptic[nRIBL].values[nextState] += 1;
    postSynaptic[nRIBR].values[nextState] += 7;
    postSynaptic[nRIGL].values[nextState] += 1;
    postSynaptic[nRIGR].values[nextState] += 1;
    postSynaptic[nRIR].values[nextState] += 1;
}

void BAGR() {
    postSynaptic[nAIYL].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVEL].values[nextState] += 2;
    postSynaptic[nBAGL].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 5;
    postSynaptic[nRIBL].values[nextState] += 4;
    postSynaptic[nRIGL].values[nextState] += 1;
    postSynaptic[nRIR].values[nextState] += 1;
}

void BDUL() {
    postSynaptic[nADEL].values[nextState] += 3;
    postSynaptic[nAVHL].values[nextState] += 1;
    postSynaptic[nAVJR].values[nextState] += 1;
    postSynaptic[nHSNL].values[nextState] += 1;
    postSynaptic[nPVNL].values[nextState] += 2;
    postSynaptic[nPVNR].values[nextState] += 2;
    postSynaptic[nSAADL].values[nextState] += 1;
    postSynaptic[nURADL].values[nextState] += 1;
}

void BDUR() {
    postSynaptic[nADER].values[nextState] += 1;
    postSynaptic[nALMR].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 3;
    postSynaptic[nAVHL].values[nextState] += 1;
    postSynaptic[nAVJL].values[nextState] += 2;
    postSynaptic[nHSNR].values[nextState] += 4;
    postSynaptic[nPVCL].values[nextState] += 1;
    postSynaptic[nPVNL].values[nextState] += 2;
    postSynaptic[nPVNR].values[nextState] += 1;
    postSynaptic[nSDQL].values[nextState] += 1;
    postSynaptic[nURADR].values[nextState] += 1;
}

void CEPDL() {
    postSynaptic[nAVER].values[nextState] += 5;
    postSynaptic[nIL1DL].values[nextState] += 4;
    postSynaptic[nOLLL].values[nextState] += 2;
    postSynaptic[nOLQDL].values[nextState] += 1;
    postSynaptic[nRIBL].values[nextState] += 2;
    postSynaptic[nRICL].values[nextState] += 1;
    postSynaptic[nRICR].values[nextState] += 2;
    postSynaptic[nRIH].values[nextState] += 1;
    postSynaptic[nRIPL].values[nextState] += 2;
    postSynaptic[nRIS].values[nextState] += 1;
    postSynaptic[nRMDVL].values[nextState] += 3;
    postSynaptic[nRMGL].values[nextState] += 4;
    postSynaptic[nRMHR].values[nextState] += 4;
    postSynaptic[nSIADR].values[nextState] += 1;
    postSynaptic[nSMBDR].values[nextState] += 1;
    postSynaptic[nURADL].values[nextState] += 2;
    postSynaptic[nURBL].values[nextState] += 4;
    postSynaptic[nURYDL].values[nextState] += 2;
}

void CEPDR() {
    postSynaptic[nAVEL].values[nextState] += 6;
    postSynaptic[nBDUR].values[nextState] += 1;
    postSynaptic[nIL1DR].values[nextState] += 5;
    postSynaptic[nIL1R].values[nextState] += 1;
    postSynaptic[nOLLR].values[nextState] += 8;
    postSynaptic[nOLQDR].values[nextState] += 2;
    postSynaptic[nRIBR].values[nextState] += 1;
    postSynaptic[nRICL].values[nextState] += 4;
    postSynaptic[nRICR].values[nextState] += 3;
    postSynaptic[nRIH].values[nextState] += 1;
    postSynaptic[nRIS].values[nextState] += 1;
    postSynaptic[nRMDDL].values[nextState] += 1;
    postSynaptic[nRMDVR].values[nextState] += 2;
    postSynaptic[nRMGR].values[nextState] += 1;
    postSynaptic[nRMHL].values[nextState] += 4;
    postSynaptic[nRMHR].values[nextState] += 1;
    postSynaptic[nSIADL].values[nextState] += 1;
    postSynaptic[nSMBDR].values[nextState] += 1;
    postSynaptic[nURADR].values[nextState] += 1;
    postSynaptic[nURBR].values[nextState] += 2;
    postSynaptic[nURYDR].values[nextState] += 1;
}

void CEPVL() {
    postSynaptic[nADLL].values[nextState] += 1;
    postSynaptic[nAVER].values[nextState] += 3;
    postSynaptic[nIL1VL].values[nextState] += 2;
    postSynaptic[nMVL03].values[nextState] += 1;
    postSynaptic[nOLLL].values[nextState] += 4;
    postSynaptic[nOLQVL].values[nextState] += 1;
    postSynaptic[nRICL].values[nextState] += 7;
    postSynaptic[nRICR].values[nextState] += 4;
    postSynaptic[nRIH].values[nextState] += 1;
    postSynaptic[nRIPL].values[nextState] += 1;
    postSynaptic[nRMDDL].values[nextState] += 4;
    postSynaptic[nRMHL].values[nextState] += 1;
    postSynaptic[nSIAVL].values[nextState] += 1;
    postSynaptic[nURAVL].values[nextState] += 2;
}

void CEPVR() {
    postSynaptic[nASGR].values[nextState] += 1;
    postSynaptic[nAVEL].values[nextState] += 5;
    postSynaptic[nIL1VR].values[nextState] += 1;
    postSynaptic[nIL2VR].values[nextState] += 2;
    postSynaptic[nMVR04].values[nextState] += 1;
    postSynaptic[nOLLR].values[nextState] += 7;
    postSynaptic[nOLQVR].values[nextState] += 1;
    postSynaptic[nRICL].values[nextState] += 2;
    postSynaptic[nRICR].values[nextState] += 2;
    postSynaptic[nRIH].values[nextState] += 1;
    postSynaptic[nRIPR].values[nextState] += 1;
    postSynaptic[nRIVL].values[nextState] += 1;
    postSynaptic[nRMDDR].values[nextState] += 2;
    postSynaptic[nRMHR].values[nextState] += 2;
    postSynaptic[nSIAVR].values[nextState] += 2;
    postSynaptic[nURAVR].values[nextState] += 1;
}

void DA1() {
    postSynaptic[nAVAL].values[nextState] += 2;
    postSynaptic[nAVAR].values[nextState] += 6;
    postSynaptic[nDA4].values[nextState] += 1;
    postSynaptic[nDD1].values[nextState] += 4;
    postSynaptic[nMDL08].values[nextState] += 8;
    postSynaptic[nMDR08].values[nextState] += 8;
    postSynaptic[nSABVL].values[nextState] += 2;
    postSynaptic[nSABVR].values[nextState] += 3;
    postSynaptic[nVD1].values[nextState] += 17;
    postSynaptic[nVD2].values[nextState] += 1;
}

void DA2() {
    postSynaptic[nAS2].values[nextState] += 2;
    postSynaptic[nAS3].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 2;
    postSynaptic[nAVAR].values[nextState] += 2;
    postSynaptic[nDD1].values[nextState] += 1;
    postSynaptic[nMDL07].values[nextState] += 2;
    postSynaptic[nMDL08].values[nextState] += 1;
    postSynaptic[nMDL09].values[nextState] += 2;
    postSynaptic[nMDL10].values[nextState] += 2;
    postSynaptic[nMDR07].values[nextState] += 2;
    postSynaptic[nMDR08].values[nextState] += 2;
    postSynaptic[nMDR09].values[nextState] += 2;
    postSynaptic[nMDR10].values[nextState] += 2;
    postSynaptic[nSABVL].values[nextState] += 1;
    postSynaptic[nVA1].values[nextState] += 2;
    postSynaptic[nVD1].values[nextState] += 2;
    postSynaptic[nVD2].values[nextState] += 11;
    postSynaptic[nVD3].values[nextState] += 5;
}

void DA3() {
    postSynaptic[nAS4].values[nextState] += 2;
    postSynaptic[nAVAR].values[nextState] += 2;
    postSynaptic[nDA4].values[nextState] += 2;
    postSynaptic[nDB3].values[nextState] += 1;
    postSynaptic[nDD2].values[nextState] += 1;
    postSynaptic[nMDL09].values[nextState] += 5;
    postSynaptic[nMDL10].values[nextState] += 5;
    postSynaptic[nMDL12].values[nextState] += 5;
    postSynaptic[nMDR09].values[nextState] += 5;
    postSynaptic[nMDR10].values[nextState] += 5;
    postSynaptic[nMDR12].values[nextState] += 5;
    postSynaptic[nVD3].values[nextState] += 25;
    postSynaptic[nVD4].values[nextState] += 6;
}

void DA4() {
    postSynaptic[nAVAL].values[nextState] += 3;
    postSynaptic[nAVAR].values[nextState] += 2;
    postSynaptic[nDA1].values[nextState] += 1;
    postSynaptic[nDA3].values[nextState] += 1;
    postSynaptic[nDB3].values[nextState] += 2;
    postSynaptic[nDD2].values[nextState] += 1;
    postSynaptic[nMDL11].values[nextState] += 4;
    postSynaptic[nMDL12].values[nextState] += 4;
    postSynaptic[nMDL14].values[nextState] += 5;
    postSynaptic[nMDR11].values[nextState] += 4;
    postSynaptic[nMDR12].values[nextState] += 4;
    postSynaptic[nMDR14].values[nextState] += 5;
    postSynaptic[nVB6].values[nextState] += 1;
    postSynaptic[nVD4].values[nextState] += 12;
    postSynaptic[nVD5].values[nextState] += 15;
}

void DA5() {
    postSynaptic[nAS6].values[nextState] += 2;
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 5;
    postSynaptic[nDB4].values[nextState] += 1;
    postSynaptic[nMDL13].values[nextState] += 5;
    postSynaptic[nMDL14].values[nextState] += 4;
    postSynaptic[nMDR13].values[nextState] += 5;
    postSynaptic[nMDR14].values[nextState] += 4;
    postSynaptic[nVA4].values[nextState] += 1;
    postSynaptic[nVA5].values[nextState] += 2;
    postSynaptic[nVD5].values[nextState] += 1;
    postSynaptic[nVD6].values[nextState] += 16;
}

void DA6() {
    postSynaptic[nAVAL].values[nextState] += 10;
    postSynaptic[nAVAR].values[nextState] += 2;
    postSynaptic[nMDL11].values[nextState] += 6;
    postSynaptic[nMDL12].values[nextState] += 4;
    postSynaptic[nMDL13].values[nextState] += 4;
    postSynaptic[nMDL14].values[nextState] += 4;
    postSynaptic[nMDL16].values[nextState] += 4;
    postSynaptic[nMDR11].values[nextState] += 4;
    postSynaptic[nMDR12].values[nextState] += 4;
    postSynaptic[nMDR13].values[nextState] += 4;
    postSynaptic[nMDR14].values[nextState] += 4;
    postSynaptic[nMDR16].values[nextState] += 4;
    postSynaptic[nVD4].values[nextState] += 4;
    postSynaptic[nVD5].values[nextState] += 3;
    postSynaptic[nVD6].values[nextState] += 3;
}

void DA7() {
    postSynaptic[nAVAL].values[nextState] += 2;
    postSynaptic[nMDL15].values[nextState] += 4;
    postSynaptic[nMDL17].values[nextState] += 4;
    postSynaptic[nMDL18].values[nextState] += 4;
    postSynaptic[nMDR15].values[nextState] += 4;
    postSynaptic[nMDR17].values[nextState] += 4;
    postSynaptic[nMDR18].values[nextState] += 4;
}

void DA8() {
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nDA9].values[nextState] += 1;
    postSynaptic[nMDL17].values[nextState] += 4;
    postSynaptic[nMDL19].values[nextState] += 4;
    postSynaptic[nMDL20].values[nextState] += 4;
    postSynaptic[nMDR17].values[nextState] += 4;
    postSynaptic[nMDR19].values[nextState] += 4;
    postSynaptic[nMDR20].values[nextState] += 4;
}

void DA9() {
    postSynaptic[nDA8].values[nextState] += 1;
    postSynaptic[nDD6].values[nextState] += 1;
    postSynaptic[nMDL19].values[nextState] += 4;
    postSynaptic[nMDL21].values[nextState] += 4;
    postSynaptic[nMDL22].values[nextState] += 4;
    postSynaptic[nMDL23].values[nextState] += 4;
    postSynaptic[nMDL24].values[nextState] += 4;
    postSynaptic[nMDR19].values[nextState] += 4;
    postSynaptic[nMDR21].values[nextState] += 4;
    postSynaptic[nMDR22].values[nextState] += 4;
    postSynaptic[nMDR23].values[nextState] += 4;
    postSynaptic[nMDR24].values[nextState] += 4;
    postSynaptic[nPDA].values[nextState] += 1;
    postSynaptic[nPHCL].values[nextState] += 1;
    postSynaptic[nRID].values[nextState] += 1;
    postSynaptic[nVD13].values[nextState] += 1;
}

void DB1() {
    postSynaptic[nAIBR].values[nextState] += 1;
    postSynaptic[nAS1].values[nextState] += 1;
    postSynaptic[nAS2].values[nextState] += 1;
    postSynaptic[nAS3].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 3;
    postSynaptic[nDB2].values[nextState] += 1;
    postSynaptic[nDB4].values[nextState] += 1;
    postSynaptic[nDD1].values[nextState] += 10;
    postSynaptic[nDVA].values[nextState] += 1;
    postSynaptic[nMDL07].values[nextState] += 1;
    postSynaptic[nMDL08].values[nextState] += 1;
    postSynaptic[nMDR07].values[nextState] += 1;
    postSynaptic[nMDR08].values[nextState] += 1;
    postSynaptic[nRID].values[nextState] += 1;
    postSynaptic[nRIS].values[nextState] += 1;
    postSynaptic[nVB3].values[nextState] += 1;
    postSynaptic[nVB4].values[nextState] += 1;
    postSynaptic[nVD1].values[nextState] += 21;
    postSynaptic[nVD2].values[nextState] += 15;
    postSynaptic[nVD3].values[nextState] += 1;
}

void DB2() {
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nDA3].values[nextState] += 5;
    postSynaptic[nDB1].values[nextState] += 1;
    postSynaptic[nDB3].values[nextState] += 6;
    postSynaptic[nDD2].values[nextState] += 3;
    postSynaptic[nMDL09].values[nextState] += 3;
    postSynaptic[nMDL10].values[nextState] += 3;
    postSynaptic[nMDL11].values[nextState] += 3;
    postSynaptic[nMDL12].values[nextState] += 3;
    postSynaptic[nMDR09].values[nextState] += 3;
    postSynaptic[nMDR10].values[nextState] += 3;
    postSynaptic[nMDR11].values[nextState] += 3;
    postSynaptic[nMDR12].values[nextState] += 3;
    postSynaptic[nVB1].values[nextState] += 2;
    postSynaptic[nVD3].values[nextState] += 23;
    postSynaptic[nVD4].values[nextState] += 14;
    postSynaptic[nVD5].values[nextState] += 1;
}

void DB3() {
    postSynaptic[nAS4].values[nextState] += 1;
    postSynaptic[nAS5].values[nextState] += 1;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nDA4].values[nextState] += 1;
    postSynaptic[nDB2].values[nextState] += 6;
    postSynaptic[nDB4].values[nextState] += 1;
    postSynaptic[nDD2].values[nextState] += 4;
    postSynaptic[nDD3].values[nextState] += 10;
    postSynaptic[nMDL11].values[nextState] += 3;
    postSynaptic[nMDL12].values[nextState] += 3;
    postSynaptic[nMDL13].values[nextState] += 4;
    postSynaptic[nMDL14].values[nextState] += 3;
    postSynaptic[nMDR11].values[nextState] += 3;
    postSynaptic[nMDR12].values[nextState] += 3;
    postSynaptic[nMDR13].values[nextState] += 4;
    postSynaptic[nMDR14].values[nextState] += 3;
    postSynaptic[nVD4].values[nextState] += 9;
    postSynaptic[nVD5].values[nextState] += 26;
    postSynaptic[nVD6].values[nextState] += 7;
}

void DB4() {
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nDB1].values[nextState] += 1;
    postSynaptic[nDB3].values[nextState] += 1;
    postSynaptic[nDD3].values[nextState] += 3;
    postSynaptic[nMDL13].values[nextState] += 2;
    postSynaptic[nMDL14].values[nextState] += 2;
    postSynaptic[nMDL16].values[nextState] += 2;
    postSynaptic[nMDR13].values[nextState] += 2;
    postSynaptic[nMDR14].values[nextState] += 2;
    postSynaptic[nMDR16].values[nextState] += 2;
    postSynaptic[nVB2].values[nextState] += 1;
    postSynaptic[nVB4].values[nextState] += 1;
    postSynaptic[nVD6].values[nextState] += 13;
}

void DB5() {
    postSynaptic[nAVAR].values[nextState] += 2;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nMDL15].values[nextState] += 2;
    postSynaptic[nMDL17].values[nextState] += 2;
    postSynaptic[nMDL18].values[nextState] += 2;
    postSynaptic[nMDR15].values[nextState] += 2;
    postSynaptic[nMDR17].values[nextState] += 2;
    postSynaptic[nMDR18].values[nextState] += 2;
}

void DB6() {
    postSynaptic[nAVAL].values[nextState] += 3;
    postSynaptic[nAVBL].values[nextState] += 2;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nMDL17].values[nextState] += 2;
    postSynaptic[nMDL19].values[nextState] += 2;
    postSynaptic[nMDL20].values[nextState] += 2;
    postSynaptic[nMDR17].values[nextState] += 2;
    postSynaptic[nMDR19].values[nextState] += 2;
    postSynaptic[nMDR20].values[nextState] += 2;
}

void DB7() {
    postSynaptic[nAVBL].values[nextState] += 2;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nMDL19].values[nextState] += 2;
    postSynaptic[nMDL21].values[nextState] += 2;
    postSynaptic[nMDL22].values[nextState] += 2;
    postSynaptic[nMDL23].values[nextState] += 2;
    postSynaptic[nMDL24].values[nextState] += 2;
    postSynaptic[nMDR19].values[nextState] += 2;
    postSynaptic[nMDR21].values[nextState] += 2;
    postSynaptic[nMDR22].values[nextState] += 2;
    postSynaptic[nMDR23].values[nextState] += 2;
    postSynaptic[nMDR24].values[nextState] += 2;
    postSynaptic[nVD13].values[nextState] += 2;
}

void DD1() {
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nDD2].values[nextState] += 3;
    postSynaptic[nMDL07].values[nextState] += -6;
    postSynaptic[nMDL08].values[nextState] += -6;
    postSynaptic[nMDL09].values[nextState] += -7;
    postSynaptic[nMDL10].values[nextState] += -6;
    postSynaptic[nMDR07].values[nextState] += -6;
    postSynaptic[nMDR08].values[nextState] += -6;
    postSynaptic[nMDR09].values[nextState] += -7;
    postSynaptic[nMDR10].values[nextState] += -6;
    postSynaptic[nVD1].values[nextState] += 4;
    postSynaptic[nVD2].values[nextState] += 2;
}

void DD2() {
    postSynaptic[nDA3].values[nextState] += 1;
    postSynaptic[nDD1].values[nextState] += 1;
    postSynaptic[nDD3].values[nextState] += 2;
    postSynaptic[nMDL09].values[nextState] += -6;
    postSynaptic[nMDL11].values[nextState] += -7;
    postSynaptic[nMDL12].values[nextState] += -6;
    postSynaptic[nMDR09].values[nextState] += -6;
    postSynaptic[nMDR11].values[nextState] += -7;
    postSynaptic[nMDR12].values[nextState] += -6;
    postSynaptic[nVD3].values[nextState] += 1;
    postSynaptic[nVD4].values[nextState] += 3;
}

void DD3() {
    postSynaptic[nDD2].values[nextState] += 2;
    postSynaptic[nDD4].values[nextState] += 1;
    postSynaptic[nMDL11].values[nextState] += -7;
    postSynaptic[nMDL13].values[nextState] += -9;
    postSynaptic[nMDL14].values[nextState] += -7;
    postSynaptic[nMDR11].values[nextState] += -7;
    postSynaptic[nMDR13].values[nextState] += -9;
    postSynaptic[nMDR14].values[nextState] += -7;
}

void DD4() {
    postSynaptic[nDD3].values[nextState] += 1;
    postSynaptic[nMDL13].values[nextState] += -7;
    postSynaptic[nMDL15].values[nextState] += -7;
    postSynaptic[nMDL16].values[nextState] += -7;
    postSynaptic[nMDR13].values[nextState] += -7;
    postSynaptic[nMDR15].values[nextState] += -7;
    postSynaptic[nMDR16].values[nextState] += -7;
    postSynaptic[nVC3].values[nextState] += 1;
    postSynaptic[nVD8].values[nextState] += 1;
}

void DD5() {
    postSynaptic[nMDL17].values[nextState] += -7;
    postSynaptic[nMDL18].values[nextState] += -7;
    postSynaptic[nMDL20].values[nextState] += -7;
    postSynaptic[nMDR17].values[nextState] += -7;
    postSynaptic[nMDR18].values[nextState] += -7;
    postSynaptic[nMDR20].values[nextState] += -7;
    postSynaptic[nVB8].values[nextState] += 1;
    postSynaptic[nVD10].values[nextState] += 1;
    postSynaptic[nVD9].values[nextState] += 1;
}

void DD6() {
    postSynaptic[nMDL19].values[nextState] += -7;
    postSynaptic[nMDL21].values[nextState] += -7;
    postSynaptic[nMDL22].values[nextState] += -7;
    postSynaptic[nMDL23].values[nextState] += -7;
    postSynaptic[nMDL24].values[nextState] += -7;
    postSynaptic[nMDR19].values[nextState] += -7;
    postSynaptic[nMDR21].values[nextState] += -7;
    postSynaptic[nMDR22].values[nextState] += -7;
    postSynaptic[nMDR23].values[nextState] += -7;
    postSynaptic[nMDR24].values[nextState] += -7;
}

void DVA() {
    postSynaptic[nAIZL].values[nextState] += 3;
    postSynaptic[nAQR].values[nextState] += 4;
    postSynaptic[nAUAL].values[nextState] += 1;
    postSynaptic[nAUAR].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 3;
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nAVBL].values[nextState] += 2;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nAVEL].values[nextState] += 9;
    postSynaptic[nAVER].values[nextState] += 5;
    postSynaptic[nDB1].values[nextState] += 1;
    postSynaptic[nDB2].values[nextState] += 1;
    postSynaptic[nDB3].values[nextState] += 2;
    postSynaptic[nDB4].values[nextState] += 1;
    postSynaptic[nDB5].values[nextState] += 1;
    postSynaptic[nDB6].values[nextState] += 2;
    postSynaptic[nDB7].values[nextState] += 1;
    postSynaptic[nPDEL].values[nextState] += 3;
    postSynaptic[nPVCL].values[nextState] += 1;
    postSynaptic[nPVCR].values[nextState] += 1;
    postSynaptic[nPVR].values[nextState] += 2;
    postSynaptic[nRIAL].values[nextState] += 1;
    postSynaptic[nRIAR].values[nextState] += 1;
    postSynaptic[nRIMR].values[nextState] += 1;
    postSynaptic[nRIR].values[nextState] += 3;
    postSynaptic[nSAADR].values[nextState] += 1;
    postSynaptic[nSAAVL].values[nextState] += 1;
    postSynaptic[nSAAVR].values[nextState] += 1;
    postSynaptic[nSABD].values[nextState] += 1;
    postSynaptic[nSMBDL].values[nextState] += 3;
    postSynaptic[nSMBDR].values[nextState] += 2;
    postSynaptic[nSMBVL].values[nextState] += 3;
    postSynaptic[nSMBVR].values[nextState] += 2;
    postSynaptic[nVA12].values[nextState] += 1;
    postSynaptic[nVA2].values[nextState] += 1;
    postSynaptic[nVB1].values[nextState] += 1;
    postSynaptic[nVB11].values[nextState] += 2;
}

void DVB() {
    postSynaptic[nAS9].values[nextState] += 7;
    postSynaptic[nAVL].values[nextState] += 1;
    postSynaptic[nDA8].values[nextState] += 2;
    postSynaptic[nDD6].values[nextState] += 3;
    postSynaptic[nDVC].values[nextState] += 3;
    postSynaptic[nPDA].values[nextState] += 1;
    postSynaptic[nPHCL].values[nextState] += 1;
    postSynaptic[nPVPL].values[nextState] += 1;
    postSynaptic[nVA9].values[nextState] += 1;
    postSynaptic[nVB9].values[nextState] += 1;
}

void DVC() {
    postSynaptic[nAIBL].values[nextState] += 2;
    postSynaptic[nAIBR].values[nextState] += 5;
    postSynaptic[nAVAL].values[nextState] += 5;
    postSynaptic[nAVAR].values[nextState] += 7;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVKL].values[nextState] += 2;
    postSynaptic[nAVKR].values[nextState] += 1;
    postSynaptic[nAVL].values[nextState] += 9;
    postSynaptic[nPVPL].values[nextState] += 2;
    postSynaptic[nPVPR].values[nextState] += 13;
    postSynaptic[nPVT].values[nextState] += 1;
    postSynaptic[nRIBL].values[nextState] += 1;
    postSynaptic[nRIBR].values[nextState] += 1;
    postSynaptic[nRIGL].values[nextState] += 5;
    postSynaptic[nRIGR].values[nextState] += 5;
    postSynaptic[nRMFL].values[nextState] += 2;
    postSynaptic[nRMFR].values[nextState] += 4;
    postSynaptic[nVA9].values[nextState] += 1;
    postSynaptic[nVD1].values[nextState] += 5;
    postSynaptic[nVD10].values[nextState] += 4;
}

void FLPL() {
    postSynaptic[nADEL].values[nextState] += 2;
    postSynaptic[nADER].values[nextState] += 2;
    postSynaptic[nAIBL].values[nextState] += 1;
    postSynaptic[nAIBR].values[nextState] += 2;
    postSynaptic[nAVAL].values[nextState] += 15;
    postSynaptic[nAVAR].values[nextState] += 17;
    postSynaptic[nAVBL].values[nextState] += 4;
    postSynaptic[nAVBR].values[nextState] += 5;
    postSynaptic[nAVDL].values[nextState] += 7;
    postSynaptic[nAVDR].values[nextState] += 13;
    postSynaptic[nDVA].values[nextState] += 1;
    postSynaptic[nFLPR].values[nextState] += 3;
    postSynaptic[nRIH].values[nextState] += 1;
}

void FLPR() {
    postSynaptic[nADER].values[nextState] += 1;
    postSynaptic[nAIBR].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 12;
    postSynaptic[nAVAR].values[nextState] += 5;
    postSynaptic[nAVBL].values[nextState] += 5;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nAVDL].values[nextState] += 1;
    postSynaptic[nAVDR].values[nextState] += 2;
    postSynaptic[nAVEL].values[nextState] += 4;
    postSynaptic[nAVER].values[nextState] += 2;
    postSynaptic[nAVJR].values[nextState] += 1;
    postSynaptic[nDVA].values[nextState] += 1;
    postSynaptic[nFLPL].values[nextState] += 4;
    postSynaptic[nPVCL].values[nextState] += 2;
    postSynaptic[nVB1].values[nextState] += 1;
}

void HSNL() {
    postSynaptic[nAIAL].values[nextState] += 1;
    postSynaptic[nAIZL].values[nextState] += 2;
    postSynaptic[nAIZR].values[nextState] += 1;
    postSynaptic[nASHL].values[nextState] += 1;
    postSynaptic[nASHR].values[nextState] += 2;
    postSynaptic[nASJR].values[nextState] += 1;
    postSynaptic[nASKL].values[nextState] += 1;
    postSynaptic[nAVDR].values[nextState] += 2;
    postSynaptic[nAVFL].values[nextState] += 6;
    postSynaptic[nAVJL].values[nextState] += 1;
    postSynaptic[nAWBL].values[nextState] += 1;
    postSynaptic[nAWBR].values[nextState] += 2;
    postSynaptic[nHSNR].values[nextState] += 1;
    postSynaptic[nMVULVA].values[nextState] += 7;
    postSynaptic[nRIFL].values[nextState] += 3;
    postSynaptic[nRIML].values[nextState] += 2;
    postSynaptic[nSABVL].values[nextState] += 2;
    postSynaptic[nVC5].values[nextState] += 3;
}

void HSNR() {
    postSynaptic[nAIBL].values[nextState] += 1;
    postSynaptic[nAIBR].values[nextState] += 1;
    postSynaptic[nAIZL].values[nextState] += 1;
    postSynaptic[nAIZR].values[nextState] += 1;
    postSynaptic[nAS5].values[nextState] += 1;
    postSynaptic[nASHL].values[nextState] += 2;
    postSynaptic[nAVDR].values[nextState] += 1;
    postSynaptic[nAVFL].values[nextState] += 1;
    postSynaptic[nAVJL].values[nextState] += 1;
    postSynaptic[nAVL].values[nextState] += 1;
    postSynaptic[nAWBL].values[nextState] += 1;
    postSynaptic[nBDUR].values[nextState] += 1;
    postSynaptic[nDA5].values[nextState] += 1;
    postSynaptic[nDA6].values[nextState] += 1;
    postSynaptic[nHSNL].values[nextState] += 2;
    postSynaptic[nMVULVA].values[nextState] += 6;
    postSynaptic[nPVNR].values[nextState] += 2;
    postSynaptic[nPVQR].values[nextState] += 1;
    postSynaptic[nRIFR].values[nextState] += 4;
    postSynaptic[nRMGR].values[nextState] += 1;
    postSynaptic[nSABD].values[nextState] += 1;
    postSynaptic[nSABVR].values[nextState] += 1;
    postSynaptic[nVA6].values[nextState] += 1;
    postSynaptic[nVC2].values[nextState] += 3;
    postSynaptic[nVC3].values[nextState] += 1;
    postSynaptic[nVD4].values[nextState] += 2;
}

void I1L() {
    postSynaptic[nI1R].values[nextState] += 1;
    postSynaptic[nI3].values[nextState] += 1;
    postSynaptic[nI5].values[nextState] += 1;
    postSynaptic[nRIPL].values[nextState] += 1;
    postSynaptic[nRIPR].values[nextState] += 1;
}

void I1R() {
    postSynaptic[nI1L].values[nextState] += 1;
    postSynaptic[nI3].values[nextState] += 1;
    postSynaptic[nI5].values[nextState] += 1;
    postSynaptic[nRIPL].values[nextState] += 1;
    postSynaptic[nRIPR].values[nextState] += 1;
}

void I2L() {
    postSynaptic[nI1L].values[nextState] += 1;
    postSynaptic[nI1R].values[nextState] += 1;
    postSynaptic[nM1].values[nextState] += 4;
}

void I2R() {
    postSynaptic[nI1L].values[nextState] += 1;
    postSynaptic[nI1R].values[nextState] += 1;
    postSynaptic[nM1].values[nextState] += 4;
}

void I3() {
    postSynaptic[nM1].values[nextState] += 4;
    postSynaptic[nM2L].values[nextState] += 2;
    postSynaptic[nM2R].values[nextState] += 2;
}

void I4() {
    postSynaptic[nI2L].values[nextState] += 5;
    postSynaptic[nI2R].values[nextState] += 5;
    postSynaptic[nI5].values[nextState] += 2;
    postSynaptic[nM1].values[nextState] += 4;
}

void I5() {
    postSynaptic[nI1L].values[nextState] += 4;
    postSynaptic[nI1R].values[nextState] += 3;
    postSynaptic[nM1].values[nextState] += 2;
    postSynaptic[nM5].values[nextState] += 2;
    postSynaptic[nMI].values[nextState] += 4;
}

void I6() {
    postSynaptic[nI2L].values[nextState] += 2;
    postSynaptic[nI2R].values[nextState] += 2;
    postSynaptic[nI3].values[nextState] += 1;
    postSynaptic[nM4].values[nextState] += 1;
    postSynaptic[nM5].values[nextState] += 2;
    postSynaptic[nNSML].values[nextState] += 2;
    postSynaptic[nNSMR].values[nextState] += 2;
}

void IL1DL() {
    postSynaptic[nIL1DR].values[nextState] += 1;
    postSynaptic[nIL1L].values[nextState] += 1;
    postSynaptic[nMDL01].values[nextState] += 1;
    postSynaptic[nMDL02].values[nextState] += 1;
    postSynaptic[nMDL04].values[nextState] += 2;
    postSynaptic[nOLLL].values[nextState] += 1;
    postSynaptic[nPVR].values[nextState] += 1;
    postSynaptic[nRIH].values[nextState] += 1;
    postSynaptic[nRIPL].values[nextState] += 2;
    postSynaptic[nRMDDR].values[nextState] += 1;
    postSynaptic[nRMDVL].values[nextState] += 4;
    postSynaptic[nRMEV].values[nextState] += 1;
    postSynaptic[nURYDL].values[nextState] += 1;
}

void IL1DR() {
    postSynaptic[nIL1DL].values[nextState] += 1;
    postSynaptic[nIL1R].values[nextState] += 1;
    postSynaptic[nMDR01].values[nextState] += 4;
    postSynaptic[nMDR02].values[nextState] += 3;
    postSynaptic[nOLLR].values[nextState] += 1;
    postSynaptic[nRIPR].values[nextState] += 5;
    postSynaptic[nRMDVR].values[nextState] += 5;
    postSynaptic[nRMEV].values[nextState] += 1;
}

void IL1L() {
    postSynaptic[nAVER].values[nextState] += 2;
    postSynaptic[nIL1DL].values[nextState] += 2;
    postSynaptic[nIL1VL].values[nextState] += 1;
    postSynaptic[nMDL01].values[nextState] += 3;
    postSynaptic[nMDL03].values[nextState] += 3;
    postSynaptic[nMDL05].values[nextState] += 4;
    postSynaptic[nMVL01].values[nextState] += 3;
    postSynaptic[nMVL03].values[nextState] += 3;
    postSynaptic[nRMDDL].values[nextState] += 5;
    postSynaptic[nRMDL].values[nextState] += 1;
    postSynaptic[nRMDR].values[nextState] += 3;
    postSynaptic[nRMDVL].values[nextState] += 4;
    postSynaptic[nRMDVR].values[nextState] += 2;
    postSynaptic[nRMER].values[nextState] += 1;
}

void IL1R() {
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nAVER].values[nextState] += 1;
    postSynaptic[nIL1DR].values[nextState] += 2;
    postSynaptic[nIL1VR].values[nextState] += 1;
    postSynaptic[nMDR01].values[nextState] += 3;
    postSynaptic[nMDR03].values[nextState] += 3;
    postSynaptic[nMVR01].values[nextState] += 3;
    postSynaptic[nMVR03].values[nextState] += 3;
    postSynaptic[nRMDDL].values[nextState] += 3;
    postSynaptic[nRMDDR].values[nextState] += 2;
    postSynaptic[nRMDL].values[nextState] += 4;
    postSynaptic[nRMDR].values[nextState] += 2;
    postSynaptic[nRMDVL].values[nextState] += 1;
    postSynaptic[nRMDVR].values[nextState] += 4;
    postSynaptic[nRMEL].values[nextState] += 2;
    postSynaptic[nRMHL].values[nextState] += 1;
    postSynaptic[nURXR].values[nextState] += 2;
}

void IL1VL() {
    postSynaptic[nIL1L].values[nextState] += 2;
    postSynaptic[nIL1VR].values[nextState] += 1;
    postSynaptic[nMVL01].values[nextState] += 5;
    postSynaptic[nMVL02].values[nextState] += 4;
    postSynaptic[nRIPL].values[nextState] += 4;
    postSynaptic[nRMDDL].values[nextState] += 5;
    postSynaptic[nRMED].values[nextState] += 1;
    postSynaptic[nURYVL].values[nextState] += 1;
}

void IL1VR() {
    postSynaptic[nIL1R].values[nextState] += 2;
    postSynaptic[nIL1VL].values[nextState] += 1;
    postSynaptic[nIL2R].values[nextState] += 1;
    postSynaptic[nIL2VR].values[nextState] += 1;
    postSynaptic[nMVR01].values[nextState] += 5;
    postSynaptic[nMVR02].values[nextState] += 5;
    postSynaptic[nRIPR].values[nextState] += 6;
    postSynaptic[nRMDDR].values[nextState] += 10;
    postSynaptic[nRMER].values[nextState] += 1;
}

void IL2DL() {
    postSynaptic[nAUAL].values[nextState] += 1;
    postSynaptic[nIL1DL].values[nextState] += 7;
    postSynaptic[nOLQDL].values[nextState] += 2;
    postSynaptic[nRIBL].values[nextState] += 1;
    postSynaptic[nRIPL].values[nextState] += 10;
    postSynaptic[nRMEL].values[nextState] += 4;
    postSynaptic[nRMER].values[nextState] += 3;
    postSynaptic[nURADL].values[nextState] += 3;
}

void IL2DR() {
    postSynaptic[nCEPDR].values[nextState] += 1;
    postSynaptic[nIL1DR].values[nextState] += 7;
    postSynaptic[nRICR].values[nextState] += 1;
    postSynaptic[nRIPR].values[nextState] += 11;
    postSynaptic[nRMED].values[nextState] += 1;
    postSynaptic[nRMEL].values[nextState] += 2;
    postSynaptic[nRMER].values[nextState] += 2;
    postSynaptic[nRMEV].values[nextState] += 1;
    postSynaptic[nURADR].values[nextState] += 3;
}

void IL2L() {
    postSynaptic[nADEL].values[nextState] += 2;
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nIL1L].values[nextState] += 1;
    postSynaptic[nOLQDL].values[nextState] += 5;
    postSynaptic[nOLQVL].values[nextState] += 8;
    postSynaptic[nRICL].values[nextState] += 1;
    postSynaptic[nRIH].values[nextState] += 7;
    postSynaptic[nRMDL].values[nextState] += 3;
    postSynaptic[nRMDR].values[nextState] += 1;
    postSynaptic[nRMER].values[nextState] += 2;
    postSynaptic[nRMEV].values[nextState] += 2;
    postSynaptic[nRMGL].values[nextState] += 1;
    postSynaptic[nURXL].values[nextState] += 2;
}

void IL2R() {
    postSynaptic[nADER].values[nextState] += 1;
    postSynaptic[nIL1R].values[nextState] += 1;
    postSynaptic[nIL1VR].values[nextState] += 1;
    postSynaptic[nOLLR].values[nextState] += 1;
    postSynaptic[nOLQDR].values[nextState] += 2;
    postSynaptic[nOLQVR].values[nextState] += 7;
    postSynaptic[nRIH].values[nextState] += 6;
    postSynaptic[nRMDL].values[nextState] += 1;
    postSynaptic[nRMEL].values[nextState] += 2;
    postSynaptic[nRMEV].values[nextState] += 1;
    postSynaptic[nRMGR].values[nextState] += 1;
    postSynaptic[nURBR].values[nextState] += 1;
    postSynaptic[nURXR].values[nextState] += 1;
}

void IL2VL() {
    postSynaptic[nBAGR].values[nextState] += 1;
    postSynaptic[nIL1VL].values[nextState] += 7;
    postSynaptic[nIL2L].values[nextState] += 1;
    postSynaptic[nOLQVL].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 1;
    postSynaptic[nRIH].values[nextState] += 2;
    postSynaptic[nRIPL].values[nextState] += 1;
    postSynaptic[nRMEL].values[nextState] += 1;
    postSynaptic[nRMER].values[nextState] += 4;
    postSynaptic[nRMEV].values[nextState] += 1;
    postSynaptic[nURAVL].values[nextState] += 3;
}

void IL2VR() {
    postSynaptic[nIL1VR].values[nextState] += 6;
    postSynaptic[nOLQVR].values[nextState] += 1;
    postSynaptic[nRIAR].values[nextState] += 2;
    postSynaptic[nRIH].values[nextState] += 3;
    postSynaptic[nRIPR].values[nextState] += 15;
    postSynaptic[nRMEL].values[nextState] += 3;
    postSynaptic[nRMER].values[nextState] += 2;
    postSynaptic[nRMEV].values[nextState] += 3;
    postSynaptic[nURAVR].values[nextState] += 4;
    postSynaptic[nURXR].values[nextState] += 1;
}

void LUAL() {
    postSynaptic[nAVAL].values[nextState] += 6;
    postSynaptic[nAVAR].values[nextState] += 6;
    postSynaptic[nAVDL].values[nextState] += 4;
    postSynaptic[nAVDR].values[nextState] += 2;
    postSynaptic[nAVJL].values[nextState] += 1;
    postSynaptic[nPHBL].values[nextState] += 1;
    postSynaptic[nPLML].values[nextState] += 1;
    postSynaptic[nPVNL].values[nextState] += 1;
    postSynaptic[nPVR].values[nextState] += 1;
    postSynaptic[nPVWL].values[nextState] += 1;
}

void LUAR() {
    postSynaptic[nAVAL].values[nextState] += 3;
    postSynaptic[nAVAR].values[nextState] += 7;
    postSynaptic[nAVDL].values[nextState] += 1;
    postSynaptic[nAVDR].values[nextState] += 3;
    postSynaptic[nAVJR].values[nextState] += 1;
    postSynaptic[nPLMR].values[nextState] += 1;
    postSynaptic[nPQR].values[nextState] += 1;
    postSynaptic[nPVCR].values[nextState] += 3;
    postSynaptic[nPVR].values[nextState] += 2;
    postSynaptic[nPVWL].values[nextState] += 1;
}

void M1() {
    postSynaptic[nI2L].values[nextState] += 2;
    postSynaptic[nI2R].values[nextState] += 2;
    postSynaptic[nI3].values[nextState] += 1;
    postSynaptic[nI4].values[nextState] += 1;
}

void M2L() {
    postSynaptic[nI1L].values[nextState] += 3;
    postSynaptic[nI1R].values[nextState] += 3;
    postSynaptic[nI3].values[nextState] += 3;
    postSynaptic[nM2R].values[nextState] += 1;
    postSynaptic[nM5].values[nextState] += 1;
    postSynaptic[nMI].values[nextState] += 4;
}

void M2R() {
    postSynaptic[nI1L].values[nextState] += 3;
    postSynaptic[nI1R].values[nextState] += 3;
    postSynaptic[nI3].values[nextState] += 3;
    postSynaptic[nM3L].values[nextState] += 1;
    postSynaptic[nM3R].values[nextState] += 1;
    postSynaptic[nM5].values[nextState] += 1;
    postSynaptic[nMI].values[nextState] += 4;
}

void M3L() {
    postSynaptic[nI1L].values[nextState] += 4;
    postSynaptic[nI1R].values[nextState] += 4;
    postSynaptic[nI4].values[nextState] += 2;
    postSynaptic[nI5].values[nextState] += 3;
    postSynaptic[nI6].values[nextState] += 1;
    postSynaptic[nM1].values[nextState] += 2;
    postSynaptic[nM3R].values[nextState] += 1;
    postSynaptic[nMCL].values[nextState] += 1;
    postSynaptic[nMCR].values[nextState] += 1;
    postSynaptic[nMI].values[nextState] += 2;
    postSynaptic[nNSML].values[nextState] += 2;
    postSynaptic[nNSMR].values[nextState] += 3;
}

void M3R() {
    postSynaptic[nI1L].values[nextState] += 4;
    postSynaptic[nI1R].values[nextState] += 4;
    postSynaptic[nI3].values[nextState] += 2;
    postSynaptic[nI4].values[nextState] += 6;
    postSynaptic[nI5].values[nextState] += 3;
    postSynaptic[nI6].values[nextState] += 1;
    postSynaptic[nM1].values[nextState] += 2;
    postSynaptic[nM3L].values[nextState] += 1;
    postSynaptic[nMCL].values[nextState] += 1;
    postSynaptic[nMCR].values[nextState] += 1;
    postSynaptic[nMI].values[nextState] += 2;
    postSynaptic[nNSML].values[nextState] += 2;
    postSynaptic[nNSMR].values[nextState] += 3;
}

void M4() {
    postSynaptic[nI3].values[nextState] += 1;
    postSynaptic[nI5].values[nextState] += 13;
    postSynaptic[nI6].values[nextState] += 3;
    postSynaptic[nM2L].values[nextState] += 1;
    postSynaptic[nM2R].values[nextState] += 1;
    postSynaptic[nM4].values[nextState] += 6;
    postSynaptic[nM5].values[nextState] += 1;
    postSynaptic[nNSML].values[nextState] += 1;
    postSynaptic[nNSMR].values[nextState] += 1;
}

void M5() {
    postSynaptic[nI5].values[nextState] += 1;
    postSynaptic[nI6].values[nextState] += 1;
    postSynaptic[nM1].values[nextState] += 2;
    postSynaptic[nM2L].values[nextState] += 2;
    postSynaptic[nM2R].values[nextState] += 2;
    postSynaptic[nM5].values[nextState] += 4;
}

void MCL() {
    postSynaptic[nI1L].values[nextState] += 3;
    postSynaptic[nI1R].values[nextState] += 3;
    postSynaptic[nI2L].values[nextState] += 1;
    postSynaptic[nI2R].values[nextState] += 1;
    postSynaptic[nI3].values[nextState] += 1;
    postSynaptic[nM1].values[nextState] += 2;
    postSynaptic[nM2L].values[nextState] += 2;
    postSynaptic[nM2R].values[nextState] += 2;
}

void MCR() {
    postSynaptic[nI1L].values[nextState] += 3;
    postSynaptic[nI1R].values[nextState] += 3;
    postSynaptic[nI3].values[nextState] += 1;
    postSynaptic[nM1].values[nextState] += 2;
    postSynaptic[nM2L].values[nextState] += 2;
    postSynaptic[nM2R].values[nextState] += 2;
}

void MI() {
    postSynaptic[nI1L].values[nextState] += 1;
    postSynaptic[nI1R].values[nextState] += 1;
    postSynaptic[nI3].values[nextState] += 1;
    postSynaptic[nI4].values[nextState] += 1;
    postSynaptic[nI5].values[nextState] += 2;
    postSynaptic[nM1].values[nextState] += 1;
    postSynaptic[nM2L].values[nextState] += 2;
    postSynaptic[nM2R].values[nextState] += 2;
    postSynaptic[nM3L].values[nextState] += 1;
    postSynaptic[nM3R].values[nextState] += 1;
    postSynaptic[nMCL].values[nextState] += 2;
    postSynaptic[nMCR].values[nextState] += 2;
}

void NSML() {
    postSynaptic[nI1L].values[nextState] += 1;
    postSynaptic[nI1R].values[nextState] += 2;
    postSynaptic[nI2L].values[nextState] += 6;
    postSynaptic[nI2R].values[nextState] += 6;
    postSynaptic[nI3].values[nextState] += 2;
    postSynaptic[nI4].values[nextState] += 3;
    postSynaptic[nI5].values[nextState] += 2;
    postSynaptic[nI6].values[nextState] += 2;
    postSynaptic[nM3L].values[nextState] += 2;
    postSynaptic[nM3R].values[nextState] += 2;
}

void NSMR() {
    postSynaptic[nI1L].values[nextState] += 2;
    postSynaptic[nI1R].values[nextState] += 2;
    postSynaptic[nI2L].values[nextState] += 6;
    postSynaptic[nI2R].values[nextState] += 6;
    postSynaptic[nI3].values[nextState] += 2;
    postSynaptic[nI4].values[nextState] += 3;
    postSynaptic[nI5].values[nextState] += 2;
    postSynaptic[nI6].values[nextState] += 2;
    postSynaptic[nM3L].values[nextState] += 2;
    postSynaptic[nM3R].values[nextState] += 2;
}

void OLLL() {
    postSynaptic[nAVER].values[nextState] += 21;
    postSynaptic[nCEPDL].values[nextState] += 3;
    postSynaptic[nCEPVL].values[nextState] += 4;
    postSynaptic[nIL1DL].values[nextState] += 1;
    postSynaptic[nIL1VL].values[nextState] += 2;
    postSynaptic[nOLLR].values[nextState] += 2;
    postSynaptic[nRIBL].values[nextState] += 8;
    postSynaptic[nRIGL].values[nextState] += 1;
    postSynaptic[nRMDDL].values[nextState] += 7;
    postSynaptic[nRMDL].values[nextState] += 2;
    postSynaptic[nRMDVL].values[nextState] += 1;
    postSynaptic[nRMEL].values[nextState] += 2;
    postSynaptic[nSMDDL].values[nextState] += 3;
    postSynaptic[nSMDDR].values[nextState] += 4;
    postSynaptic[nSMDVR].values[nextState] += 4;
    postSynaptic[nURYDL].values[nextState] += 1;
}

void OLLR() {
    postSynaptic[nAVEL].values[nextState] += 16;
    postSynaptic[nCEPDR].values[nextState] += 1;
    postSynaptic[nCEPVR].values[nextState] += 6;
    postSynaptic[nIL1DR].values[nextState] += 3;
    postSynaptic[nIL1VR].values[nextState] += 1;
    postSynaptic[nIL2R].values[nextState] += 1;
    postSynaptic[nOLLL].values[nextState] += 2;
    postSynaptic[nRIBR].values[nextState] += 10;
    postSynaptic[nRIGR].values[nextState] += 1;
    postSynaptic[nRMDDR].values[nextState] += 10;
    postSynaptic[nRMDL].values[nextState] += 3;
    postSynaptic[nRMDVR].values[nextState] += 3;
    postSynaptic[nRMER].values[nextState] += 2;
    postSynaptic[nSMDDR].values[nextState] += 1;
    postSynaptic[nSMDVL].values[nextState] += 4;
    postSynaptic[nSMDVR].values[nextState] += 3;
}

void OLQDL() {
    postSynaptic[nCEPDL].values[nextState] += 1;
    postSynaptic[nRIBL].values[nextState] += 2;
    postSynaptic[nRICR].values[nextState] += 1;
    postSynaptic[nRIGL].values[nextState] += 1;
    postSynaptic[nRMDDR].values[nextState] += 4;
    postSynaptic[nRMDVL].values[nextState] += 1;
    postSynaptic[nSIBVL].values[nextState] += 3;
    postSynaptic[nURBL].values[nextState] += 1;
}

void OLQDR() {
    postSynaptic[nCEPDR].values[nextState] += 2;
    postSynaptic[nRIBR].values[nextState] += 2;
    postSynaptic[nRICL].values[nextState] += 1;
    postSynaptic[nRICR].values[nextState] += 1;
    postSynaptic[nRIGR].values[nextState] += 1;
    postSynaptic[nRIH].values[nextState] += 1;
    postSynaptic[nRMDDL].values[nextState] += 3;
    postSynaptic[nRMDVR].values[nextState] += 1;
    postSynaptic[nRMHR].values[nextState] += 1;
    postSynaptic[nSIBVR].values[nextState] += 2;
    postSynaptic[nURBR].values[nextState] += 1;
}

void OLQVL() {
    postSynaptic[nADLL].values[nextState] += 1;
    postSynaptic[nCEPVL].values[nextState] += 1;
    postSynaptic[nIL1VL].values[nextState] += 1;
    postSynaptic[nIL2VL].values[nextState] += 1;
    postSynaptic[nRIBL].values[nextState] += 1;
    postSynaptic[nRICL].values[nextState] += 1;
    postSynaptic[nRIGL].values[nextState] += 1;
    postSynaptic[nRIH].values[nextState] += 1;
    postSynaptic[nRIPL].values[nextState] += 1;
    postSynaptic[nRMDDL].values[nextState] += 1;
    postSynaptic[nRMDVR].values[nextState] += 4;
    postSynaptic[nSIBDL].values[nextState] += 3;
    postSynaptic[nURBL].values[nextState] += 1;
}

void OLQVR() {
    postSynaptic[nCEPVR].values[nextState] += 1;
    postSynaptic[nIL1VR].values[nextState] += 1;
    postSynaptic[nRIBR].values[nextState] += 1;
    postSynaptic[nRICR].values[nextState] += 1;
    postSynaptic[nRIGR].values[nextState] += 1;
    postSynaptic[nRIH].values[nextState] += 2;
    postSynaptic[nRIPR].values[nextState] += 2;
    postSynaptic[nRMDDR].values[nextState] += 1;
    postSynaptic[nRMDVL].values[nextState] += 4;
    postSynaptic[nRMER].values[nextState] += 1;
    postSynaptic[nSIBDR].values[nextState] += 4;
    postSynaptic[nURBR].values[nextState] += 1;
}

void PDA() {
    postSynaptic[nAS11].values[nextState] += 1;
    postSynaptic[nDA9].values[nextState] += 1;
    postSynaptic[nDD6].values[nextState] += 1;
    postSynaptic[nMDL21].values[nextState] += 2;
    postSynaptic[nPVNR].values[nextState] += 1;
    postSynaptic[nVD13].values[nextState] += 3;
}

void PDB() {
    postSynaptic[nAS11].values[nextState] += 2;
    postSynaptic[nMVL22].values[nextState] += 1;
    postSynaptic[nMVR21].values[nextState] += 1;
    postSynaptic[nRID].values[nextState] += 2;
    postSynaptic[nVD13].values[nextState] += 2;
}

void PDEL() {
    postSynaptic[nAVKL].values[nextState] += 6;
    postSynaptic[nDVA].values[nextState] += 24;
    postSynaptic[nPDER].values[nextState] += 3;
    postSynaptic[nPVCR].values[nextState] += 1;
    postSynaptic[nPVM].values[nextState] += 1;
    postSynaptic[nPVR].values[nextState] += 2;
    postSynaptic[nVA9].values[nextState] += 1;
    postSynaptic[nVD11].values[nextState] += 1;
}

void PDER() {
    postSynaptic[nAVKL].values[nextState] += 16;
    postSynaptic[nDVA].values[nextState] += 35;
    postSynaptic[nPDEL].values[nextState] += 3;
    postSynaptic[nPVCL].values[nextState] += 1;
    postSynaptic[nPVCR].values[nextState] += 1;
    postSynaptic[nPVM].values[nextState] += 1;
    postSynaptic[nVA8].values[nextState] += 1;
    postSynaptic[nVD9].values[nextState] += 1;
}

void PHAL() {
    postSynaptic[nAVDR].values[nextState] += 1;
    postSynaptic[nAVFL].values[nextState] += 3;
    postSynaptic[nAVG].values[nextState] += 5;
    postSynaptic[nAVHL].values[nextState] += 1;
    postSynaptic[nAVHR].values[nextState] += 1;
    postSynaptic[nDVA].values[nextState] += 2;
    postSynaptic[nPHAR].values[nextState] += 2;
    postSynaptic[nPHBL].values[nextState] += 5;
    postSynaptic[nPHBR].values[nextState] += 5;
    postSynaptic[nPVQL].values[nextState] += 2;
}

void PHAR() {
    postSynaptic[nAVG].values[nextState] += 3;
    postSynaptic[nAVHR].values[nextState] += 1;
    postSynaptic[nDA8].values[nextState] += 1;
    postSynaptic[nDVA].values[nextState] += 1;
    postSynaptic[nPHAL].values[nextState] += 2;
    postSynaptic[nPHBL].values[nextState] += 1;
    postSynaptic[nPHBR].values[nextState] += 5;
    postSynaptic[nPVPL].values[nextState] += 3;
    postSynaptic[nPVQL].values[nextState] += 2;
}

void PHBL() {
    postSynaptic[nAVAL].values[nextState] += 9;
    postSynaptic[nAVAR].values[nextState] += 6;
    postSynaptic[nAVDL].values[nextState] += 1;
    postSynaptic[nPHBR].values[nextState] += 3;
    postSynaptic[nPVCL].values[nextState] += 13;
    postSynaptic[nVA12].values[nextState] += 1;
}

void PHBR() {
    postSynaptic[nAVAL].values[nextState] += 7;
    postSynaptic[nAVAR].values[nextState] += 7;
    postSynaptic[nAVDL].values[nextState] += 1;
    postSynaptic[nAVDR].values[nextState] += 1;
    postSynaptic[nAVFL].values[nextState] += 1;
    postSynaptic[nAVHL].values[nextState] += 1;
    postSynaptic[nDA8].values[nextState] += 1;
    postSynaptic[nPHBL].values[nextState] += 3;
    postSynaptic[nPVCL].values[nextState] += 6;
    postSynaptic[nPVCR].values[nextState] += 3;
    postSynaptic[nVA12].values[nextState] += 2;
}

void PHCL() {
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nDA9].values[nextState] += 1;
    postSynaptic[nDVA].values[nextState] += 6;
    postSynaptic[nLUAL].values[nextState] += 1;
    postSynaptic[nPHCR].values[nextState] += 1;
    postSynaptic[nPLML].values[nextState] += 1;
    postSynaptic[nPVCL].values[nextState] += 2;
    postSynaptic[nVA12].values[nextState] += 3;
}

void PHCR() {
    postSynaptic[nAVHR].values[nextState] += 1;
    postSynaptic[nDA9].values[nextState] += 2;
    postSynaptic[nDVA].values[nextState] += 8;
    postSynaptic[nLUAR].values[nextState] += 1;
    postSynaptic[nPHCL].values[nextState] += 2;
    postSynaptic[nPVCR].values[nextState] += 9;
    postSynaptic[nVA12].values[nextState] += 2;
}

void PLML() {
    postSynaptic[nHSNL].values[nextState] += 1;
    postSynaptic[nLUAL].values[nextState] += 1;
    postSynaptic[nPHCL].values[nextState] += 1;
    postSynaptic[nPVCL].values[nextState] += 1;
}

void PLMR() {
    postSynaptic[nAS6].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 4;
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nAVDL].values[nextState] += 1;
    postSynaptic[nAVDR].values[nextState] += 4;
    postSynaptic[nDVA].values[nextState] += 5;
    postSynaptic[nHSNR].values[nextState] += 1;
    postSynaptic[nLUAR].values[nextState] += 1;
    postSynaptic[nPDEL].values[nextState] += 2;
    postSynaptic[nPDER].values[nextState] += 3;
    postSynaptic[nPVCL].values[nextState] += 2;
    postSynaptic[nPVCR].values[nextState] += 1;
    postSynaptic[nPVR].values[nextState] += 2;
}

void PLNL() {
    postSynaptic[nSAADL].values[nextState] += 5;
    postSynaptic[nSMBVL].values[nextState] += 6;
}

void PLNR() {
    postSynaptic[nSAADR].values[nextState] += 4;
    postSynaptic[nSMBVR].values[nextState] += 6;
}

void PQR() {
    postSynaptic[nAVAL].values[nextState] += 8;
    postSynaptic[nAVAR].values[nextState] += 11;
    postSynaptic[nAVDL].values[nextState] += 7;
    postSynaptic[nAVDR].values[nextState] += 6;
    postSynaptic[nAVG].values[nextState] += 1;
    postSynaptic[nLUAR].values[nextState] += 1;
    postSynaptic[nPVNL].values[nextState] += 1;
    postSynaptic[nPVPL].values[nextState] += 4;
}

void PVCL() {
    postSynaptic[nAS1].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 3;
    postSynaptic[nAVAR].values[nextState] += 4;
    postSynaptic[nAVBL].values[nextState] += 5;
    postSynaptic[nAVBR].values[nextState] += 12;
    postSynaptic[nAVDL].values[nextState] += 5;
    postSynaptic[nAVDR].values[nextState] += 2;
    postSynaptic[nAVEL].values[nextState] += 3;
    postSynaptic[nAVER].values[nextState] += 1;
    postSynaptic[nAVJL].values[nextState] += 4;
    postSynaptic[nAVJR].values[nextState] += 2;
    postSynaptic[nDA2].values[nextState] += 1;
    postSynaptic[nDA5].values[nextState] += 1;
    postSynaptic[nDA6].values[nextState] += 1;
    postSynaptic[nDB2].values[nextState] += 3;
    postSynaptic[nDB3].values[nextState] += 4;
    postSynaptic[nDB4].values[nextState] += 3;
    postSynaptic[nDB5].values[nextState] += 2;
    postSynaptic[nDB6].values[nextState] += 2;
    postSynaptic[nDB7].values[nextState] += 3;
    postSynaptic[nDVA].values[nextState] += 5;
    postSynaptic[nPLML].values[nextState] += 1;
    postSynaptic[nPVCR].values[nextState] += 7;
    postSynaptic[nRID].values[nextState] += 5;
    postSynaptic[nRIS].values[nextState] += 2;
    postSynaptic[nSIBVL].values[nextState] += 2;
    postSynaptic[nVB10].values[nextState] += 3;
    postSynaptic[nVB11].values[nextState] += 1;
    postSynaptic[nVB3].values[nextState] += 1;
    postSynaptic[nVB4].values[nextState] += 1;
    postSynaptic[nVB5].values[nextState] += 1;
    postSynaptic[nVB6].values[nextState] += 2;
    postSynaptic[nVB8].values[nextState] += 1;
    postSynaptic[nVB9].values[nextState] += 2;
}

void PVCR() {
    postSynaptic[nAQR].values[nextState] += 1;
    postSynaptic[nAS2].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 12;
    postSynaptic[nAVAR].values[nextState] += 10;
    postSynaptic[nAVBL].values[nextState] += 8;
    postSynaptic[nAVBR].values[nextState] += 6;
    postSynaptic[nAVDL].values[nextState] += 5;
    postSynaptic[nAVDR].values[nextState] += 1;
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nAVER].values[nextState] += 1;
    postSynaptic[nAVJL].values[nextState] += 3;
    postSynaptic[nAVL].values[nextState] += 1;
    postSynaptic[nDA9].values[nextState] += 1;
    postSynaptic[nDB2].values[nextState] += 1;
    postSynaptic[nDB3].values[nextState] += 3;
    postSynaptic[nDB4].values[nextState] += 4;
    postSynaptic[nDB5].values[nextState] += 1;
    postSynaptic[nDB6].values[nextState] += 2;
    postSynaptic[nDB7].values[nextState] += 1;
    postSynaptic[nFLPL].values[nextState] += 1;
    postSynaptic[nLUAR].values[nextState] += 1;
    postSynaptic[nPDEL].values[nextState] += 2;
    postSynaptic[nPHCR].values[nextState] += 1;
    postSynaptic[nPLMR].values[nextState] += 1;
    postSynaptic[nPVCL].values[nextState] += 8;
    postSynaptic[nPVDL].values[nextState] += 1;
    postSynaptic[nPVR].values[nextState] += 1;
    postSynaptic[nPVWL].values[nextState] += 2;
    postSynaptic[nPVWR].values[nextState] += 2;
    postSynaptic[nRID].values[nextState] += 5;
    postSynaptic[nSIBVR].values[nextState] += 2;
    postSynaptic[nVA8].values[nextState] += 2;
    postSynaptic[nVA9].values[nextState] += 1;
    postSynaptic[nVB10].values[nextState] += 1;
    postSynaptic[nVB4].values[nextState] += 3;
    postSynaptic[nVB6].values[nextState] += 2;
    postSynaptic[nVB7].values[nextState] += 3;
    postSynaptic[nVB8].values[nextState] += 1;
}

void PVDL() {
    postSynaptic[nAVAL].values[nextState] += 6;
    postSynaptic[nAVAR].values[nextState] += 6;
    postSynaptic[nDD5].values[nextState] += 1;
    postSynaptic[nPVCL].values[nextState] += 1;
    postSynaptic[nPVCR].values[nextState] += 6;
    postSynaptic[nVD10].values[nextState] += 6;
}

void PVDR() {
    postSynaptic[nAVAL].values[nextState] += 6;
    postSynaptic[nAVAR].values[nextState] += 9;
    postSynaptic[nDVA].values[nextState] += 3;
    postSynaptic[nPVCL].values[nextState] += 13;
    postSynaptic[nPVCR].values[nextState] += 10;
    postSynaptic[nPVDL].values[nextState] += 1;
    postSynaptic[nVA9].values[nextState] += 1;
}

void PVM() {
    postSynaptic[nAVKL].values[nextState] += 11;
    postSynaptic[nAVL].values[nextState] += 1;
    postSynaptic[nAVM].values[nextState] += 1;
    postSynaptic[nDVA].values[nextState] += 3;
    postSynaptic[nPDEL].values[nextState] += 1;
    postSynaptic[nPDER].values[nextState] += 1;
    postSynaptic[nPVCL].values[nextState] += 2;
    postSynaptic[nPVR].values[nextState] += 1;
}

void PVNL() {
    postSynaptic[nAVAL].values[nextState] += 2;
    postSynaptic[nAVBR].values[nextState] += 3;
    postSynaptic[nAVDL].values[nextState] += 3;
    postSynaptic[nAVDR].values[nextState] += 3;
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nAVFR].values[nextState] += 1;
    postSynaptic[nAVG].values[nextState] += 1;
    postSynaptic[nAVJL].values[nextState] += 5;
    postSynaptic[nAVJR].values[nextState] += 5;
    postSynaptic[nAVL].values[nextState] += 2;
    postSynaptic[nBDUL].values[nextState] += 1;
    postSynaptic[nBDUR].values[nextState] += 2;
    postSynaptic[nDD1].values[nextState] += 2;
    postSynaptic[nMVL09].values[nextState] += 3;
    postSynaptic[nPQR].values[nextState] += 1;
    postSynaptic[nPVCL].values[nextState] += 1;
    postSynaptic[nPVNR].values[nextState] += 5;
    postSynaptic[nPVQR].values[nextState] += 1;
    postSynaptic[nPVT].values[nextState] += 1;
    postSynaptic[nPVWL].values[nextState] += 1;
    postSynaptic[nRIFL].values[nextState] += 1;
}

void PVNR() {
    postSynaptic[nAVAL].values[nextState] += 2;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 2;
    postSynaptic[nAVDR].values[nextState] += 1;
    postSynaptic[nAVEL].values[nextState] += 3;
    postSynaptic[nAVJL].values[nextState] += 4;
    postSynaptic[nAVJR].values[nextState] += 1;
    postSynaptic[nAVL].values[nextState] += 2;
    postSynaptic[nBDUL].values[nextState] += 1;
    postSynaptic[nBDUR].values[nextState] += 2;
    postSynaptic[nDD3].values[nextState] += 1;
    postSynaptic[nHSNR].values[nextState] += 2;
    postSynaptic[nMVL12].values[nextState] += 1;
    postSynaptic[nMVL13].values[nextState] += 2;
    postSynaptic[nPQR].values[nextState] += 2;
    postSynaptic[nPVCL].values[nextState] += 1;
    postSynaptic[nPVNL].values[nextState] += 1;
    postSynaptic[nPVT].values[nextState] += 2;
    postSynaptic[nPVWL].values[nextState] += 2;
    postSynaptic[nVC2].values[nextState] += 1;
    postSynaptic[nVC3].values[nextState] += 1;
    postSynaptic[nVD12].values[nextState] += 1;
    postSynaptic[nVD6].values[nextState] += 1;
    postSynaptic[nVD7].values[nextState] += 1;
}

void PVPL() {
    postSynaptic[nADAL].values[nextState] += 1;
    postSynaptic[nAQR].values[nextState] += 8;
    postSynaptic[nAVAL].values[nextState] += 2;
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nAVBL].values[nextState] += 5;
    postSynaptic[nAVBR].values[nextState] += 6;
    postSynaptic[nAVDR].values[nextState] += 2;
    postSynaptic[nAVER].values[nextState] += 1;
    postSynaptic[nAVHR].values[nextState] += 1;
    postSynaptic[nAVKL].values[nextState] += 1;
    postSynaptic[nAVKR].values[nextState] += 6;
    postSynaptic[nDVC].values[nextState] += 2;
    postSynaptic[nPHAR].values[nextState] += 3;
    postSynaptic[nPQR].values[nextState] += 4;
    postSynaptic[nPVCR].values[nextState] += 3;
    postSynaptic[nPVPR].values[nextState] += 1;
    postSynaptic[nPVT].values[nextState] += 1;
    postSynaptic[nRIGL].values[nextState] += 2;
    postSynaptic[nVD13].values[nextState] += 2;
    postSynaptic[nVD3].values[nextState] += 1;
}

void PVPR() {
    postSynaptic[nADFR].values[nextState] += 1;
    postSynaptic[nAQR].values[nextState] += 11;
    postSynaptic[nASHR].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 2;
    postSynaptic[nAVBL].values[nextState] += 4;
    postSynaptic[nAVBR].values[nextState] += 5;
    postSynaptic[nAVHL].values[nextState] += 3;
    postSynaptic[nAVKL].values[nextState] += 1;
    postSynaptic[nAVL].values[nextState] += 4;
    postSynaptic[nDD2].values[nextState] += 1;
    postSynaptic[nDVC].values[nextState] += 14;
    postSynaptic[nPVCL].values[nextState] += 4;
    postSynaptic[nPVCR].values[nextState] += 7;
    postSynaptic[nPVPL].values[nextState] += 1;
    postSynaptic[nPVQR].values[nextState] += 1;
    postSynaptic[nRIAR].values[nextState] += 2;
    postSynaptic[nRIGR].values[nextState] += 1;
    postSynaptic[nRIMR].values[nextState] += 1;
    postSynaptic[nRMGR].values[nextState] += 1;
    postSynaptic[nVD4].values[nextState] += 1;
    postSynaptic[nVD5].values[nextState] += 1;
}

void PVQL() {
    postSynaptic[nADAL].values[nextState] += 1;
    postSynaptic[nAIAL].values[nextState] += 3;
    postSynaptic[nASJL].values[nextState] += 1;
    postSynaptic[nASKL].values[nextState] += 5;
    postSynaptic[nHSNL].values[nextState] += 2;
    postSynaptic[nPVQR].values[nextState] += 2;
    postSynaptic[nRMGL].values[nextState] += 1;
}

void PVQR() {
    postSynaptic[nADAR].values[nextState] += 1;
    postSynaptic[nAIAR].values[nextState] += 7;
    postSynaptic[nASER].values[nextState] += 1;
    postSynaptic[nASKR].values[nextState] += 8;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVFL].values[nextState] += 1;
    postSynaptic[nAVFR].values[nextState] += 1;
    postSynaptic[nAVL].values[nextState] += 1;
    postSynaptic[nAWAR].values[nextState] += 2;
    postSynaptic[nDD1].values[nextState] += 1;
    postSynaptic[nDVC].values[nextState] += 1;
    postSynaptic[nHSNR].values[nextState] += 1;
    postSynaptic[nPVNL].values[nextState] += 1;
    postSynaptic[nPVQL].values[nextState] += 1;
    postSynaptic[nPVT].values[nextState] += 1;
    postSynaptic[nRIFR].values[nextState] += 1;
    postSynaptic[nVD1].values[nextState] += 1;
}

void PVR() {
    postSynaptic[nADAL].values[nextState] += 1;
    postSynaptic[nALML].values[nextState] += 1;
    postSynaptic[nAS6].values[nextState] += 1;
    postSynaptic[nAVBL].values[nextState] += 4;
    postSynaptic[nAVBR].values[nextState] += 4;
    postSynaptic[nAVJL].values[nextState] += 3;
    postSynaptic[nAVJR].values[nextState] += 2;
    postSynaptic[nAVKL].values[nextState] += 1;
    postSynaptic[nDA9].values[nextState] += 1;
    postSynaptic[nDB2].values[nextState] += 1;
    postSynaptic[nDB3].values[nextState] += 1;
    postSynaptic[nDVA].values[nextState] += 3;
    postSynaptic[nIL1DL].values[nextState] += 1;
    postSynaptic[nIL1DR].values[nextState] += 1;
    postSynaptic[nIL1VL].values[nextState] += 1;
    postSynaptic[nIL1VR].values[nextState] += 1;
    postSynaptic[nLUAL].values[nextState] += 1;
    postSynaptic[nLUAR].values[nextState] += 1;
    postSynaptic[nPDEL].values[nextState] += 1;
    postSynaptic[nPDER].values[nextState] += 1;
    postSynaptic[nPLMR].values[nextState] += 2;
    postSynaptic[nPVCR].values[nextState] += 1;
    postSynaptic[nRIPL].values[nextState] += 3;
    postSynaptic[nRIPR].values[nextState] += 3;
    postSynaptic[nSABD].values[nextState] += 1;
    postSynaptic[nURADL].values[nextState] += 1;
}

void PVT() {
    postSynaptic[nAIBL].values[nextState] += 3;
    postSynaptic[nAIBR].values[nextState] += 5;
    postSynaptic[nAVKL].values[nextState] += 9;
    postSynaptic[nAVKR].values[nextState] += 7;
    postSynaptic[nAVL].values[nextState] += 2;
    postSynaptic[nDVC].values[nextState] += 2;
    postSynaptic[nPVPL].values[nextState] += 1;
    postSynaptic[nRIBL].values[nextState] += 1;
    postSynaptic[nRIBR].values[nextState] += 1;
    postSynaptic[nRIGL].values[nextState] += 2;
    postSynaptic[nRIGR].values[nextState] += 3;
    postSynaptic[nRIH].values[nextState] += 1;
    postSynaptic[nRMEV].values[nextState] += 1;
    postSynaptic[nRMFL].values[nextState] += 2;
    postSynaptic[nRMFR].values[nextState] += 3;
    postSynaptic[nSMBDR].values[nextState] += 1;
}

void PVWL() {
    postSynaptic[nAVJL].values[nextState] += 1;
    postSynaptic[nPVCR].values[nextState] += 2;
    postSynaptic[nPVT].values[nextState] += 2;
    postSynaptic[nPVWR].values[nextState] += 1;
    postSynaptic[nVA12].values[nextState] += 1;
}

void PVWR() {
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nAVDR].values[nextState] += 1;
    postSynaptic[nPVCR].values[nextState] += 2;
    postSynaptic[nPVT].values[nextState] += 1;
    postSynaptic[nVA12].values[nextState] += 1;
}

void RIAL() {
    postSynaptic[nCEPVL].values[nextState] += 1;
    postSynaptic[nRIAR].values[nextState] += 1;
    postSynaptic[nRIVL].values[nextState] += 2;
    postSynaptic[nRIVR].values[nextState] += 4;
    postSynaptic[nRMDDL].values[nextState] += 12;
    postSynaptic[nRMDDR].values[nextState] += 7;
    postSynaptic[nRMDL].values[nextState] += 6;
    postSynaptic[nRMDR].values[nextState] += 6;
    postSynaptic[nRMDVL].values[nextState] += 9;
    postSynaptic[nRMDVR].values[nextState] += 11;
    postSynaptic[nSIADL].values[nextState] += 2;
    postSynaptic[nSMDDL].values[nextState] += 8;
    postSynaptic[nSMDDR].values[nextState] += 10;
    postSynaptic[nSMDVL].values[nextState] += 6;
    postSynaptic[nSMDVR].values[nextState] += 11;
}

void RIAR() {
    postSynaptic[nCEPVR].values[nextState] += 1;
    postSynaptic[nIL1R].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 4;
    postSynaptic[nRIVL].values[nextState] += 1;
    postSynaptic[nRMDDL].values[nextState] += 10;
    postSynaptic[nRMDDR].values[nextState] += 11;
    postSynaptic[nRMDL].values[nextState] += 3;
    postSynaptic[nRMDR].values[nextState] += 8;
    postSynaptic[nRMDVL].values[nextState] += 12;
    postSynaptic[nRMDVR].values[nextState] += 10;
    postSynaptic[nSAADR].values[nextState] += 1;
    postSynaptic[nSIADL].values[nextState] += 1;
    postSynaptic[nSIADR].values[nextState] += 1;
    postSynaptic[nSIAVL].values[nextState] += 1;
    postSynaptic[nSMDDL].values[nextState] += 7;
    postSynaptic[nSMDDR].values[nextState] += 7;
    postSynaptic[nSMDVL].values[nextState] += 13;
    postSynaptic[nSMDVR].values[nextState] += 7;
}

void RIBL() {
    postSynaptic[nAIBR].values[nextState] += 2;
    postSynaptic[nAUAL].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 2;
    postSynaptic[nAVDR].values[nextState] += 1;
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nAVER].values[nextState] += 5;
    postSynaptic[nBAGR].values[nextState] += 1;
    postSynaptic[nOLQDL].values[nextState] += 2;
    postSynaptic[nOLQVL].values[nextState] += 1;
    postSynaptic[nPVT].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 3;
    postSynaptic[nRIBL].values[nextState] += 1;
    postSynaptic[nRIBR].values[nextState] += 3;
    postSynaptic[nRIGL].values[nextState] += 1;
    postSynaptic[nSIADL].values[nextState] += 1;
    postSynaptic[nSIAVL].values[nextState] += 1;
    postSynaptic[nSIBDL].values[nextState] += 1;
    postSynaptic[nSIBVL].values[nextState] += 1;
    postSynaptic[nSIBVR].values[nextState] += 1;
    postSynaptic[nSMBDL].values[nextState] += 1;
    postSynaptic[nSMDDL].values[nextState] += 1;
    postSynaptic[nSMDVR].values[nextState] += 4;
}

void RIBR() {
    postSynaptic[nAIBL].values[nextState] += 1;
    postSynaptic[nAIZR].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 2;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nAVEL].values[nextState] += 3;
    postSynaptic[nAVER].values[nextState] += 1;
    postSynaptic[nBAGL].values[nextState] += 1;
    postSynaptic[nOLQDR].values[nextState] += 2;
    postSynaptic[nOLQVR].values[nextState] += 1;
    postSynaptic[nPVT].values[nextState] += 1;
    postSynaptic[nRIAR].values[nextState] += 2;
    postSynaptic[nRIBL].values[nextState] += 3;
    postSynaptic[nRIBR].values[nextState] += 1;
    postSynaptic[nRIGR].values[nextState] += 2;
    postSynaptic[nRIH].values[nextState] += 1;
    postSynaptic[nSIADR].values[nextState] += 1;
    postSynaptic[nSIAVR].values[nextState] += 1;
    postSynaptic[nSIBDR].values[nextState] += 1;
    postSynaptic[nSIBVR].values[nextState] += 1;
    postSynaptic[nSMBDR].values[nextState] += 1;
    postSynaptic[nSMDDL].values[nextState] += 2;
    postSynaptic[nSMDDR].values[nextState] += 1;
    postSynaptic[nSMDVL].values[nextState] += 2;
}

void RICL() {
    postSynaptic[nADAR].values[nextState] += 1;
    postSynaptic[nASHL].values[nextState] += 2;
    postSynaptic[nAVAL].values[nextState] += 5;
    postSynaptic[nAVAR].values[nextState] += 6;
    postSynaptic[nAVKL].values[nextState] += 1;
    postSynaptic[nAVKR].values[nextState] += 2;
    postSynaptic[nAWBR].values[nextState] += 1;
    postSynaptic[nRIML].values[nextState] += 1;
    postSynaptic[nRIMR].values[nextState] += 3;
    postSynaptic[nRIVR].values[nextState] += 1;
    postSynaptic[nRMFR].values[nextState] += 1;
    postSynaptic[nSMBDL].values[nextState] += 2;
    postSynaptic[nSMDDL].values[nextState] += 3;
    postSynaptic[nSMDDR].values[nextState] += 3;
    postSynaptic[nSMDVR].values[nextState] += 1;
}

void RICR() {
    postSynaptic[nADAR].values[nextState] += 1;
    postSynaptic[nASHR].values[nextState] += 2;
    postSynaptic[nAVAL].values[nextState] += 5;
    postSynaptic[nAVAR].values[nextState] += 5;
    postSynaptic[nAVKL].values[nextState] += 1;
    postSynaptic[nSMBDR].values[nextState] += 1;
    postSynaptic[nSMDDL].values[nextState] += 4;
    postSynaptic[nSMDDR].values[nextState] += 3;
    postSynaptic[nSMDVL].values[nextState] += 2;
    postSynaptic[nSMDVR].values[nextState] += 1;
}

void RID() {
    postSynaptic[nALA].values[nextState] += 1;
    postSynaptic[nAS2].values[nextState] += 1;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 2;
    postSynaptic[nDA6].values[nextState] += 3;
    postSynaptic[nDA9].values[nextState] += 1;
    postSynaptic[nDB1].values[nextState] += 1;
    postSynaptic[nDD1].values[nextState] += 4;
    postSynaptic[nDD2].values[nextState] += 4;
    postSynaptic[nDD3].values[nextState] += 3;
    postSynaptic[nMDL14].values[nextState] += -2;
    postSynaptic[nMDL21].values[nextState] += -3;
    postSynaptic[nPDB].values[nextState] += 2;
    postSynaptic[nVD13].values[nextState] += 1;
    postSynaptic[nVD5].values[nextState] += 1;
}

void RIFL() {
    postSynaptic[nALML].values[nextState] += 2;
    postSynaptic[nAVBL].values[nextState] += 10;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nAVG].values[nextState] += 1;
    postSynaptic[nAVHR].values[nextState] += 1;
    postSynaptic[nAVJR].values[nextState] += 2;
    postSynaptic[nPVPL].values[nextState] += 3;
    postSynaptic[nRIML].values[nextState] += 4;
    postSynaptic[nVD1].values[nextState] += 1;
}

void RIFR() {
    postSynaptic[nASHR].values[nextState] += 2;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 17;
    postSynaptic[nAVFL].values[nextState] += 1;
    postSynaptic[nAVG].values[nextState] += 1;
    postSynaptic[nAVHL].values[nextState] += 1;
    postSynaptic[nAVJL].values[nextState] += 1;
    postSynaptic[nAVJR].values[nextState] += 2;
    postSynaptic[nHSNR].values[nextState] += 1;
    postSynaptic[nPVCL].values[nextState] += 1;
    postSynaptic[nPVCR].values[nextState] += 1;
    postSynaptic[nPVPR].values[nextState] += 4;
    postSynaptic[nRIMR].values[nextState] += 4;
    postSynaptic[nRIPR].values[nextState] += 1;
}

void RIGL() {
    postSynaptic[nAIBR].values[nextState] += 3;
    postSynaptic[nAIZR].values[nextState] += 1;
    postSynaptic[nALNL].values[nextState] += 1;
    postSynaptic[nAQR].values[nextState] += 2;
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nAVER].values[nextState] += 1;
    postSynaptic[nAVKL].values[nextState] += 1;
    postSynaptic[nAVKR].values[nextState] += 2;
    postSynaptic[nBAGR].values[nextState] += 2;
    postSynaptic[nDVC].values[nextState] += 1;
    postSynaptic[nOLLL].values[nextState] += 1;
    postSynaptic[nOLQDL].values[nextState] += 1;
    postSynaptic[nOLQVL].values[nextState] += 1;
    postSynaptic[nRIBL].values[nextState] += 2;
    postSynaptic[nRIGR].values[nextState] += 3;
    postSynaptic[nRIR].values[nextState] += 2;
    postSynaptic[nRMEL].values[nextState] += 2;
    postSynaptic[nRMHR].values[nextState] += 3;
    postSynaptic[nURYDL].values[nextState] += 1;
    postSynaptic[nURYVL].values[nextState] += 1;
    postSynaptic[nVB2].values[nextState] += 1;
    postSynaptic[nVD1].values[nextState] += 2;
}

void RIGR() {
    postSynaptic[nAIBL].values[nextState] += 3;
    postSynaptic[nALNR].values[nextState] += 1;
    postSynaptic[nAQR].values[nextState] += 1;
    postSynaptic[nAVER].values[nextState] += 2;
    postSynaptic[nAVKL].values[nextState] += 4;
    postSynaptic[nAVKR].values[nextState] += 2;
    postSynaptic[nBAGL].values[nextState] += 1;
    postSynaptic[nOLLR].values[nextState] += 1;
    postSynaptic[nOLQDR].values[nextState] += 1;
    postSynaptic[nOLQVR].values[nextState] += 1;
    postSynaptic[nRIBR].values[nextState] += 2;
    postSynaptic[nRIGL].values[nextState] += 3;
    postSynaptic[nRIR].values[nextState] += 1;
    postSynaptic[nRMHL].values[nextState] += 4;
    postSynaptic[nURYDR].values[nextState] += 1;
    postSynaptic[nURYVR].values[nextState] += 1;
}

void RIH() {
    postSynaptic[nADFR].values[nextState] += 1;
    postSynaptic[nAIZL].values[nextState] += 4;
    postSynaptic[nAIZR].values[nextState] += 4;
    postSynaptic[nAUAR].values[nextState] += 1;
    postSynaptic[nBAGR].values[nextState] += 1;
    postSynaptic[nCEPDL].values[nextState] += 2;
    postSynaptic[nCEPDR].values[nextState] += 2;
    postSynaptic[nCEPVL].values[nextState] += 2;
    postSynaptic[nCEPVR].values[nextState] += 2;
    postSynaptic[nFLPL].values[nextState] += 1;
    postSynaptic[nIL2L].values[nextState] += 2;
    postSynaptic[nIL2R].values[nextState] += 1;
    postSynaptic[nOLQDL].values[nextState] += 4;
    postSynaptic[nOLQDR].values[nextState] += 2;
    postSynaptic[nOLQVL].values[nextState] += 1;
    postSynaptic[nOLQVR].values[nextState] += 6;
    postSynaptic[nRIAL].values[nextState] += 10;
    postSynaptic[nRIAR].values[nextState] += 8;
    postSynaptic[nRIBL].values[nextState] += 5;
    postSynaptic[nRIBR].values[nextState] += 4;
    postSynaptic[nRIPL].values[nextState] += 4;
    postSynaptic[nRIPR].values[nextState] += 6;
    postSynaptic[nRMER].values[nextState] += 2;
    postSynaptic[nRMEV].values[nextState] += 1;
    postSynaptic[nURYVR].values[nextState] += 1;
}

void RIML() {
    postSynaptic[nAIBR].values[nextState] += 1;
    postSynaptic[nAIYL].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 2;
    postSynaptic[nAVBL].values[nextState] += 2;
    postSynaptic[nAVBR].values[nextState] += 3;
    postSynaptic[nAVEL].values[nextState] += 2;
    postSynaptic[nAVER].values[nextState] += 3;
    postSynaptic[nMDR05].values[nextState] += 2;
    postSynaptic[nMVR05].values[nextState] += 2;
    postSynaptic[nRIBL].values[nextState] += 1;
    postSynaptic[nRIS].values[nextState] += 1;
    postSynaptic[nRMDL].values[nextState] += 1;
    postSynaptic[nRMDR].values[nextState] += 1;
    postSynaptic[nRMFR].values[nextState] += 1;
    postSynaptic[nSAADR].values[nextState] += 1;
    postSynaptic[nSAAVL].values[nextState] += 3;
    postSynaptic[nSAAVR].values[nextState] += 2;
    postSynaptic[nSMDDR].values[nextState] += 5;
    postSynaptic[nSMDVL].values[nextState] += 1;
}

void RIMR() {
    postSynaptic[nADAR].values[nextState] += 1;
    postSynaptic[nAIBL].values[nextState] += 1;
    postSynaptic[nAIYR].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 5;
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nAVBL].values[nextState] += 2;
    postSynaptic[nAVBR].values[nextState] += 5;
    postSynaptic[nAVEL].values[nextState] += 3;
    postSynaptic[nAVER].values[nextState] += 2;
    postSynaptic[nAVJL].values[nextState] += 1;
    postSynaptic[nAVKL].values[nextState] += 1;
    postSynaptic[nMDL05].values[nextState] += 1;
    postSynaptic[nMDL07].values[nextState] += 1;
    postSynaptic[nMVL05].values[nextState] += 1;
    postSynaptic[nMVL07].values[nextState] += 1;
    postSynaptic[nRIBR].values[nextState] += 1;
    postSynaptic[nRIS].values[nextState] += 2;
    postSynaptic[nRMDL].values[nextState] += 1;
    postSynaptic[nRMDR].values[nextState] += 1;
    postSynaptic[nRMFL].values[nextState] += 1;
    postSynaptic[nRMFR].values[nextState] += 1;
    postSynaptic[nSAAVL].values[nextState] += 3;
    postSynaptic[nSAAVR].values[nextState] += 3;
    postSynaptic[nSMDDL].values[nextState] += 2;
    postSynaptic[nSMDDR].values[nextState] += 4;
}

void RIPL() {
    postSynaptic[nOLQDL].values[nextState] += 1;
    postSynaptic[nOLQDR].values[nextState] += 1;
    postSynaptic[nRMED].values[nextState] += 1;
}

void RIPR() {
    postSynaptic[nOLQDL].values[nextState] += 1;
    postSynaptic[nOLQDR].values[nextState] += 1;
    postSynaptic[nRMED].values[nextState] += 1;
}

void RIR() {
    postSynaptic[nAFDR].values[nextState] += 1;
    postSynaptic[nAIZL].values[nextState] += 3;
    postSynaptic[nAIZR].values[nextState] += 5;
    postSynaptic[nAUAL].values[nextState] += 1;
    postSynaptic[nAWBR].values[nextState] += 1;
    postSynaptic[nBAGL].values[nextState] += 1;
    postSynaptic[nBAGR].values[nextState] += 2;
    postSynaptic[nDVA].values[nextState] += 2;
    postSynaptic[nHSNL].values[nextState] += 1;
    postSynaptic[nPVPL].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 5;
    postSynaptic[nRIAR].values[nextState] += 1;
    postSynaptic[nRIGL].values[nextState] += 1;
    postSynaptic[nURXL].values[nextState] += 5;
    postSynaptic[nURXR].values[nextState] += 1;
}

void RIS() {
    postSynaptic[nAIBR].values[nextState] += 1;
    postSynaptic[nAVEL].values[nextState] += 7;
    postSynaptic[nAVER].values[nextState] += 7;
    postSynaptic[nAVJL].values[nextState] += 1;
    postSynaptic[nAVKL].values[nextState] += 1;
    postSynaptic[nAVKR].values[nextState] += 4;
    postSynaptic[nAVL].values[nextState] += 2;
    postSynaptic[nCEPDR].values[nextState] += 1;
    postSynaptic[nCEPVL].values[nextState] += 2;
    postSynaptic[nCEPVR].values[nextState] += 1;
    postSynaptic[nDB1].values[nextState] += 1;
    postSynaptic[nOLLR].values[nextState] += 1;
    postSynaptic[nRIBL].values[nextState] += 3;
    postSynaptic[nRIBR].values[nextState] += 5;
    postSynaptic[nRIML].values[nextState] += 2;
    postSynaptic[nRIMR].values[nextState] += 5;
    postSynaptic[nRMDDL].values[nextState] += 1;
    postSynaptic[nRMDL].values[nextState] += 2;
    postSynaptic[nRMDR].values[nextState] += 4;
    postSynaptic[nSMDDL].values[nextState] += 1;
    postSynaptic[nSMDDR].values[nextState] += 3;
    postSynaptic[nSMDVL].values[nextState] += 1;
    postSynaptic[nSMDVR].values[nextState] += 1;
    postSynaptic[nURYVR].values[nextState] += 1;
}

void RIVL() {
    postSynaptic[nAIBL].values[nextState] += 1;
    postSynaptic[nMVR05].values[nextState] += -2;
    postSynaptic[nMVR06].values[nextState] += -2;
    postSynaptic[nMVR08].values[nextState] += -3;
    postSynaptic[nRIAL].values[nextState] += 1;
    postSynaptic[nRIAR].values[nextState] += 1;
    postSynaptic[nRIVR].values[nextState] += 2;
    postSynaptic[nRMDL].values[nextState] += 2;
    postSynaptic[nSAADR].values[nextState] += 3;
    postSynaptic[nSDQR].values[nextState] += 2;
    postSynaptic[nSIAVR].values[nextState] += 2;
    postSynaptic[nSMDDR].values[nextState] += 1;
    postSynaptic[nSMDVL].values[nextState] += 1;
}

void RIVR() {
    postSynaptic[nAIBR].values[nextState] += 1;
    postSynaptic[nMVL05].values[nextState] += -2;
    postSynaptic[nMVL06].values[nextState] += -2;
    postSynaptic[nMVL08].values[nextState] += -2;
    postSynaptic[nMVR04].values[nextState] += -2;
    postSynaptic[nMVR06].values[nextState] += -2;
    postSynaptic[nRIAL].values[nextState] += 2;
    postSynaptic[nRIAR].values[nextState] += 1;
    postSynaptic[nRIVL].values[nextState] += 2;
    postSynaptic[nRMDDL].values[nextState] += 1;
    postSynaptic[nRMDR].values[nextState] += 1;
    postSynaptic[nRMDVR].values[nextState] += 1;
    postSynaptic[nRMEV].values[nextState] += 1;
    postSynaptic[nSAADL].values[nextState] += 2;
    postSynaptic[nSDQR].values[nextState] += 2;
    postSynaptic[nSIAVL].values[nextState] += 2;
    postSynaptic[nSMDDL].values[nextState] += 2;
    postSynaptic[nSMDVR].values[nextState] += 4;
}

void RMDDL() {
    postSynaptic[nMDR01].values[nextState] += 1;
    postSynaptic[nMDR02].values[nextState] += 1;
    postSynaptic[nMDR03].values[nextState] += 1;
    postSynaptic[nMDR04].values[nextState] += 1;
    postSynaptic[nMDR08].values[nextState] += 2;
    postSynaptic[nMVR01].values[nextState] += 1;
    postSynaptic[nOLQVL].values[nextState] += 1;
    postSynaptic[nRMDL].values[nextState] += 1;
    postSynaptic[nRMDVL].values[nextState] += 1;
    postSynaptic[nRMDVR].values[nextState] += 7;
    postSynaptic[nSMDDL].values[nextState] += 1;
}

void RMDDR() {
    postSynaptic[nMDL01].values[nextState] += 1;
    postSynaptic[nMDL02].values[nextState] += 1;
    postSynaptic[nMDL03].values[nextState] += 2;
    postSynaptic[nMDL04].values[nextState] += 1;
    postSynaptic[nMDR04].values[nextState] += 1;
    postSynaptic[nMVR01].values[nextState] += 1;
    postSynaptic[nMVR02].values[nextState] += 1;
    postSynaptic[nOLQVR].values[nextState] += 1;
    postSynaptic[nRMDVL].values[nextState] += 12;
    postSynaptic[nRMDVR].values[nextState] += 1;
    postSynaptic[nSAADR].values[nextState] += 1;
    postSynaptic[nSMDDR].values[nextState] += 1;
    postSynaptic[nURYDL].values[nextState] += 1;
}

void RMDL() {
    postSynaptic[nMDL03].values[nextState] += 1;
    postSynaptic[nMDL05].values[nextState] += 2;
    postSynaptic[nMDR01].values[nextState] += 1;
    postSynaptic[nMDR03].values[nextState] += 1;
    postSynaptic[nMVL01].values[nextState] += 1;
    postSynaptic[nMVR01].values[nextState] += 1;
    postSynaptic[nMVR03].values[nextState] += 1;
    postSynaptic[nMVR05].values[nextState] += 2;
    postSynaptic[nMVR07].values[nextState] += 1;
    postSynaptic[nOLLR].values[nextState] += 2;
    postSynaptic[nRIAL].values[nextState] += 4;
    postSynaptic[nRIAR].values[nextState] += 3;
    postSynaptic[nRMDDL].values[nextState] += 1;
    postSynaptic[nRMDDR].values[nextState] += 1;
    postSynaptic[nRMDR].values[nextState] += 3;
    postSynaptic[nRMDVL].values[nextState] += 1;
    postSynaptic[nRMER].values[nextState] += 1;
    postSynaptic[nRMFL].values[nextState] += 1;
}

void RMDR() {
    postSynaptic[nAVKL].values[nextState] += 1;
    postSynaptic[nMDL03].values[nextState] += 1;
    postSynaptic[nMDL05].values[nextState] += 1;
    postSynaptic[nMDR05].values[nextState] += 1;
    postSynaptic[nMVL03].values[nextState] += 1;
    postSynaptic[nMVL05].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 3;
    postSynaptic[nRIAR].values[nextState] += 7;
    postSynaptic[nRIMR].values[nextState] += 2;
    postSynaptic[nRIS].values[nextState] += 1;
    postSynaptic[nRMDDL].values[nextState] += 1;
    postSynaptic[nRMDL].values[nextState] += 1;
    postSynaptic[nRMDVR].values[nextState] += 1;
}

void RMDVL() {
    postSynaptic[nAVER].values[nextState] += 1;
    postSynaptic[nMDR01].values[nextState] += 1;
    postSynaptic[nMVL04].values[nextState] += 1;
    postSynaptic[nMVR01].values[nextState] += 1;
    postSynaptic[nMVR02].values[nextState] += 1;
    postSynaptic[nMVR03].values[nextState] += 1;
    postSynaptic[nMVR04].values[nextState] += 1;
    postSynaptic[nMVR05].values[nextState] += 1;
    postSynaptic[nMVR06].values[nextState] += 1;
    postSynaptic[nMVR08].values[nextState] += 1;
    postSynaptic[nOLQDL].values[nextState] += 1;
    postSynaptic[nRMDDL].values[nextState] += 1;
    postSynaptic[nRMDDR].values[nextState] += 6;
    postSynaptic[nRMDL].values[nextState] += 1;
    postSynaptic[nRMDVR].values[nextState] += 1;
    postSynaptic[nSAAVL].values[nextState] += 1;
    postSynaptic[nSMDVL].values[nextState] += 1;
}

void RMDVR() {
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nAVER].values[nextState] += 1;
    postSynaptic[nMDL01].values[nextState] += 1;
    postSynaptic[nMVL01].values[nextState] += 1;
    postSynaptic[nMVL02].values[nextState] += 1;
    postSynaptic[nMVL03].values[nextState] += 1;
    postSynaptic[nMVL04].values[nextState] += 1;
    postSynaptic[nMVL05].values[nextState] += 1;
    postSynaptic[nMVL06].values[nextState] += 1;
    postSynaptic[nMVL08].values[nextState] += 1;
    postSynaptic[nMVR04].values[nextState] += 1;
    postSynaptic[nMVR06].values[nextState] += 1;
    postSynaptic[nMVR08].values[nextState] += 1;
    postSynaptic[nOLQDR].values[nextState] += 1;
    postSynaptic[nRMDDL].values[nextState] += 4;
    postSynaptic[nRMDDR].values[nextState] += 1;
    postSynaptic[nRMDR].values[nextState] += 1;
    postSynaptic[nRMDVL].values[nextState] += 1;
    postSynaptic[nSAAVR].values[nextState] += 1;
    postSynaptic[nSIBDR].values[nextState] += 1;
    postSynaptic[nSIBVR].values[nextState] += 1;
    postSynaptic[nSMDVR].values[nextState] += 1;
}

void RMED() {
    postSynaptic[nIL1VL].values[nextState] += 1;
    postSynaptic[nMVL02].values[nextState] += -4;
    postSynaptic[nMVL04].values[nextState] += -4;
    postSynaptic[nMVL06].values[nextState] += -4;
    postSynaptic[nMVR02].values[nextState] += -4;
    postSynaptic[nMVR04].values[nextState] += -4;
    postSynaptic[nRIBL].values[nextState] += 1;
    postSynaptic[nRIBR].values[nextState] += 1;
    postSynaptic[nRIPL].values[nextState] += 1;
    postSynaptic[nRIPR].values[nextState] += 1;
    postSynaptic[nRMEV].values[nextState] += 2;
}

void RMEL() {
    postSynaptic[nMDR01].values[nextState] += -5;
    postSynaptic[nMDR03].values[nextState] += -5;
    postSynaptic[nMVR01].values[nextState] += -5;
    postSynaptic[nMVR03].values[nextState] += -5;
    postSynaptic[nRIGL].values[nextState] += 1;
    postSynaptic[nRMEV].values[nextState] += 1;
}

void RMER() {
    postSynaptic[nMDL01].values[nextState] += -7;
    postSynaptic[nMDL03].values[nextState] += -7;
    postSynaptic[nMVL01].values[nextState] += -7;
    postSynaptic[nRMEV].values[nextState] += 1;
}

void RMEV() {
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nAVER].values[nextState] += 1;
    postSynaptic[nIL1DL].values[nextState] += 1;
    postSynaptic[nIL1DR].values[nextState] += 1;
    postSynaptic[nMDL02].values[nextState] += -3;
    postSynaptic[nMDL04].values[nextState] += -3;
    postSynaptic[nMDL06].values[nextState] += -3;
    postSynaptic[nMDR02].values[nextState] += -3;
    postSynaptic[nMDR04].values[nextState] += -3;
    postSynaptic[nRMED].values[nextState] += 2;
    postSynaptic[nRMEL].values[nextState] += 1;
    postSynaptic[nRMER].values[nextState] += 1;
    postSynaptic[nSMDDR].values[nextState] += 1;
}

void RMFL() {
    postSynaptic[nAVKL].values[nextState] += 4;
    postSynaptic[nAVKR].values[nextState] += 4;
    postSynaptic[nMDR03].values[nextState] += 1;
    postSynaptic[nMVR01].values[nextState] += 1;
    postSynaptic[nMVR03].values[nextState] += 1;
    postSynaptic[nPVT].values[nextState] += 1;
    postSynaptic[nRIGR].values[nextState] += 1;
    postSynaptic[nRMDR].values[nextState] += 3;
    postSynaptic[nRMGR].values[nextState] += 1;
    postSynaptic[nURBR].values[nextState] += 1;
}

void RMFR() {
    postSynaptic[nAVKL].values[nextState] += 3;
    postSynaptic[nAVKR].values[nextState] += 3;
    postSynaptic[nRMDL].values[nextState] += 2;
}

void RMGL() {
    postSynaptic[nADAL].values[nextState] += 1;
    postSynaptic[nADLL].values[nextState] += 1;
    postSynaptic[nAIBR].values[nextState] += 1;
    postSynaptic[nALML].values[nextState] += 1;
    postSynaptic[nALNL].values[nextState] += 1;
    postSynaptic[nASHL].values[nextState] += 2;
    postSynaptic[nASKL].values[nextState] += 2;
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 2;
    postSynaptic[nAVEL].values[nextState] += 2;
    postSynaptic[nAWBL].values[nextState] += 1;
    postSynaptic[nCEPDL].values[nextState] += 1;
    postSynaptic[nIL2L].values[nextState] += 1;
    postSynaptic[nMDL05].values[nextState] += 2;
    postSynaptic[nMVL05].values[nextState] += 2;
    postSynaptic[nRID].values[nextState] += 1;
    postSynaptic[nRMDL].values[nextState] += 1;
    postSynaptic[nRMDR].values[nextState] += 3;
    postSynaptic[nRMDVL].values[nextState] += 3;
    postSynaptic[nRMHL].values[nextState] += 3;
    postSynaptic[nRMHR].values[nextState] += 1;
    postSynaptic[nSIAVL].values[nextState] += 1;
    postSynaptic[nSIBVL].values[nextState] += 3;
    postSynaptic[nSIBVR].values[nextState] += 1;
    postSynaptic[nSMBVL].values[nextState] += 1;
    postSynaptic[nURXL].values[nextState] += 2;
}

void RMGR() {
    postSynaptic[nADAR].values[nextState] += 1;
    postSynaptic[nAIMR].values[nextState] += 1;
    postSynaptic[nALNR].values[nextState] += 1;
    postSynaptic[nASHR].values[nextState] += 2;
    postSynaptic[nASKR].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nAVDL].values[nextState] += 1;
    postSynaptic[nAVER].values[nextState] += 3;
    postSynaptic[nAVJL].values[nextState] += 1;
    postSynaptic[nAWBR].values[nextState] += 1;
    postSynaptic[nIL2R].values[nextState] += 1;
    postSynaptic[nMDR05].values[nextState] += 1;
    postSynaptic[nMVR05].values[nextState] += 1;
    postSynaptic[nMVR07].values[nextState] += 1;
    postSynaptic[nRIR].values[nextState] += 1;
    postSynaptic[nRMDL].values[nextState] += 4;
    postSynaptic[nRMDR].values[nextState] += 2;
    postSynaptic[nRMDVR].values[nextState] += 5;
    postSynaptic[nRMHR].values[nextState] += 1;
    postSynaptic[nURXR].values[nextState] += 2;
}

void RMHL() {
    postSynaptic[nMDR01].values[nextState] += 2;
    postSynaptic[nMDR03].values[nextState] += 3;
    postSynaptic[nMVR01].values[nextState] += 2;
    postSynaptic[nRMDR].values[nextState] += 1;
    postSynaptic[nRMGL].values[nextState] += 3;
    postSynaptic[nSIBVR].values[nextState] += 1;
}

void RMHR() {
    postSynaptic[nMDL01].values[nextState] += 2;
    postSynaptic[nMDL03].values[nextState] += 2;
    postSynaptic[nMDL05].values[nextState] += 2;
    postSynaptic[nMVL01].values[nextState] += 2;
    postSynaptic[nRMER].values[nextState] += 1;
    postSynaptic[nRMGL].values[nextState] += 1;
    postSynaptic[nRMGR].values[nextState] += 1;
}

void SAADL() {
    postSynaptic[nAIBL].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 6;
    postSynaptic[nRIML].values[nextState] += 3;
    postSynaptic[nRIMR].values[nextState] += 6;
    postSynaptic[nRMGR].values[nextState] += 1;
    postSynaptic[nSMBDL].values[nextState] += 1;
}

void SAADR() {
    postSynaptic[nAIBR].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 3;
    postSynaptic[nOLLL].values[nextState] += 1;
    postSynaptic[nRIML].values[nextState] += 4;
    postSynaptic[nRIMR].values[nextState] += 5;
    postSynaptic[nRMDDR].values[nextState] += 1;
    postSynaptic[nRMFL].values[nextState] += 1;
    postSynaptic[nRMGL].values[nextState] += 1;
}

void SAAVL() {
    postSynaptic[nAIBL].values[nextState] += 1;
    postSynaptic[nALNL].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 16;
    postSynaptic[nOLLR].values[nextState] += 1;
    postSynaptic[nRIML].values[nextState] += 2;
    postSynaptic[nRIMR].values[nextState] += 12;
    postSynaptic[nRMDVL].values[nextState] += 2;
    postSynaptic[nRMFR].values[nextState] += 2;
    postSynaptic[nSMBVR].values[nextState] += 3;
    postSynaptic[nSMDDR].values[nextState] += 8;
}

void SAAVR() {
    postSynaptic[nAVAR].values[nextState] += 13;
    postSynaptic[nRIML].values[nextState] += 5;
    postSynaptic[nRIMR].values[nextState] += 2;
    postSynaptic[nRMDVR].values[nextState] += 1;
    postSynaptic[nSMBVL].values[nextState] += 2;
    postSynaptic[nSMDDL].values[nextState] += 6;
}

void SABD() {
    postSynaptic[nAVAL].values[nextState] += 4;
    postSynaptic[nVA2].values[nextState] += 4;
    postSynaptic[nVA3].values[nextState] += 2;
    postSynaptic[nVA4].values[nextState] += 1;
}

void SABVL() {
    postSynaptic[nAVAR].values[nextState] += 3;
    postSynaptic[nDA1].values[nextState] += 2;
    postSynaptic[nDA2].values[nextState] += 1;
}

void SABVR() {
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nDA1].values[nextState] += 3;
}

void SDQL() {
    postSynaptic[nALML].values[nextState] += 2;
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 3;
    postSynaptic[nAVEL].values[nextState] += 1;
    postSynaptic[nFLPL].values[nextState] += 1;
    postSynaptic[nRICR].values[nextState] += 1;
    postSynaptic[nRIS].values[nextState] += 3;
    postSynaptic[nRMFL].values[nextState] += 1;
    postSynaptic[nSDQR].values[nextState] += 1;
}

void SDQR() {
    postSynaptic[nADLL].values[nextState] += 1;
    postSynaptic[nAIBL].values[nextState] += 2;
    postSynaptic[nAVAL].values[nextState] += 3;
    postSynaptic[nAVBL].values[nextState] += 7;
    postSynaptic[nAVBR].values[nextState] += 4;
    postSynaptic[nDVA].values[nextState] += 3;
    postSynaptic[nRICR].values[nextState] += 1;
    postSynaptic[nRIVL].values[nextState] += 2;
    postSynaptic[nRIVR].values[nextState] += 2;
    postSynaptic[nRMHL].values[nextState] += 2;
    postSynaptic[nRMHR].values[nextState] += 1;
    postSynaptic[nSDQL].values[nextState] += 1;
    postSynaptic[nSIBVL].values[nextState] += 1;
}

void SIADL() {
    postSynaptic[nRIBL].values[nextState] += 1;
}

void SIADR() {
    postSynaptic[nRIBR].values[nextState] += 1;
}

void SIAVL() {
    postSynaptic[nRIBL].values[nextState] += 1;
}

void SIAVR() {
    postSynaptic[nRIBR].values[nextState] += 1;
}

void SIBDL() {
    postSynaptic[nRIBL].values[nextState] += 1;
    postSynaptic[nSIBVL].values[nextState] += 1;
}

void SIBDR() {
    postSynaptic[nAIML].values[nextState] += 1;
    postSynaptic[nRIBR].values[nextState] += 1;
    postSynaptic[nSIBVR].values[nextState] += 1;
}

void SIBVL() {
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nRIBL].values[nextState] += 1;
    postSynaptic[nSDQR].values[nextState] += 1;
    postSynaptic[nSIBDL].values[nextState] += 1;
}

void SIBVR() {
    postSynaptic[nRIBL].values[nextState] += 1;
    postSynaptic[nRIBR].values[nextState] += 1;
    postSynaptic[nRMHL].values[nextState] += 1;
    postSynaptic[nSIBDR].values[nextState] += 1;
}

void SMBDL() {
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nAVKL].values[nextState] += 1;
    postSynaptic[nAVKR].values[nextState] += 1;
    postSynaptic[nMDR01].values[nextState] += 2;
    postSynaptic[nMDR02].values[nextState] += 2;
    postSynaptic[nMDR03].values[nextState] += 2;
    postSynaptic[nMDR04].values[nextState] += 2;
    postSynaptic[nMDR06].values[nextState] += 3;
    postSynaptic[nRIBL].values[nextState] += 1;
    postSynaptic[nRMED].values[nextState] += 3;
    postSynaptic[nSAADL].values[nextState] += 1;
    postSynaptic[nSAAVR].values[nextState] += 1;
}

void SMBDR() {
    postSynaptic[nALNL].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVKL].values[nextState] += 1;
    postSynaptic[nAVKR].values[nextState] += 2;
    postSynaptic[nMDL02].values[nextState] += 1;
    postSynaptic[nMDL03].values[nextState] += 1;
    postSynaptic[nMDL04].values[nextState] += 1;
    postSynaptic[nMDL06].values[nextState] += 2;
    postSynaptic[nMDR04].values[nextState] += 1;
    postSynaptic[nMDR08].values[nextState] += 1;
    postSynaptic[nRIBR].values[nextState] += 1;
    postSynaptic[nRMED].values[nextState] += 4;
    postSynaptic[nSAAVL].values[nextState] += 3;
}

void SMBVL() {
    postSynaptic[nMVL01].values[nextState] += 1;
    postSynaptic[nMVL02].values[nextState] += 1;
    postSynaptic[nMVL03].values[nextState] += 1;
    postSynaptic[nMVL04].values[nextState] += 1;
    postSynaptic[nMVL05].values[nextState] += 1;
    postSynaptic[nMVL06].values[nextState] += 1;
    postSynaptic[nMVL08].values[nextState] += 1;
    postSynaptic[nPLNL].values[nextState] += 1;
    postSynaptic[nRMEV].values[nextState] += 5;
    postSynaptic[nSAADL].values[nextState] += 3;
    postSynaptic[nSAAVR].values[nextState] += 2;
}

void SMBVR() {
    postSynaptic[nAVKL].values[nextState] += 1;
    postSynaptic[nAVKR].values[nextState] += 1;
    postSynaptic[nMVR01].values[nextState] += 1;
    postSynaptic[nMVR02].values[nextState] += 1;
    postSynaptic[nMVR03].values[nextState] += 1;
    postSynaptic[nMVR04].values[nextState] += 1;
    postSynaptic[nMVR06].values[nextState] += 1;
    postSynaptic[nMVR07].values[nextState] += 1;
    postSynaptic[nRMEV].values[nextState] += 3;
    postSynaptic[nSAADR].values[nextState] += 4;
    postSynaptic[nSAAVL].values[nextState] += 3;
}

void SMDDL() {
    postSynaptic[nMDL04].values[nextState] += 1;
    postSynaptic[nMDL06].values[nextState] += 1;
    postSynaptic[nMDL08].values[nextState] += 1;
    postSynaptic[nMDR02].values[nextState] += 1;
    postSynaptic[nMDR03].values[nextState] += 1;
    postSynaptic[nMDR04].values[nextState] += 1;
    postSynaptic[nMDR05].values[nextState] += 1;
    postSynaptic[nMDR06].values[nextState] += 1;
    postSynaptic[nMDR07].values[nextState] += 1;
    postSynaptic[nMVL02].values[nextState] += 1;
    postSynaptic[nMVL04].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 1;
    postSynaptic[nRIAR].values[nextState] += 1;
    postSynaptic[nRIBL].values[nextState] += 1;
    postSynaptic[nRIBR].values[nextState] += 1;
    postSynaptic[nRIS].values[nextState] += 1;
    postSynaptic[nRMDDL].values[nextState] += 1;
    postSynaptic[nSMDVR].values[nextState] += 2;
}

void SMDDR() {
    postSynaptic[nMDL04].values[nextState] += 1;
    postSynaptic[nMDL05].values[nextState] += 1;
    postSynaptic[nMDL06].values[nextState] += 1;
    postSynaptic[nMDL08].values[nextState] += 1;
    postSynaptic[nMDR04].values[nextState] += 1;
    postSynaptic[nMDR06].values[nextState] += 1;
    postSynaptic[nMVR02].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 2;
    postSynaptic[nRIAR].values[nextState] += 1;
    postSynaptic[nRIBR].values[nextState] += 1;
    postSynaptic[nRIS].values[nextState] += 1;
    postSynaptic[nRMDDR].values[nextState] += 1;
    postSynaptic[nVD1].values[nextState] += 1;
}

void SMDVL() {
    postSynaptic[nMVL03].values[nextState] += 1;
    postSynaptic[nMVL06].values[nextState] += 1;
    postSynaptic[nMVR02].values[nextState] += 1;
    postSynaptic[nMVR03].values[nextState] += 1;
    postSynaptic[nMVR04].values[nextState] += 1;
    postSynaptic[nMVR06].values[nextState] += 1;
    postSynaptic[nPVR].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 3;
    postSynaptic[nRIAR].values[nextState] += 8;
    postSynaptic[nRIBR].values[nextState] += 2;
    postSynaptic[nRIS].values[nextState] += 1;
    postSynaptic[nRIVL].values[nextState] += 2;
    postSynaptic[nRMDDR].values[nextState] += 1;
    postSynaptic[nRMDVL].values[nextState] += 1;
    postSynaptic[nSMDDR].values[nextState] += 4;
    postSynaptic[nSMDVR].values[nextState] += 1;
}

void SMDVR() {
    postSynaptic[nMVL02].values[nextState] += 1;
    postSynaptic[nMVL03].values[nextState] += 1;
    postSynaptic[nMVL04].values[nextState] += 1;
    postSynaptic[nMVR07].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 7;
    postSynaptic[nRIAR].values[nextState] += 5;
    postSynaptic[nRIBL].values[nextState] += 2;
    postSynaptic[nRIVR].values[nextState] += 2;
    postSynaptic[nRMDDL].values[nextState] += 1;
    postSynaptic[nRMDVR].values[nextState] += 1;
    postSynaptic[nSMDDL].values[nextState] += 2;
    postSynaptic[nSMDVL].values[nextState] += 1;
    postSynaptic[nVB1].values[nextState] += 1;
}

void URADL() {
    postSynaptic[nIL1DL].values[nextState] += 2;
    postSynaptic[nMDL02].values[nextState] += 2;
    postSynaptic[nMDL03].values[nextState] += 2;
    postSynaptic[nMDL04].values[nextState] += 2;
    postSynaptic[nRIPL].values[nextState] += 3;
    postSynaptic[nRMEL].values[nextState] += 1;
}

void URADR() {
    postSynaptic[nIL1DR].values[nextState] += 1;
    postSynaptic[nMDR01].values[nextState] += 3;
    postSynaptic[nMDR02].values[nextState] += 2;
    postSynaptic[nMDR03].values[nextState] += 3;
    postSynaptic[nRIPR].values[nextState] += 3;
    postSynaptic[nRMDVR].values[nextState] += 1;
    postSynaptic[nRMED].values[nextState] += 1;
    postSynaptic[nRMER].values[nextState] += 1;
    postSynaptic[nURYDR].values[nextState] += 1;
}

void URAVL() {
    postSynaptic[nMVL01].values[nextState] += 2;
    postSynaptic[nMVL02].values[nextState] += 2;
    postSynaptic[nMVL03].values[nextState] += 3;
    postSynaptic[nMVL04].values[nextState] += 2;
    postSynaptic[nRIPL].values[nextState] += 3;
    postSynaptic[nRMEL].values[nextState] += 1;
    postSynaptic[nRMER].values[nextState] += 1;
    postSynaptic[nRMEV].values[nextState] += 2;
}

void URAVR() {
    postSynaptic[nIL1R].values[nextState] += 1;
    postSynaptic[nMVR01].values[nextState] += 2;
    postSynaptic[nMVR02].values[nextState] += 2;
    postSynaptic[nMVR03].values[nextState] += 2;
    postSynaptic[nMVR04].values[nextState] += 2;
    postSynaptic[nRIPR].values[nextState] += 3;
    postSynaptic[nRMDVL].values[nextState] += 1;
    postSynaptic[nRMER].values[nextState] += 2;
    postSynaptic[nRMEV].values[nextState] += 2;
}

void URBL() {
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nCEPDL].values[nextState] += 1;
    postSynaptic[nIL1L].values[nextState] += 1;
    postSynaptic[nOLQDL].values[nextState] += 1;
    postSynaptic[nOLQVL].values[nextState] += 1;
    postSynaptic[nRICR].values[nextState] += 1;
    postSynaptic[nRMDDR].values[nextState] += 1;
    postSynaptic[nSIAVL].values[nextState] += 1;
    postSynaptic[nSMBDR].values[nextState] += 1;
    postSynaptic[nURXL].values[nextState] += 2;
}

void URBR() {
    postSynaptic[nADAR].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nCEPDR].values[nextState] += 1;
    postSynaptic[nIL1R].values[nextState] += 3;
    postSynaptic[nIL2R].values[nextState] += 1;
    postSynaptic[nOLQDR].values[nextState] += 1;
    postSynaptic[nOLQVR].values[nextState] += 1;
    postSynaptic[nRICR].values[nextState] += 1;
    postSynaptic[nRMDL].values[nextState] += 1;
    postSynaptic[nRMDR].values[nextState] += 1;
    postSynaptic[nRMFL].values[nextState] += 1;
    postSynaptic[nSIAVR].values[nextState] += 2;
    postSynaptic[nSMBDL].values[nextState] += 1;
    postSynaptic[nURXR].values[nextState] += 4;
}

void URXL() {
    postSynaptic[nASHL].values[nextState] += 1;
    postSynaptic[nAUAL].values[nextState] += 5;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVEL].values[nextState] += 4;
    postSynaptic[nAVJR].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 8;
    postSynaptic[nRICL].values[nextState] += 1;
    postSynaptic[nRIGL].values[nextState] += 3;
    postSynaptic[nRMGL].values[nextState] += 1;
}

void URXR() {
    postSynaptic[nAUAR].values[nextState] += 4;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 2;
    postSynaptic[nAVER].values[nextState] += 2;
    postSynaptic[nIL2R].values[nextState] += 1;
    postSynaptic[nOLQVR].values[nextState] += 1;
    postSynaptic[nRIAR].values[nextState] += 3;
    postSynaptic[nRIGR].values[nextState] += 2;
    postSynaptic[nRIPR].values[nextState] += 3;
    postSynaptic[nRMDR].values[nextState] += 1;
    postSynaptic[nRMGR].values[nextState] += 2;
    postSynaptic[nSIAVR].values[nextState] += 1;
}

void URYDL() {
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVER].values[nextState] += 2;
    postSynaptic[nRIBL].values[nextState] += 1;
    postSynaptic[nRIGL].values[nextState] += 1;
    postSynaptic[nRMDDR].values[nextState] += 4;
    postSynaptic[nRMDVL].values[nextState] += 6;
    postSynaptic[nSMDDL].values[nextState] += 1;
    postSynaptic[nSMDDR].values[nextState] += 1;
}

void URYDR() {
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nAVEL].values[nextState] += 2;
    postSynaptic[nAVER].values[nextState] += 2;
    postSynaptic[nRIBR].values[nextState] += 1;
    postSynaptic[nRIGR].values[nextState] += 1;
    postSynaptic[nRMDDL].values[nextState] += 3;
    postSynaptic[nRMDVR].values[nextState] += 5;
    postSynaptic[nSMDDL].values[nextState] += 4;
}

void URYVL() {
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nAVER].values[nextState] += 5;
    postSynaptic[nIL1VL].values[nextState] += 1;
    postSynaptic[nRIAL].values[nextState] += 1;
    postSynaptic[nRIBL].values[nextState] += 2;
    postSynaptic[nRIGL].values[nextState] += 1;
    postSynaptic[nRIH].values[nextState] += 1;
    postSynaptic[nRIS].values[nextState] += 1;
    postSynaptic[nRMDDL].values[nextState] += 4;
    postSynaptic[nRMDVR].values[nextState] += 2;
    postSynaptic[nSIBVR].values[nextState] += 1;
    postSynaptic[nSMDVR].values[nextState] += 4;
}

void URYVR() {
    postSynaptic[nAVAL].values[nextState] += 2;
    postSynaptic[nAVEL].values[nextState] += 6;
    postSynaptic[nIL1VR].values[nextState] += 1;
    postSynaptic[nRIAR].values[nextState] += 1;
    postSynaptic[nRIBR].values[nextState] += 1;
    postSynaptic[nRIGR].values[nextState] += 1;
    postSynaptic[nRMDDR].values[nextState] += 6;
    postSynaptic[nRMDVL].values[nextState] += 4;
    postSynaptic[nSIBDR].values[nextState] += 1;
    postSynaptic[nSIBVL].values[nextState] += 1;
    postSynaptic[nSMDVL].values[nextState] += 3;
}

void VA1() {
    postSynaptic[nAVAL].values[nextState] += 3;
    postSynaptic[nDA2].values[nextState] += 2;
    postSynaptic[nDD1].values[nextState] += 9;
    postSynaptic[nMVL07].values[nextState] += 3;
    postSynaptic[nMVL08].values[nextState] += 3;
    postSynaptic[nMVR07].values[nextState] += 3;
    postSynaptic[nMVR08].values[nextState] += 3;
    postSynaptic[nVD1].values[nextState] += 2;
}

void VA2() {
    postSynaptic[nAVAL].values[nextState] += 5;
    postSynaptic[nDD1].values[nextState] += 13;
    postSynaptic[nMVL07].values[nextState] += 5;
    postSynaptic[nMVL10].values[nextState] += 5;
    postSynaptic[nMVR07].values[nextState] += 5;
    postSynaptic[nMVR10].values[nextState] += 5;
    postSynaptic[nSABD].values[nextState] += 3;
    postSynaptic[nVA3].values[nextState] += 2;
    postSynaptic[nVB1].values[nextState] += 2;
    postSynaptic[nVD1].values[nextState] += 1;
    postSynaptic[nVD2].values[nextState] += 11;
}

void VA3() {
    postSynaptic[nAS1].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 2;
    postSynaptic[nDD1].values[nextState] += 18;
    postSynaptic[nDD2].values[nextState] += 11;
    postSynaptic[nMVL09].values[nextState] += 5;
    postSynaptic[nMVL10].values[nextState] += 5;
    postSynaptic[nMVL12].values[nextState] += 5;
    postSynaptic[nMVR09].values[nextState] += 5;
    postSynaptic[nMVR10].values[nextState] += 5;
    postSynaptic[nMVR12].values[nextState] += 5;
    postSynaptic[nSABD].values[nextState] += 2;
    postSynaptic[nVA4].values[nextState] += 1;
    postSynaptic[nVD2].values[nextState] += 3;
    postSynaptic[nVD3].values[nextState] += 3;
}

void VA4() {
    postSynaptic[nAS2].values[nextState] += 2;
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 2;
    postSynaptic[nAVDL].values[nextState] += 1;
    postSynaptic[nDA5].values[nextState] += 1;
    postSynaptic[nDD2].values[nextState] += 21;
    postSynaptic[nMVL11].values[nextState] += 6;
    postSynaptic[nMVL12].values[nextState] += 6;
    postSynaptic[nMVR11].values[nextState] += 6;
    postSynaptic[nMVR12].values[nextState] += 6;
    postSynaptic[nSABD].values[nextState] += 1;
    postSynaptic[nVB3].values[nextState] += 2;
    postSynaptic[nVD4].values[nextState] += 3;
}

void VA5() {
    postSynaptic[nAS3].values[nextState] += 2;
    postSynaptic[nAVAL].values[nextState] += 5;
    postSynaptic[nAVAR].values[nextState] += 3;
    postSynaptic[nDA5].values[nextState] += 2;
    postSynaptic[nDD2].values[nextState] += 5;
    postSynaptic[nDD3].values[nextState] += 13;
    postSynaptic[nMVL11].values[nextState] += 5;
    postSynaptic[nMVL14].values[nextState] += 5;
    postSynaptic[nMVR11].values[nextState] += 5;
    postSynaptic[nMVR14].values[nextState] += 5;
    postSynaptic[nVD5].values[nextState] += 2;
}

void VA6() {
    postSynaptic[nAVAL].values[nextState] += 6;
    postSynaptic[nAVAR].values[nextState] += 2;
    postSynaptic[nDD3].values[nextState] += 24;
    postSynaptic[nMVL13].values[nextState] += 5;
    postSynaptic[nMVL14].values[nextState] += 5;
    postSynaptic[nMVR13].values[nextState] += 5;
    postSynaptic[nMVR14].values[nextState] += 5;
    postSynaptic[nVB5].values[nextState] += 2;
    postSynaptic[nVD5].values[nextState] += 1;
    postSynaptic[nVD6].values[nextState] += 2;
}

void VA7() {
    postSynaptic[nAS5].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 2;
    postSynaptic[nAVAR].values[nextState] += 4;
    postSynaptic[nDD3].values[nextState] += 3;
    postSynaptic[nDD4].values[nextState] += 12;
    postSynaptic[nMVL13].values[nextState] += 4;
    postSynaptic[nMVL15].values[nextState] += 4;
    postSynaptic[nMVL16].values[nextState] += 4;
    postSynaptic[nMVR13].values[nextState] += 4;
    postSynaptic[nMVR15].values[nextState] += 4;
    postSynaptic[nMVR16].values[nextState] += 4;
    postSynaptic[nMVULVA].values[nextState] += 4;
    postSynaptic[nVB3].values[nextState] += 1;
    postSynaptic[nVD7].values[nextState] += 9;
}

void VA8() {
    postSynaptic[nAS6].values[nextState] += 1;
    postSynaptic[nAVAL].values[nextState] += 10;
    postSynaptic[nAVAR].values[nextState] += 4;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nDD4].values[nextState] += 21;
    postSynaptic[nMVL15].values[nextState] += 6;
    postSynaptic[nMVL16].values[nextState] += 6;
    postSynaptic[nMVR15].values[nextState] += 6;
    postSynaptic[nMVR16].values[nextState] += 6;
    postSynaptic[nPDER].values[nextState] += 1;
    postSynaptic[nPVCR].values[nextState] += 2;
    postSynaptic[nVA8].values[nextState] += 1;
    postSynaptic[nVA9].values[nextState] += 1;
    postSynaptic[nVB6].values[nextState] += 1;
    postSynaptic[nVB8].values[nextState] += 3;
    postSynaptic[nVB9].values[nextState] += 3;
    postSynaptic[nVD7].values[nextState] += 5;
    postSynaptic[nVD8].values[nextState] += 1;
}

void VA9() {
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nDD4].values[nextState] += 3;
    postSynaptic[nDD5].values[nextState] += 15;
    postSynaptic[nDVB].values[nextState] += 1;
    postSynaptic[nDVC].values[nextState] += 1;
    postSynaptic[nMVL15].values[nextState] += 5;
    postSynaptic[nMVL18].values[nextState] += 5;
    postSynaptic[nMVR15].values[nextState] += 5;
    postSynaptic[nMVR18].values[nextState] += 5;
    postSynaptic[nPVCR].values[nextState] += 1;
    postSynaptic[nPVT].values[nextState] += 1;
    postSynaptic[nVB8].values[nextState] += 1;
    postSynaptic[nVB9].values[nextState] += 4;
    postSynaptic[nVD7].values[nextState] += 1;
    postSynaptic[nVD9].values[nextState] += 10;
}

void VA10() {
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nMVL17].values[nextState] += 5;
    postSynaptic[nMVL18].values[nextState] += 5;
    postSynaptic[nMVR17].values[nextState] += 5;
    postSynaptic[nMVR18].values[nextState] += 5;
}

void VA11() {
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nAVAR].values[nextState] += 7;
    postSynaptic[nDD6].values[nextState] += 10;
    postSynaptic[nMVL19].values[nextState] += 5;
    postSynaptic[nMVL20].values[nextState] += 5;
    postSynaptic[nMVR19].values[nextState] += 5;
    postSynaptic[nMVR20].values[nextState] += 5;
    postSynaptic[nPVNR].values[nextState] += 2;
    postSynaptic[nVB10].values[nextState] += 1;
    postSynaptic[nVD12].values[nextState] += 4;
}

void VA12() {
    postSynaptic[nAS11].values[nextState] += 2;
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nDA8].values[nextState] += 3;
    postSynaptic[nDA9].values[nextState] += 5;
    postSynaptic[nDB7].values[nextState] += 4;
    postSynaptic[nDD6].values[nextState] += 2;
    postSynaptic[nLUAL].values[nextState] += 2;
    postSynaptic[nMVL21].values[nextState] += 5;
    postSynaptic[nMVL22].values[nextState] += 5;
    postSynaptic[nMVL23].values[nextState] += 5;
    postSynaptic[nMVR21].values[nextState] += 5;
    postSynaptic[nMVR22].values[nextState] += 5;
    postSynaptic[nMVR23].values[nextState] += 5;
    postSynaptic[nMVR24].values[nextState] += 5;
    postSynaptic[nPHCL].values[nextState] += 1;
    postSynaptic[nPHCR].values[nextState] += 1;
    postSynaptic[nPVCL].values[nextState] += 2;
    postSynaptic[nPVCR].values[nextState] += 3;
    postSynaptic[nVA11].values[nextState] += 1;
    postSynaptic[nVB11].values[nextState] += 1;
    postSynaptic[nVD12].values[nextState] += 3;
    postSynaptic[nVD13].values[nextState] += 11;
}

void VB1() {
    postSynaptic[nAIBR].values[nextState] += 1;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVKL].values[nextState] += 4;
    postSynaptic[nDB2].values[nextState] += 2;
    postSynaptic[nDD1].values[nextState] += 1;
    postSynaptic[nDVA].values[nextState] += 1;
    postSynaptic[nMVL07].values[nextState] += 1;
    postSynaptic[nMVL08].values[nextState] += 1;
    postSynaptic[nMVR07].values[nextState] += 1;
    postSynaptic[nMVR08].values[nextState] += 1;
    postSynaptic[nRIML].values[nextState] += 2;
    postSynaptic[nRMFL].values[nextState] += 2;
    postSynaptic[nSAADL].values[nextState] += 9;
    postSynaptic[nSAADR].values[nextState] += 2;
    postSynaptic[nSABD].values[nextState] += 1;
    postSynaptic[nSMDVR].values[nextState] += 1;
    postSynaptic[nVA1].values[nextState] += 3;
    postSynaptic[nVA3].values[nextState] += 1;
    postSynaptic[nVB2].values[nextState] += 4;
    postSynaptic[nVD1].values[nextState] += 3;
    postSynaptic[nVD2].values[nextState] += 1;
}

void VB2() {
    postSynaptic[nAVBL].values[nextState] += 3;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nDB4].values[nextState] += 1;
    postSynaptic[nDD1].values[nextState] += 20;
    postSynaptic[nDD2].values[nextState] += 1;
    postSynaptic[nMVL07].values[nextState] += 4;
    postSynaptic[nMVL09].values[nextState] += 4;
    postSynaptic[nMVL10].values[nextState] += 4;
    postSynaptic[nMVL12].values[nextState] += 4;
    postSynaptic[nMVR07].values[nextState] += 4;
    postSynaptic[nMVR09].values[nextState] += 4;
    postSynaptic[nMVR10].values[nextState] += 4;
    postSynaptic[nMVR12].values[nextState] += 4;
    postSynaptic[nRIGL].values[nextState] += 1;
    postSynaptic[nVA2].values[nextState] += 1;
    postSynaptic[nVB1].values[nextState] += 4;
    postSynaptic[nVB3].values[nextState] += 1;
    postSynaptic[nVB5].values[nextState] += 1;
    postSynaptic[nVB7].values[nextState] += 2;
    postSynaptic[nVC2].values[nextState] += 1;
    postSynaptic[nVD2].values[nextState] += 9;
    postSynaptic[nVD3].values[nextState] += 3;
}

void VB3() {
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nDB1].values[nextState] += 1;
    postSynaptic[nDD2].values[nextState] += 37;
    postSynaptic[nMVL11].values[nextState] += 6;
    postSynaptic[nMVL12].values[nextState] += 6;
    postSynaptic[nMVL14].values[nextState] += 6;
    postSynaptic[nMVR11].values[nextState] += 6;
    postSynaptic[nMVR12].values[nextState] += 6;
    postSynaptic[nMVR14].values[nextState] += 6;
    postSynaptic[nVA4].values[nextState] += 1;
    postSynaptic[nVA7].values[nextState] += 1;
    postSynaptic[nVB2].values[nextState] += 1;
}

void VB4() {
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nDB1].values[nextState] += 1;
    postSynaptic[nDB4].values[nextState] += 1;
    postSynaptic[nDD2].values[nextState] += 6;
    postSynaptic[nDD3].values[nextState] += 16;
    postSynaptic[nMVL11].values[nextState] += 5;
    postSynaptic[nMVL14].values[nextState] += 5;
    postSynaptic[nMVR11].values[nextState] += 5;
    postSynaptic[nMVR14].values[nextState] += 5;
    postSynaptic[nVB5].values[nextState] += 1;
}

void VB5() {
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nDD3].values[nextState] += 27;
    postSynaptic[nMVL13].values[nextState] += 6;
    postSynaptic[nMVL14].values[nextState] += 6;
    postSynaptic[nMVR13].values[nextState] += 6;
    postSynaptic[nMVR14].values[nextState] += 6;
    postSynaptic[nVB2].values[nextState] += 1;
    postSynaptic[nVB4].values[nextState] += 1;
    postSynaptic[nVB6].values[nextState] += 8;
}

void VB6() {
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 2;
    postSynaptic[nDA4].values[nextState] += 1;
    postSynaptic[nDD4].values[nextState] += 30;
    postSynaptic[nMVL15].values[nextState] += 6;
    postSynaptic[nMVL16].values[nextState] += 6;
    postSynaptic[nMVR15].values[nextState] += 6;
    postSynaptic[nMVR16].values[nextState] += 6;
    postSynaptic[nMVULVA].values[nextState] += 6;
    postSynaptic[nVA8].values[nextState] += 1;
    postSynaptic[nVB5].values[nextState] += 1;
    postSynaptic[nVB7].values[nextState] += 1;
    postSynaptic[nVD6].values[nextState] += 1;
    postSynaptic[nVD7].values[nextState] += 8;
}

void VB7() {
    postSynaptic[nAVBL].values[nextState] += 2;
    postSynaptic[nAVBR].values[nextState] += 2;
    postSynaptic[nDD4].values[nextState] += 2;
    postSynaptic[nMVL15].values[nextState] += 5;
    postSynaptic[nMVR15].values[nextState] += 5;
    postSynaptic[nVB2].values[nextState] += 2;
}

void VB8() {
    postSynaptic[nAVBL].values[nextState] += 7;
    postSynaptic[nAVBR].values[nextState] += 3;
    postSynaptic[nDD5].values[nextState] += 30;
    postSynaptic[nMVL17].values[nextState] += 5;
    postSynaptic[nMVL18].values[nextState] += 5;
    postSynaptic[nMVL20].values[nextState] += 5;
    postSynaptic[nMVR17].values[nextState] += 5;
    postSynaptic[nMVR18].values[nextState] += 5;
    postSynaptic[nMVR20].values[nextState] += 5;
    postSynaptic[nVA8].values[nextState] += 3;
    postSynaptic[nVA9].values[nextState] += 1;
    postSynaptic[nVB9].values[nextState] += 6;
    postSynaptic[nVD10].values[nextState] += 1;
    postSynaptic[nVD9].values[nextState] += 10;
}

void VB9() {
    postSynaptic[nAVAL].values[nextState] += 5;
    postSynaptic[nAVAR].values[nextState] += 4;
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVBR].values[nextState] += 6;
    postSynaptic[nDD5].values[nextState] += 8;
    postSynaptic[nDVB].values[nextState] += 1;
    postSynaptic[nMVL17].values[nextState] += 6;
    postSynaptic[nMVL20].values[nextState] += 6;
    postSynaptic[nMVR17].values[nextState] += 6;
    postSynaptic[nMVR20].values[nextState] += 6;
    postSynaptic[nPVCL].values[nextState] += 2;
    postSynaptic[nVA8].values[nextState] += 3;
    postSynaptic[nVA9].values[nextState] += 4;
    postSynaptic[nVB8].values[nextState] += 3;
    postSynaptic[nVD10].values[nextState] += 5;
}

void VB10() {
    postSynaptic[nAVBL].values[nextState] += 2;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nAVKL].values[nextState] += 1;
    postSynaptic[nDD6].values[nextState] += 9;
    postSynaptic[nMVL19].values[nextState] += 5;
    postSynaptic[nMVL20].values[nextState] += 5;
    postSynaptic[nMVR19].values[nextState] += 5;
    postSynaptic[nMVR20].values[nextState] += 5;
    postSynaptic[nPVCL].values[nextState] += 1;
    postSynaptic[nPVT].values[nextState] += 1;
    postSynaptic[nVD11].values[nextState] += 1;
    postSynaptic[nVD12].values[nextState] += 2;
}

void VB11() {
    postSynaptic[nAVBL].values[nextState] += 2;
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nDD6].values[nextState] += 7;
    postSynaptic[nMVL21].values[nextState] += 5;
    postSynaptic[nMVL22].values[nextState] += 5;
    postSynaptic[nMVL23].values[nextState] += 5;
    postSynaptic[nMVR21].values[nextState] += 5;
    postSynaptic[nMVR22].values[nextState] += 5;
    postSynaptic[nMVR23].values[nextState] += 5;
    postSynaptic[nMVR24].values[nextState] += 5;
    postSynaptic[nPVCR].values[nextState] += 1;
    postSynaptic[nVA12].values[nextState] += 2;
}

void VC1() {
    postSynaptic[nAVL].values[nextState] += 2;
    postSynaptic[nDD1].values[nextState] += 7;
    postSynaptic[nDD2].values[nextState] += 6;
    postSynaptic[nDD3].values[nextState] += 6;
    postSynaptic[nDVC].values[nextState] += 1;
    postSynaptic[nMVULVA].values[nextState] += 6;
    postSynaptic[nPVT].values[nextState] += 2;
    postSynaptic[nVC2].values[nextState] += 9;
    postSynaptic[nVC3].values[nextState] += 3;
    postSynaptic[nVD1].values[nextState] += 5;
    postSynaptic[nVD2].values[nextState] += 1;
    postSynaptic[nVD3].values[nextState] += 1;
    postSynaptic[nVD4].values[nextState] += 2;
    postSynaptic[nVD5].values[nextState] += 5;
    postSynaptic[nVD6].values[nextState] += 1;
}

void VC2() {
    postSynaptic[nDB4].values[nextState] += 1;
    postSynaptic[nDD1].values[nextState] += 6;
    postSynaptic[nDD2].values[nextState] += 4;
    postSynaptic[nDD3].values[nextState] += 9;
    postSynaptic[nDVC].values[nextState] += 1;
    postSynaptic[nMVULVA].values[nextState] += 10;
    postSynaptic[nPVCR].values[nextState] += 1;
    postSynaptic[nPVQR].values[nextState] += 1;
    postSynaptic[nPVT].values[nextState] += 2;
    postSynaptic[nVC1].values[nextState] += 10;
    postSynaptic[nVC3].values[nextState] += 6;
    postSynaptic[nVD1].values[nextState] += 2;
    postSynaptic[nVD2].values[nextState] += 2;
    postSynaptic[nVD4].values[nextState] += 5;
    postSynaptic[nVD5].values[nextState] += 5;
    postSynaptic[nVD6].values[nextState] += 1;
}

void VC3() {
    postSynaptic[nAVL].values[nextState] += 1;
    postSynaptic[nDD1].values[nextState] += 2;
    postSynaptic[nDD2].values[nextState] += 4;
    postSynaptic[nDD3].values[nextState] += 5;
    postSynaptic[nDD4].values[nextState] += 13;
    postSynaptic[nDVC].values[nextState] += 1;
    postSynaptic[nHSNR].values[nextState] += 1;
    postSynaptic[nMVULVA].values[nextState] += 11;
    postSynaptic[nPVNR].values[nextState] += 1;
    postSynaptic[nPVPR].values[nextState] += 1;
    postSynaptic[nPVQR].values[nextState] += 4;
    postSynaptic[nVC1].values[nextState] += 4;
    postSynaptic[nVC2].values[nextState] += 3;
    postSynaptic[nVC4].values[nextState] += 1;
    postSynaptic[nVC5].values[nextState] += 2;
    postSynaptic[nVD1].values[nextState] += 1;
    postSynaptic[nVD2].values[nextState] += 1;
    postSynaptic[nVD3].values[nextState] += 1;
    postSynaptic[nVD4].values[nextState] += 2;
    postSynaptic[nVD5].values[nextState] += 4;
    postSynaptic[nVD6].values[nextState] += 4;
    postSynaptic[nVD7].values[nextState] += 5;
}

void VC4() {
    postSynaptic[nAVBL].values[nextState] += 1;
    postSynaptic[nAVFR].values[nextState] += 1;
    postSynaptic[nAVHR].values[nextState] += 1;
    postSynaptic[nMVULVA].values[nextState] += 7;
    postSynaptic[nVC1].values[nextState] += 1;
    postSynaptic[nVC3].values[nextState] += 5;
    postSynaptic[nVC5].values[nextState] += 2;
}

void VC5() {
    postSynaptic[nAVFL].values[nextState] += 1;
    postSynaptic[nAVFR].values[nextState] += 1;
    postSynaptic[nDVC].values[nextState] += 2;
    postSynaptic[nHSNL].values[nextState] += 1;
    postSynaptic[nMVULVA].values[nextState] += 2;
    postSynaptic[nOLLR].values[nextState] += 1;
    postSynaptic[nPVT].values[nextState] += 1;
    postSynaptic[nURBL].values[nextState] += 3;
    postSynaptic[nVC3].values[nextState] += 3;
    postSynaptic[nVC4].values[nextState] += 2;
}

void VC6() {
    postSynaptic[nMVULVA].values[nextState] += 1;
}

void VD1() {
    postSynaptic[nDD1].values[nextState] += 5;
    postSynaptic[nDVC].values[nextState] += 5;
    postSynaptic[nMVL05].values[nextState] += -5;
    postSynaptic[nMVL08].values[nextState] += -5;
    postSynaptic[nMVR05].values[nextState] += -5;
    postSynaptic[nMVR08].values[nextState] += -5;
    postSynaptic[nRIFL].values[nextState] += 1;
    postSynaptic[nRIGL].values[nextState] += 2;
    postSynaptic[nSMDDR].values[nextState] += 1;
    postSynaptic[nVA1].values[nextState] += 2;
    postSynaptic[nVA2].values[nextState] += 1;
    postSynaptic[nVC1].values[nextState] += 1;
    postSynaptic[nVD2].values[nextState] += 7;
}

void VD2() {
    postSynaptic[nAS1].values[nextState] += 1;
    postSynaptic[nDD1].values[nextState] += 3;
    postSynaptic[nMVL07].values[nextState] += -7;
    postSynaptic[nMVL10].values[nextState] += -7;
    postSynaptic[nMVR07].values[nextState] += -7;
    postSynaptic[nMVR10].values[nextState] += -7;
    postSynaptic[nVA2].values[nextState] += 9;
    postSynaptic[nVB2].values[nextState] += 3;
    postSynaptic[nVD1].values[nextState] += 7;
    postSynaptic[nVD3].values[nextState] += 2;
}

void VD3() {
    postSynaptic[nMVL09].values[nextState] += -7;
    postSynaptic[nMVL12].values[nextState] += -9;
    postSynaptic[nMVR09].values[nextState] += -7;
    postSynaptic[nMVR12].values[nextState] += -7;
    postSynaptic[nPVPL].values[nextState] += 1;
    postSynaptic[nVA3].values[nextState] += 2;
    postSynaptic[nVB2].values[nextState] += 2;
    postSynaptic[nVD2].values[nextState] += 2;
    postSynaptic[nVD4].values[nextState] += 1;
}

void VD4() {
    postSynaptic[nDD2].values[nextState] += 2;
    postSynaptic[nMVL11].values[nextState] += -9;
    postSynaptic[nMVL12].values[nextState] += -9;
    postSynaptic[nMVR11].values[nextState] += -9;
    postSynaptic[nMVR12].values[nextState] += -9;
    postSynaptic[nPVPR].values[nextState] += 1;
    postSynaptic[nVD3].values[nextState] += 1;
    postSynaptic[nVD5].values[nextState] += 1;
}

void VD5() {
    postSynaptic[nAVAR].values[nextState] += 1;
    postSynaptic[nMVL14].values[nextState] += -17;
    postSynaptic[nMVR14].values[nextState] += -17;
    postSynaptic[nPVPR].values[nextState] += 1;
    postSynaptic[nVA5].values[nextState] += 2;
    postSynaptic[nVB4].values[nextState] += 2;
    postSynaptic[nVD4].values[nextState] += 1;
    postSynaptic[nVD6].values[nextState] += 2;
}

void VD6() {
    postSynaptic[nAVAL].values[nextState] += 1;
    postSynaptic[nMVL13].values[nextState] += -7;
    postSynaptic[nMVL14].values[nextState] += -7;
    postSynaptic[nMVL16].values[nextState] += -7;
    postSynaptic[nMVR13].values[nextState] += -7;
    postSynaptic[nMVR14].values[nextState] += -7;
    postSynaptic[nMVR16].values[nextState] += -7;
    postSynaptic[nVA6].values[nextState] += 1;
    postSynaptic[nVB5].values[nextState] += 2;
    postSynaptic[nVD5].values[nextState] += 2;
    postSynaptic[nVD7].values[nextState] += 1;
}

void VD7() {
    postSynaptic[nMVL15].values[nextState] += -7;
    postSynaptic[nMVL16].values[nextState] += -7;
    postSynaptic[nMVR15].values[nextState] += -7;
    postSynaptic[nMVR16].values[nextState] += -7;
    postSynaptic[nMVULVA].values[nextState] += -15;
    postSynaptic[nVA9].values[nextState] += 1;
    postSynaptic[nVD6].values[nextState] += 1;
}

void VD8() {
    postSynaptic[nDD4].values[nextState] += 2;
    postSynaptic[nMVL15].values[nextState] += -18;
    postSynaptic[nMVR15].values[nextState] += -18;
    postSynaptic[nVA8].values[nextState] += 5;
}

void VD9() {
    postSynaptic[nMVL17].values[nextState] += -10;
    postSynaptic[nMVL18].values[nextState] += -10;
    postSynaptic[nMVR17].values[nextState] += -10;
    postSynaptic[nMVR18].values[nextState] += -10;
    postSynaptic[nPDER].values[nextState] += 1;
    postSynaptic[nVD10].values[nextState] += 5;
}

void VD10() {
    postSynaptic[nAVBR].values[nextState] += 1;
    postSynaptic[nDD5].values[nextState] += 2;
    postSynaptic[nDVC].values[nextState] += 4;
    postSynaptic[nMVL17].values[nextState] += -9;
    postSynaptic[nMVL20].values[nextState] += -9;
    postSynaptic[nMVR17].values[nextState] += -9;
    postSynaptic[nMVR20].values[nextState] += -9;
    postSynaptic[nVB9].values[nextState] += 2;
    postSynaptic[nVD9].values[nextState] += 5;
}

void VD11() {
    postSynaptic[nAVAR].values[nextState] += 2;
    postSynaptic[nMVL19].values[nextState] += -9;
    postSynaptic[nMVL20].values[nextState] += -9;
    postSynaptic[nMVR19].values[nextState] += -9;
    postSynaptic[nMVR20].values[nextState] += -9;
    postSynaptic[nVA11].values[nextState] += 1;
    postSynaptic[nVB10].values[nextState] += 1;
}

void VD12() {
    postSynaptic[nMVL19].values[nextState] += -5;
    postSynaptic[nMVL21].values[nextState] += -5;
    postSynaptic[nMVR19].values[nextState] += -5;
    postSynaptic[nMVR22].values[nextState] += -5;
    postSynaptic[nVA11].values[nextState] += 3;
    postSynaptic[nVA12].values[nextState] += 2;
    postSynaptic[nVB10].values[nextState] += 1;
    postSynaptic[nVB11].values[nextState] += 1;
}

void VD13() {
    postSynaptic[nAVAR].values[nextState] += 2;
    postSynaptic[nMVL21].values[nextState] += -9;
    postSynaptic[nMVL22].values[nextState] += -9;
    postSynaptic[nMVL23].values[nextState] += -9;
    postSynaptic[nMVR21].values[nextState] += -9;
    postSynaptic[nMVR22].values[nextState] += -9;
    postSynaptic[nMVR23].values[nextState] += -9;
    postSynaptic[nMVR24].values[nextState] += -9;
    postSynaptic[nPVCL].values[nextState] += 1;
    postSynaptic[nPVCR].values[nextState] += 1;
    postSynaptic[nPVPL].values[nextState] += 2;
    postSynaptic[nVA12].values[nextState] += 1;
}

void createPostSynaptic() {
    postSynaptic[nADAL] = { ADAL, { 0, 0 } };
    postSynaptic[nADAR] = { ADAR, { 0, 0 } };
    postSynaptic[nADEL] = { ADEL, { 0, 0 } };
    postSynaptic[nADER] = { ADER, { 0, 0 } };
    postSynaptic[nADFL] = { ADFL, { 0, 0 } };
    postSynaptic[nADFR] = { ADFR, { 0, 0 } };
    postSynaptic[nADLL] = { ADLL, { 0, 0 } };
    postSynaptic[nADLR] = { ADLR, { 0, 0 } };
    postSynaptic[nAFDL] = { AFDL, { 0, 0 } };
    postSynaptic[nAFDR] = { AFDR, { 0, 0 } };
    postSynaptic[nAIAL] = { AIAL, { 0, 0 } };
    postSynaptic[nAIAR] = { AIAR, { 0, 0 } };
    postSynaptic[nAIBL] = { AIBL, { 0, 0 } };
    postSynaptic[nAIBR] = { AIBR, { 0, 0 } };
    postSynaptic[nAIML] = { AIML, { 0, 0 } };
    postSynaptic[nAIMR] = { AIMR, { 0, 0 } };
    postSynaptic[nAINL] = { AINL, { 0, 0 } };
    postSynaptic[nAINR] = { AINR, { 0, 0 } };
    postSynaptic[nAIYL] = { AIYL, { 0, 0 } };
    postSynaptic[nAIYR] = { AIYR, { 0, 0 } };
    postSynaptic[nAIZL] = { AIZL, { 0, 0 } };
    postSynaptic[nAIZR] = { AIZR, { 0, 0 } };
    postSynaptic[nALA] = { ALA, { 0, 0 } };
    postSynaptic[nALML] = { ALML, { 0, 0 } };
    postSynaptic[nALMR] = { ALMR, { 0, 0 } };
    postSynaptic[nALNL] = { ALNL, { 0, 0 } };
    postSynaptic[nALNR] = { ALNR, { 0, 0 } };
    postSynaptic[nAQR] = { AQR, { 0, 0 } };
    postSynaptic[nAS1] = { AS1, { 0, 0 } };
    postSynaptic[nAS10] = { AS10, { 0, 0 } };
    postSynaptic[nAS11] = { AS11, { 0, 0 } };
    postSynaptic[nAS2] = { AS2, { 0, 0 } };
    postSynaptic[nAS3] = { AS3, { 0, 0 } };
    postSynaptic[nAS4] = { AS4, { 0, 0 } };
    postSynaptic[nAS5] = { AS5, { 0, 0 } };
    postSynaptic[nAS6] = { AS6, { 0, 0 } };
    postSynaptic[nAS7] = { AS7, { 0, 0 } };
    postSynaptic[nAS8] = { AS8, { 0, 0 } };
    postSynaptic[nAS9] = { AS9, { 0, 0 } };
    postSynaptic[nASEL] = { ASEL, { 0, 0 } };
    postSynaptic[nASER] = { ASER, { 0, 0 } };
    postSynaptic[nASGL] = { ASGL, { 0, 0 } };
    postSynaptic[nASGR] = { ASGR, { 0, 0 } };
    postSynaptic[nASHL] = { ASHL, { 0, 0 } };
    postSynaptic[nASHR] = { ASHR, { 0, 0 } };
    postSynaptic[nASIL] = { ASIL, { 0, 0 } };
    postSynaptic[nASIR] = { ASIR, { 0, 0 } };
    postSynaptic[nASJL] = { ASJL, { 0, 0 } };
    postSynaptic[nASJR] = { ASJR, { 0, 0 } };
    postSynaptic[nASKL] = { ASKL, { 0, 0 } };
    postSynaptic[nASKR] = { ASKR, { 0, 0 } };
    postSynaptic[nAUAL] = { AUAL, { 0, 0 } };
    postSynaptic[nAUAR] = { AUAR, { 0, 0 } };
    postSynaptic[nAVAL] = { AVAL, { 0, 0 } };
    postSynaptic[nAVAR] = { AVAR, { 0, 0 } };
    postSynaptic[nAVBL] = { AVBL, { 0, 0 } };
    postSynaptic[nAVBR] = { AVBR, { 0, 0 } };
    postSynaptic[nAVDL] = { AVDL, { 0, 0 } };
    postSynaptic[nAVDR] = { AVDR, { 0, 0 } };
    postSynaptic[nAVEL] = { AVEL, { 0, 0 } };
    postSynaptic[nAVER] = { AVER, { 0, 0 } };
    postSynaptic[nAVFL] = { AVFL, { 0, 0 } };
    postSynaptic[nAVFR] = { AVFR, { 0, 0 } };
    postSynaptic[nAVG] = { AVG, { 0, 0 } };
    postSynaptic[nAVHL] = { AVHL, { 0, 0 } };
    postSynaptic[nAVHR] = { AVHR, { 0, 0 } };
    postSynaptic[nAVJL] = { AVJL, { 0, 0 } };
    postSynaptic[nAVJR] = { AVJR, { 0, 0 } };
    postSynaptic[nAVKL] = { AVKL, { 0, 0 } };
    postSynaptic[nAVKR] = { AVKR, { 0, 0 } };
    postSynaptic[nAVL] = { AVL, { 0, 0 } };
    postSynaptic[nAVM] = { AVM, { 0, 0 } };
    postSynaptic[nAWAL] = { AWAL, { 0, 0 } };
    postSynaptic[nAWAR] = { AWAR, { 0, 0 } };
    postSynaptic[nAWBL] = { AWBL, { 0, 0 } };
    postSynaptic[nAWBR] = { AWBR, { 0, 0 } };
    postSynaptic[nAWCL] = { AWCL, { 0, 0 } };
    postSynaptic[nAWCR] = { AWCR, { 0, 0 } };
    postSynaptic[nBAGL] = { BAGL, { 0, 0 } };
    postSynaptic[nBAGR] = { BAGR, { 0, 0 } };
    postSynaptic[nBDUL] = { BDUL, { 0, 0 } };
    postSynaptic[nBDUR] = { BDUR, { 0, 0 } };
    postSynaptic[nCEPDL] = { CEPDL, { 0, 0 } };
    postSynaptic[nCEPDR] = { CEPDR, { 0, 0 } };
    postSynaptic[nCEPVL] = { CEPVL, { 0, 0 } };
    postSynaptic[nCEPVR] = { CEPVR, { 0, 0 } };
    postSynaptic[nDA1] = { DA1, { 0, 0 } };
    postSynaptic[nDA2] = { DA2, { 0, 0 } };
    postSynaptic[nDA3] = { DA3, { 0, 0 } };
    postSynaptic[nDA4] = { DA4, { 0, 0 } };
    postSynaptic[nDA5] = { DA5, { 0, 0 } };
    postSynaptic[nDA6] = { DA6, { 0, 0 } };
    postSynaptic[nDA7] = { DA7, { 0, 0 } };
    postSynaptic[nDA8] = { DA8, { 0, 0 } };
    postSynaptic[nDA9] = { DA9, { 0, 0 } };
    postSynaptic[nDB1] = { DB1, { 0, 0 } };
    postSynaptic[nDB2] = { DB2, { 0, 0 } };
    postSynaptic[nDB3] = { DB3, { 0, 0 } };
    postSynaptic[nDB4] = { DB4, { 0, 0 } };
    postSynaptic[nDB5] = { DB5, { 0, 0 } };
    postSynaptic[nDB6] = { DB6, { 0, 0 } };
    postSynaptic[nDB7] = { DB7, { 0, 0 } };
    postSynaptic[nDD1] = { DD1, { 0, 0 } };
    postSynaptic[nDD2] = { DD2, { 0, 0 } };
    postSynaptic[nDD3] = { DD3, { 0, 0 } };
    postSynaptic[nDD4] = { DD4, { 0, 0 } };
    postSynaptic[nDD5] = { DD5, { 0, 0 } };
    postSynaptic[nDD6] = { DD6, { 0, 0 } };
    postSynaptic[nDVA] = { DVA, { 0, 0 } };
    postSynaptic[nDVB] = { DVB, { 0, 0 } };
    postSynaptic[nDVC] = { DVC, { 0, 0 } };
    postSynaptic[nFLPL] = { FLPL, { 0, 0 } };
    postSynaptic[nFLPR] = { FLPR, { 0, 0 } };
    postSynaptic[nHSNL] = { HSNL, { 0, 0 } };
    postSynaptic[nHSNR] = { HSNR, { 0, 0 } };
    postSynaptic[nI1L] = { I1L, { 0, 0 } };
    postSynaptic[nI1R] = { I1R, { 0, 0 } };
    postSynaptic[nI2L] = { I2L, { 0, 0 } };
    postSynaptic[nI2R] = { I2R, { 0, 0 } };
    postSynaptic[nI3] = { I3, { 0, 0 } };
    postSynaptic[nI4] = { I4, { 0, 0 } };
    postSynaptic[nI5] = { I5, { 0, 0 } };
    postSynaptic[nI6] = { I6, { 0, 0 } };
    postSynaptic[nIL1DL] = { IL1DL, { 0, 0 } };
    postSynaptic[nIL1DR] = { IL1DR, { 0, 0 } };
    postSynaptic[nIL1L] = { IL1L, { 0, 0 } };
    postSynaptic[nIL1R] = { IL1R, { 0, 0 } };
    postSynaptic[nIL1VL] = { IL1VL, { 0, 0 } };
    postSynaptic[nIL1VR] = { IL1VR, { 0, 0 } };
    postSynaptic[nIL2L] = { IL2L, { 0, 0 } };
    postSynaptic[nIL2R] = { IL2R, { 0, 0 } };
    postSynaptic[nIL2DL] = { IL2DL, { 0, 0 } };
    postSynaptic[nIL2DR] = { IL2DR, { 0, 0 } };
    postSynaptic[nIL2VL] = { IL2VL, { 0, 0 } };
    postSynaptic[nIL2VR] = { IL2VR, { 0, 0 } };
    postSynaptic[nLUAL] = { LUAL, { 0, 0 } };
    postSynaptic[nLUAR] = { LUAR, { 0, 0 } };
    postSynaptic[nM1] = { M1, { 0, 0 } };
    postSynaptic[nM2L] = { M2L, { 0, 0 } };
    postSynaptic[nM2R] = { M2R, { 0, 0 } };
    postSynaptic[nM3L] = { M3L, { 0, 0 } };
    postSynaptic[nM3R] = { M3R, { 0, 0 } };
    postSynaptic[nM4] = { M4, { 0, 0 } };
    postSynaptic[nM5] = { M5, { 0, 0 } };
    postSynaptic[nMANAL] = { nullptr, { 0, 0 } }; // why doesnt this have weight????
    postSynaptic[nMCL] = { MCL, { 0, 0 } };
    postSynaptic[nMCR] = { MCR, { 0, 0 } };
    postSynaptic[nMDL01] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL02] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL03] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL04] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL05] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL06] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL07] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL08] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL09] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL10] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL11] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL12] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL13] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL14] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL15] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL16] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL17] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL18] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL19] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL20] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL21] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL22] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL23] = { nullptr, { 0, 0 } };
    postSynaptic[nMDL24] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR01] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR02] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR03] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR04] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR05] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR06] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR07] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR08] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR09] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR10] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR11] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR12] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR13] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR14] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR15] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR16] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR17] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR18] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR19] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR20] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR21] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR22] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR23] = { nullptr, { 0, 0 } };
    postSynaptic[nMDR24] = { nullptr, { 0, 0 } };
    postSynaptic[nMI] = { MI, { 0, 0 } };
    postSynaptic[nMVL01] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL02] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL03] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL04] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL05] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL06] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL07] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL08] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL09] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL10] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL11] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL12] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL13] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL14] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL15] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL16] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL17] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL18] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL19] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL20] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL21] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL22] = { nullptr, { 0, 0 } };
    postSynaptic[nMVL23] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR01] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR02] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR03] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR04] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR05] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR06] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR07] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR08] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR09] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR10] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR11] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR12] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR13] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR14] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR15] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR16] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR17] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR18] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR19] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR20] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR21] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR22] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR23] = { nullptr, { 0, 0 } };
    postSynaptic[nMVR24] = { nullptr, { 0, 0 } };
    postSynaptic[nMVULVA] = { nullptr, { 0, 0 } };
    postSynaptic[nNSML] = { NSML, { 0, 0 } };
    postSynaptic[nNSMR] = { NSMR, { 0, 0 } };
    postSynaptic[nOLLL] = { OLLL, { 0, 0 } };
    postSynaptic[nOLLR] = { OLLR, { 0, 0 } };
    postSynaptic[nOLQDL] = { OLQDL, { 0, 0 } };
    postSynaptic[nOLQDR] = { OLQDR, { 0, 0 } };
    postSynaptic[nOLQVL] = { OLQVL, { 0, 0 } };
    postSynaptic[nOLQVR] = { OLQVR, { 0, 0 } };
    postSynaptic[nPDA] = { PDA, { 0, 0 } };
    postSynaptic[nPDB] = { PDB, { 0, 0 } };
    postSynaptic[nPDEL] = { PDEL, { 0, 0 } };
    postSynaptic[nPDER] = { PDER, { 0, 0 } };
    postSynaptic[nPHAL] = { PHAL, { 0, 0 } };
    postSynaptic[nPHAR] = { PHAR, { 0, 0 } };
    postSynaptic[nPHBL] = { PHBL, { 0, 0 } };
    postSynaptic[nPHBR] = { PHBR, { 0, 0 } };
    postSynaptic[nPHCL] = { PHCL, { 0, 0 } };
    postSynaptic[nPHCR] = { PHCR, { 0, 0 } };
    postSynaptic[nPLML] = { PLML, { 0, 0 } };
    postSynaptic[nPLMR] = { PLMR, { 0, 0 } };
    postSynaptic[nPLNL] = { PLNL, { 0, 0 } };
    postSynaptic[nPLNR] = { PLNR, { 0, 0 } };
    postSynaptic[nPQR] = { PQR, { 0, 0 } };
    postSynaptic[nPVCL] = { PVCL, { 0, 0 } };
    postSynaptic[nPVCR] = { PVCR, { 0, 0 } };
    postSynaptic[nPVDL] = { PVDL, { 0, 0 } };
    postSynaptic[nPVDR] = { PVDR, { 0, 0 } };
    postSynaptic[nPVM] = { PVM, { 0, 0 } };
    postSynaptic[nPVNL] = { PVNL, { 0, 0 } };
    postSynaptic[nPVNR] = { PVNR, { 0, 0 } };
    postSynaptic[nPVPL] = { PVPL, { 0, 0 } };
    postSynaptic[nPVPR] = { PVPR, { 0, 0 } };
    postSynaptic[nPVQL] = { PVQL, { 0, 0 } };
    postSynaptic[nPVQR] = { PVQR, { 0, 0 } };
    postSynaptic[nPVR] = { PVR, { 0, 0 } };
    postSynaptic[nPVT] = { PVT, { 0, 0 } };
    postSynaptic[nPVWL] = { PVWL, { 0, 0 } };
    postSynaptic[nPVWR] = { PVWR, { 0, 0 } };
    postSynaptic[nRIAL] = { RIAL, { 0, 0 } };
    postSynaptic[nRIAR] = { RIAR, { 0, 0 } };
    postSynaptic[nRIBL] = { RIBL, { 0, 0 } };
    postSynaptic[nRIBR] = { RIBR, { 0, 0 } };
    postSynaptic[nRICL] = { RICL, { 0, 0 } };
    postSynaptic[nRICR] = { RICR, { 0, 0 } };
    postSynaptic[nRID] = { RID, { 0, 0 } };
    postSynaptic[nRIFL] = { RIFL, { 0, 0 } };
    postSynaptic[nRIFR] = { RIFR, { 0, 0 } };
    postSynaptic[nRIGL] = { RIGL, { 0, 0 } };
    postSynaptic[nRIGR] = { RIGR, { 0, 0 } };
    postSynaptic[nRIH] = { RIH, { 0, 0 } };
    postSynaptic[nRIML] = { RIML, { 0, 0 } };
    postSynaptic[nRIMR] = { RIMR, { 0, 0 } };
    postSynaptic[nRIPL] = { RIPL, { 0, 0 } };
    postSynaptic[nRIPR] = { RIPR, { 0, 0 } };
    postSynaptic[nRIR] = { RIR, { 0, 0 } };
    postSynaptic[nRIS] = { RIS, { 0, 0 } };
    postSynaptic[nRIVL] = { RIVL, { 0, 0 } };
    postSynaptic[nRIVR] = { RIVR, { 0, 0 } };
    postSynaptic[nRMDDL] = { RMDDL, { 0, 0 } };
    postSynaptic[nRMDDR] = { RMDDR, { 0, 0 } };
    postSynaptic[nRMDL] = { RMDL, { 0, 0 } };
    postSynaptic[nRMDR] = { RMDR, { 0, 0 } };
    postSynaptic[nRMDVL] = { RMDVL, { 0, 0 } };
    postSynaptic[nRMDVR] = { RMDVR, { 0, 0 } };
    postSynaptic[nRMED] = { RMED, { 0, 0 } };
    postSynaptic[nRMEL] = { RMEL, { 0, 0 } };
    postSynaptic[nRMER] = { RMER, { 0, 0 } };
    postSynaptic[nRMEV] = { RMEV, { 0, 0 } };
    postSynaptic[nRMFL] = { RMFL, { 0, 0 } };
    postSynaptic[nRMFR] = { RMFR, { 0, 0 } };
    postSynaptic[nRMGL] = { RMGL, { 0, 0 } };
    postSynaptic[nRMGR] = { RMGR, { 0, 0 } };
    postSynaptic[nRMHL] = { RMHL, { 0, 0 } };
    postSynaptic[nRMHR] = { RMHR, { 0, 0 } };
    postSynaptic[nSAADL] = { SAADL, { 0, 0 } };
    postSynaptic[nSAADR] = { SAADR, { 0, 0 } };
    postSynaptic[nSAAVL] = { SAAVL, { 0, 0 } };
    postSynaptic[nSAAVR] = { SAAVR, { 0, 0 } };
    postSynaptic[nSABD] = { SABD, { 0, 0 } };
    postSynaptic[nSABVL] = { SABVL, { 0, 0 } };
    postSynaptic[nSABVR] = { SABVR, { 0, 0 } };
    postSynaptic[nSDQL] = { SDQL, { 0, 0 } };
    postSynaptic[nSDQR] = { SDQR, { 0, 0 } };
    postSynaptic[nSIADL] = { SIADL, { 0, 0 } };
    postSynaptic[nSIADR] = { SIADR, { 0, 0 } };
    postSynaptic[nSIAVL] = { SIAVL, { 0, 0 } };
    postSynaptic[nSIAVR] = { SIAVR, { 0, 0 } };
    postSynaptic[nSIBDL] = { SIBDL, { 0, 0 } };
    postSynaptic[nSIBDR] = { SIBDR, { 0, 0 } };
    postSynaptic[nSIBVL] = { SIBVL, { 0, 0 } };
    postSynaptic[nSIBVR] = { SIBVR, { 0, 0 } };
    postSynaptic[nSMBDL] = { SMBDL, { 0, 0 } };
    postSynaptic[nSMBDR] = { SMBDR, { 0, 0 } };
    postSynaptic[nSMBVL] = { SMBVL, { 0, 0 } };
    postSynaptic[nSMBVR] = { SMBVR, { 0, 0 } };
    postSynaptic[nSMDDL] = { SMDDL, { 0, 0 } };
    postSynaptic[nSMDDR] = { SMDDR, { 0, 0 } };
    postSynaptic[nSMDVL] = { SMDVL, { 0, 0 } };
    postSynaptic[nSMDVR] = { SMDVR, { 0, 0 } };
    postSynaptic[nURADL] = { URADL, { 0, 0 } };
    postSynaptic[nURADR] = { URADR, { 0, 0 } };
    postSynaptic[nURAVL] = { URAVL, { 0, 0 } };
    postSynaptic[nURAVR] = { URAVR, { 0, 0 } };
    postSynaptic[nURBL] = { URBL, { 0, 0 } };
    postSynaptic[nURBR] = { URBR, { 0, 0 } };
    postSynaptic[nURXL] = { URXL, { 0, 0 } };
    postSynaptic[nURXR] = { URXR, { 0, 0 } };
    postSynaptic[nURYDL] = { URYDL, { 0, 0 } };
    postSynaptic[nURYDR] = { URYDR, { 0, 0 } };
    postSynaptic[nURYVL] = { URYVL, { 0, 0 } };
    postSynaptic[nURYVR] = { URYVR, { 0, 0 } };
    postSynaptic[nVA1] = { VA1, { 0, 0 } };
    postSynaptic[nVA10] = { VA10, { 0, 0 } };
    postSynaptic[nVA11] = { VA11, { 0, 0 } };
    postSynaptic[nVA12] = { VA12, { 0, 0 } };
    postSynaptic[nVA2] = { VA2, { 0, 0 } };
    postSynaptic[nVA3] = { VA3, { 0, 0 } };
    postSynaptic[nVA4] = { VA4, { 0, 0 } };
    postSynaptic[nVA5] = { VA5, { 0, 0 } };
    postSynaptic[nVA6] = { VA6, { 0, 0 } };
    postSynaptic[nVA7] = { VA7, { 0, 0 } };
    postSynaptic[nVA8] = { VA8, { 0, 0 } };
    postSynaptic[nVA9] = { VA9, { 0, 0 } };
    postSynaptic[nVB1] = { VB1, { 0, 0 } };
    postSynaptic[nVB10] = { VB10, { 0, 0 } };
    postSynaptic[nVB11] = { VB11, { 0, 0 } };
    postSynaptic[nVB2] = { VB2, { 0, 0 } };
    postSynaptic[nVB3] = { VB3, { 0, 0 } };
    postSynaptic[nVB4] = { VB4, { 0, 0 } };
    postSynaptic[nVB5] = { VB5, { 0, 0 } };
    postSynaptic[nVB6] = { VB6, { 0, 0 } };
    postSynaptic[nVB7] = { VB7, { 0, 0 } };
    postSynaptic[nVB8] = { VB8, { 0, 0 } };
    postSynaptic[nVB9] = { VB9, { 0, 0 } };
    postSynaptic[nVC1] = { VC1, { 0, 0 } };
    postSynaptic[nVC2] = { VC2, { 0, 0 } };
    postSynaptic[nVC3] = { VC3, { 0, 0 } };
    postSynaptic[nVC4] = { VC4, { 0, 0 } };
    postSynaptic[nVC5] = { VC5, { 0, 0 } };
    postSynaptic[nVC6] = { VC6, { 0, 0 } };
    postSynaptic[nVD1] = { VD1, { 0, 0 } };
    postSynaptic[nVD10] = { VD10, { 0, 0 } };
    postSynaptic[nVD11] = { VD11, { 0, 0 } };
    postSynaptic[nVD12] = { VD12, { 0, 0 } };
    postSynaptic[nVD13] = { VD13, { 0, 0 } };
    postSynaptic[nVD2] = { VD2, { 0, 0 } };
    postSynaptic[nVD3] = { VD3, { 0, 0 } };
    postSynaptic[nVD4] = { VD4, { 0, 0 } };
    postSynaptic[nVD5] = { VD5, { 0, 0 } };
    postSynaptic[nVD6] = { VD6, { 0, 0 } };
    postSynaptic[nVD7] = { VD7, { 0, 0 } };
    postSynaptic[nVD8] = { VD8, { 0, 0 } };
    postSynaptic[nVD9] = { VD9, { 0, 0 } };
}

void motorcontrol() {
    accumLeft = 0;
    accumRight = 0;
    //suboptimal
    for (int i=0; i< neuron_count; i++) {
        if(postSynaptic[i].fireNeuron == nullptr) {
            if( ((i >= nMVL01) && (i <=nMVL23))
              || ((i >= nMDL01) || (i <= nMDL24) ) ) {
                // std::cout << "accumLeft = " << accumLeft << " + " << pair.first << ", " << postSynaptic[pair.first]].values[nextState] << "\n";
                accumLeft += postSynaptic[i].values[nextState];
                postSynaptic[i].values[nextState] = 0;
            } else if( ((i >= nMVR01) || (i <=nMVR24))
              || ((i >= nMDR01) || (i<=nMDR24)) ) {
                // std::cout << "accumRight = " << accumRight << " + " << pair.first << ", " << postSynaptic[pair.first]].values[nextState] << "\n";
                accumRight += postSynaptic[i].values[nextState];
                postSynaptic[i].values[nextState] = 0;
            }
        }
    }
}

void runconnectome() {
    for (int i=0; i< neuron_count; i++) {
        //if(pair.first == "ADAL") std::cout << pair.first << ": [ " << pair.second].values[thisState] << ", " << pair.second.values[nextState] << " ]\n";
        if((postSynaptic[i].fireNeuron != nullptr) && (postSynaptic[i].values[thisState] > fireThreshold)) {
            postSynaptic[i].fireNeuron();
            postSynaptic[i].values[nextState] = 0;
        }

        motorcontrol();

        for (int j=0; i< neuron_count; i++) {
            //std::cout << postSynaptic[j].values[thisState] << ", " << postSynaptic[j].values[nextState] << "\n";
            postSynaptic[j].values[thisState] = postSynaptic[j].values[nextState];
        };

        int temp = thisState;
        thisState = nextState;
        nextState = temp;
    }
}

void update() {
    if(stimulateHungerNeurons) {
        RIML();
        RIMR();
        RICL();
        RICR();
        runconnectome();
    }
    if(stimulateNoseTouchNeurons) {
        FLPR();
        FLPL();
        ASHL();
        ASHR();
        IL1VL();
        IL1VR();
        OLQDL();
        OLQDR();
        OLQVR();
        OLQVL();
        runconnectome();
    }
    if(stimulateFoodSenseNeurons) {
        ADFL();
        ADFR();
        ASGR();
        ASGL();
        ASIL();
        ASIR();
        ASJR();
        ASJL();
        runconnectome();
    }
}

int main() {
    createPostSynaptic();
    while(true) {
        update();
        //std::cout << "thisState: " << thisState << ", nextState: " << nextState << "\n";
    }
}

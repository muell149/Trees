#!/bin/bash
#echo "Sourcing cmsset_default.sh"
#cd /afs/cern.ch/cms/sw
#source cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc491
echo "SCRAM_ARCH is $SCRAM_ARCH"
cd /afs/cern.ch/user/m/muell149/work/HLTONLINE/CMSSW_7_3_0/src/Event-by-Event_Validation/HLTEventByEventComparison/test
echo "In Directory: "
pwd
eval `scramv1 runtime -sh`
echo "cmsenv success!"
echo "executing python"
 
python validate_rel.py
 
echo "done"
date

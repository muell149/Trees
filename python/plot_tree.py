from ROOT import TFile, TTree, TBranch, TCanvas, TLegend

f1 = TFile("../ttH125_ND_cuts/ttH125_ND_cuts_job000.root")
f2 = TFile("../ttH125_DESY_30kevts_DESY/ttH125_DESY_30kevts_DESY_job000.root")
#f2 = TFile("../ttH125_DESY_testCodeV1/ttH125_DESY_testCodeV1_job000.root");
output = TFile("trees.root","recreate")
t1 = f1.Get("summaryTree")
t2 = f2.Get("summaryTree")

branches = t1.GetListOfBranches()
events = t1.GetEntriesFast()
nbr = t1.GetNbranches()

d1 = {}
d2 = {}
#loop 1
for jentry in xrange(events):
    t1.GetEntry(jentry)
    t2.GetEntry(jentry)

    j1_1 = [t1.jets_by_pt_1_eta,t1.jets_by_pt_1_pt]
    j1_2 = [t1.jets_by_pt_2_eta,t1.jets_by_pt_2_pt]
    j1_3 = [t1.jets_by_pt_3_eta,t1.jets_by_pt_3_pt]
    j1_4 = [t1.jets_by_pt_4_eta,t1.jets_by_pt_4_pt]

    j2_1 = [t2.jets_by_pt_1_eta,t2.jets_by_pt_1_pt]
    j2_2 = [t2.jets_by_pt_2_eta,t2.jets_by_pt_2_pt]
    j2_3 = [t2.jets_by_pt_3_eta,t2.jets_by_pt_3_pt]
    j2_4 = [t2.jets_by_pt_4_eta,t2.jets_by_pt_4_pt]

    l1 = [j1_1,j1_2,j1_3,j1_4] #make a list of lists of jet characteristics
    l2 = [j2_1,j2_2,j2_3,j2_4]
        
    d1[t1.eventInfo_evt] = sorted(l1, key=lambda eta: eta[0]) #sort the lists by the first value in the lists
    d2[t2.eventInfo_evt] = sorted(l2, key=lambda eta: eta[0])

print "done with loop1"
#loop 2
mismatch = 0
match = 0
for ientry in xrange(events):
    t1.GetEntry(ientry)
    t2.GetEntry(ientry)
    key = t1.eventInfo_evt
    
    if d1.has_key(key) and d2.has_key(key):
        print "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"
        print "ND event:  ", key
        print "DESY event:", key
        print "        jet1  jet2  jet3  jet4"
        print "pt "
        print "ND:   ", round(d1[key][0][1],2), round(d1[key][1][1],2), round(d1[key][2][1],2), round(d1[key][3][1],2)
        print "DESY: ", round(d2[key][0][1],2), round(d2[key][1][1],2), round(d2[key][2][1],2), round(d2[key][3][1],2)
        print " "
        print "eta"
        print "ND:   ", round(d1[key][0][0],2), round(d1[key][1][0],2), round(d1[key][2][0],2), round(d1[key][3][0],2)
        print "DESY: ", round(d2[key][0][0],2), round(d2[key][1][0],2), round(d2[key][2][0],2), round(d2[key][3][0],2)
        match += 1
        
        
    else:
        print "MISMATCH!!! ",t1.eventInfo_evt, t2.eventInfo_evt
        mismatch += 1
        print mismatch

print "mistmatched events ",mismatch
print "matched events     ",match


#         print "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"
#         print "ND event:  ", t1.eventInfo_evt
#         print "DESY event:", t2.eventInfo_evt
#         print "        jet1  jet2  jet3  jet4"
#         print "pt "
#         print "ND:   ", round(t1.jets_by_pt_1_pt,2), round(t1.jets_by_pt_2_pt,2), round(t1.jets_by_pt_3_pt,2), round(t1.jets_by_pt_4_pt,2)
#         print "DESY: ",round(t2.jets_by_pt_1_pt,2), round(t2.jets_by_pt_2_pt,2), round(t2.jets_by_pt_3_pt,2), round(t2.jets_by_pt_4_pt,2)
#         print " "
#         print "eta"
#         print "ND:   ",round(t1.jets_by_pt_1_eta,2), round(t1.jets_by_pt_2_eta,2), round(t1.jets_by_pt_3_eta,2), round(t1.jets_by_pt_4_eta,2)
#         print "DESY: ",round(t2.jets_by_pt_1_eta,2), round(t2.jets_by_pt_2_eta,2), round(t2.jets_by_pt_3_eta,2), round(t2.jets_by_pt_4_eta,2)
#     else:
#         print "MISMATCH!!! ",t1.eventInfo_evt, t2.eventInfo_evt






    
#for i in xrange(nbr):
    #name = branches[i].GetName()
    #name1 = name+'>-9e9'
    #print i, name
    #t1.SetLineColor(1)
    #t2.SetLineColor(2)
    #can1 = TCanvas(name,name)
    #t1.Draw(name,name1,"")
    #t2.Draw(name,name1,"same")
    #leg = TLegend(0.83,0.66,0.99,0.77,"","brNDC")
    #leg.AddEntry(t1,"ND")
    #leg.AddEntry(t2,"DESY")
    #leg.Draw("same")
    #can1.Write()


void plot_tree()
{
  TFile* f1 = new TFile("../ttH125_ND_cuts/ttH125_ND_cuts_job000.root");
  TFile* f2 = new TFile("../ttH125_DESY_30kevts_DESY/ttH125_DESY_30kevts_DESY_job000.root");
  
  TTree* t1 = (TTree*)f1->Get("summaryTree");
  TTree* t2 = (TTree*)f2->Get("summaryTree");
  TObjArray* list1 = (TObjArray*)t1->GetListOfBranches();
  Int_t* nbr = t1->GetNbranches();
  
  const char* bname;
  std::string s2;
  
  TFile* output = new TFile("canvases.root","recreate");
  
  for (Int_t i=0; nbr>i;i++)
    {
      cout << i << endl;
      bname = list1[1][i]->GetName();
      cout << bname << endl;
      cout << "Entries(ND)   = " << t1->GetBranch(bname)->GetEntries() << endl;
      cout << "Entries(DESY) = " << t2->GetBranch(bname)->GetEntries() <<endl;
      std::string s0(bname);
      s0+=">-9e6";
      t1->SetLineColor(1);
      t2->SetLineColor(2);
      TCanvas* can1 = new TCanvas(bname, bname);
      t1->Draw(bname,s0.c_str(),"");
      t2->Draw(bname,s0.c_str(),"same");
      TLegend *leg = new TLegend(0.83,0.66,0.99,0.77,NULL,"brNDC"); 
      leg->AddEntry(t1,"ND");
      leg->AddEntry(t2,"DESY");
      leg->Draw("same");
      //std::string s1(bname);
      //s2 = "~/www/v1/"+s1+".png";
      //can1->SaveAs(s2.c_str());
      can1->Write();
    }
}

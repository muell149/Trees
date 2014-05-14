
void plot_tree_single()
{
  TFile* f1 = new TFile("../ttH125_v2_bTag_Final/ttH125_v2_bTag_Final_job000.root");

  
  TTree* t1 = (TTree*)f1->Get("summaryTree");
  TTree* t2 = (TTree*)f1->Get("summaryTree");
  TTree* t3 = (TTree*)f1->Get("summaryTree");


  const char* bname = "ttH125";
  TFile* output = new TFile("canvases.root","recreate");


  TCanvas* can1 = new TCanvas(bname, bname);
  t1->Draw("jets_fromLF_by_pt_1_btagCombinedSecVertex>>h1","jets_fromLF_by_pt_1_btagCombinedSecVertex>0","");
  h1->SetLineColor(1);
  h1->Draw();
  t2->Draw("jets_fromLF_by_pt_1_btagCombinedSecVertexV1>>h2","jets_fromLF_by_pt_1_btagCombinedSecVertexV1>0","same");
  h2->SetLineColor(2);
  h2->Draw("same");
  t3->Draw("jets_fromLF_by_pt_1_btagCombinedSecVertexSLV1>>h3","jets_fromLF_by_pt_1_btagCombinedSecVertexSLV1>0","same");
  h3->SetLineColor(4);
  h3->Draw("same");

  TLegend *leg = new TLegend(0.83,0.66,0.99,0.77,NULL,"brNDC");
  leg->AddEntry(h1,"CSV");
  leg->AddEntry(h2,"CSV V1");
  leg->AddEntry(h3,"CSV SLV1");
  leg->Draw("same");

  
}


//   for (Int_t i=0; nbr>i;i++)
//     {
//       cout << i << endl;
//       bname = list1[1][i]->GetName();
//       cout << bname << endl;
//       cout << "Entries(ND)   = " << t1->GetBranch(bname)->GetEntries() << endl;
//       cout << "Entries(DESY) = " << t2->GetBranch(bname)->GetEntries() <<endl;
//       std::string s0(bname);
//       s0+=">-9e6";
//       t1->SetLineColor(1);
//       t2->SetLineColor(2);
//       TCanvas* can1 = new TCanvas(bname, bname);
//       t1->Draw(bname,s0.c_str(),"");
//       t2->Draw(bname,s0.c_str(),"same");
//       TLegend *leg = new TLegend(0.83,0.66,0.99,0.77,NULL,"brNDC"); 
//       leg->AddEntry(t1,"ND");
//       leg->AddEntry(t2,"DESY");
//       leg->Draw("same");
//       //std::string s1(bname);
//       //s2 = "~/www/v1/"+s1+".png";
//       //can1->SaveAs(s2.c_str());
//       can1->Write();
//     }
// }

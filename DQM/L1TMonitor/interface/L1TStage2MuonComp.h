#ifndef DQM_L1TMonitor_L1TStage2MuonComp_h
#define DQM_L1TMonitor_L1TStage2MuonComp_h


#include "DataFormats/L1Trigger/interface/Muon.h"

#include "DQMServices/Core/interface/DQMEDAnalyzer.h"
#include "DQMServices/Core/interface/MonitorElement.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ParameterSet/interface/ConfigurationDescriptions.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescription.h"


class L1TStage2MuonComp : public DQMEDAnalyzer {

 public:

  L1TStage2MuonComp(const edm::ParameterSet& ps);
  ~L1TStage2MuonComp() override;
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

 protected:

  void dqmBeginRun(const edm::Run&, const edm::EventSetup&) override;
  void bookHistograms(DQMStore::IBooker&, const edm::Run&, const edm::EventSetup&) override;
  void analyze(const edm::Event&, const edm::EventSetup&) override;

 private:  

  enum variables {BXRANGEGOOD=1, BXRANGEBAD, NMUONGOOD, NMUONBAD, MUONALL, MUONGOOD, PTBAD, ETABAD, PHIBAD, ETAATVTXBAD, PHIATVTXBAD, CHARGEBAD, CHARGEVALBAD, QUALBAD, ISOBAD, IDXBAD};
  enum ratioVariables {RBXRANGE=1, RNMUON, RMUON, RPT, RETA, RPHI, RETAATVTX, RPHIATVTX, RCHARGE, RCHARGEVAL, RQUAL, RISO, RIDX};
  bool incBin[RIDX+1];

  edm::EDGetTokenT<l1t::MuonBxCollection> muonToken1;
  edm::EDGetTokenT<l1t::MuonBxCollection> muonToken2;
  std::string monitorDir;
  std::string muonColl1Title;
  std::string muonColl2Title;
  std::string summaryTitle;
  std::vector<int> ignoreBin;
  bool verbose;

  MonitorElement* summary;
  MonitorElement* errorSummaryNum;
  MonitorElement* errorSummaryDen;

  MonitorElement* muColl1BxRange;
  MonitorElement* muColl1nMu;
  MonitorElement* muColl1hwPt;
  MonitorElement* muColl1hwEta;
  MonitorElement* muColl1hwPhi;
  MonitorElement* muColl1hwEtaAtVtx;
  MonitorElement* muColl1hwPhiAtVtx;
  MonitorElement* muColl1hwCharge;
  MonitorElement* muColl1hwChargeValid;
  MonitorElement* muColl1hwQual;
  MonitorElement* muColl1hwIso;
  MonitorElement* muColl1Index;

  MonitorElement* muColl2BxRange;
  MonitorElement* muColl2nMu;
  MonitorElement* muColl2hwPt;
  MonitorElement* muColl2hwEta;
  MonitorElement* muColl2hwPhi;
  MonitorElement* muColl2hwEtaAtVtx;
  MonitorElement* muColl2hwPhiAtVtx;
  MonitorElement* muColl2hwCharge;
  MonitorElement* muColl2hwChargeValid;
  MonitorElement* muColl2hwQual;
  MonitorElement* muColl2hwIso;
  MonitorElement* muColl2Index;

};

#endif

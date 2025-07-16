// iot_consent_sim.cc
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"

using namespace ns3;

int main (int argc, char *argv[])
{
  CommandLine cmd;
  cmd.Parse (argc, argv);

  // Simulation d'un device IoT qui envoie le consentement (1 ou 0)
  NS_LOG_UNCOND ("Simulation IoT Consentement :");
  int consent = 1; // changer à 0 pour simuler le refus

  if (consent == 1)
    NS_LOG_UNCOND ("Consentement OUI : données collectées, chiffrées et transmises");
  else
    NS_LOG_UNCOND ("Consentement NON : aucune donnée collectée, processus arrêté");

  Simulator::Stop (Seconds (1.0));
  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}

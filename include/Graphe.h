#ifndef GRAPHE_H
#define GRAPHE_H

#include <unordered_map>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include "Sommet.h"
#include "Arete.h"
#include "svgfile.h"

class Graphe
{
  private:
      std::vector<Sommet*> m_sommets; /// L'ensemble des Sommets qui composent le graphe
      std::vector<Arete*> m_aretes;   /// L'ensemble des Aretes qui composent le graphe

  public:
    Graphe(std::string nomFichier, std::string nomFichier2);
    Graphe(std::vector<Sommet*> m_sommets, std::vector<Arete*> m_aretes);
    ~Graphe();

    /// GETTERS
    std::vector<Sommet*> getSommets() const { return m_sommets; }
    std::vector<Arete*>  getAretes()  const { return m_aretes; }

    /// Affichage
    void dessiner(Svgfile& svgout, int x = 0, int y = 0, bool toggleText = 0, float coeffTaille = 1);
    void dessiner(Svgfile& svgout, std::vector<bool> vecBool, int x = 0, int y = 0, bool toggleText = 0, float coeffTaille = 1);

    /// Algorithmes
    std::vector<float> resultatGraphe(); /// nous retourne un tableau de float qui correspond au résultat du grapheen fonction de chacun des poids possibles
    std::vector<float> resultatGraphe(std::vector<bool> vecBool); /// Retourne comme la fonction non overload mais permet de prendre en compte un tableau de bool (1 = arete prise en compte; 0 = pas prise en compte)

    Graphe parcourKruskal(unsigned int indexOfPoids);

    std::vector<std::vector<bool>*> ensembleGraphesPartiels();
    std::vector<std::vector<bool>*> ensembleArbresCouvrants(std::vector<std::vector<bool>*> vec);

    void affichagePareto();
};

#endif // GRAPHE_H

#ifndef ARETE_H
#define ARETE_H

#include "Sommet.h"

class Arete
{
  public:
    Arete(int index, int s1, int s2);
    Arete(int index, int s1, int s2, std::vector<float> vecPoids);

    void setArete(int index, int s1, int s2) {
        setIndex(index);
        this->m_s1 = s1;
        this->m_s2 = s2;
    }
    void setIndex(int index) {
        ( index >= 0 )? this->m_index = index : this->m_index = -1;
    }
    void setS1(int index) {
        ( index >= 0 )? this->m_s1 = index : this->m_s1 = -1;
    }
    void setS2(int index) {
        ( index >= 0 )? this->m_s2 = index : this->m_s2 = -1;
    }
    void addPoids(float poids) { this->m_poids.push_back(poids); }

    /// GETTERS
    int getS1() const    { return m_s1; }
    int getS2() const    { return m_s2; }
    std::vector<float> getPoids() const { return m_poids; }
    int getPoids(unsigned int indexOfPoids) const { return m_poids[indexOfPoids]; }
    int getNbPoids() const { return m_poids.size(); }
    int getIndex() const { return m_index; }

    ~Arete() = default;

  protected:

  private:
      int m_index;                  /// index de l'ar�te pour son r�f�rencement
      int m_s1, m_s2;               /// ici on a les deux sommets qui forment l'ar�te
      std::vector<float> m_poids;   /// poids[0] = co�ts et poids[1] = ?(tmpsTrajet)
};

#endif // ARETE_H

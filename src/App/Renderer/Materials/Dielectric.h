#ifndef RTIAW_material_dielectric
#define RTIAW_material_dielectric

#include "Materials/Material.h"

namespace RTIAW::Render::Materials {
class Dielectric : public Material {
public:
  Dielectric(const float refractionIndex) : m_refractionIndex(refractionIndex) {}

  [[nodiscard]] std::optional<ScatteringResult> Scatter(const Ray &r_in, const HitRecord &rec) const override;

public:
  float m_refractionIndex;

  static float Reflectance(float cosine, float refractionIndex) {
    // Use Schlick's approximation for reflectance.
    float r0 = (1.0f - refractionIndex) / (1.0f + refractionIndex);
    r0 = r0 * r0;
    return r0 + (1.0f - r0) * std::pow((1.0f - cosine), 5.0f);
  }
};
} // namespace RTIAW::Render::Materials

#endif

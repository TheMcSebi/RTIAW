#ifndef RTIAW_material_lambertian
#define RTIAW_material_lambertian

#include <optional>

#include "HitRecord.h"
#include "ScatteringRecord.h"

namespace RTIAW::Render::Materials {
class Lambertian {
public:
  explicit Lambertian(const color &albedo) : m_albedo(albedo) {}

  [[nodiscard]] std::optional<ScatteringRecord> Scatter(const Ray &r_in, const HitRecord &rec) const;

public:
  color m_albedo;
};
} // namespace RTIAW::Render::Materials

#endif

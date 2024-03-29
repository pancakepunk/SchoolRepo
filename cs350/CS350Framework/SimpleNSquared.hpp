///////////////////////////////////////////////////////////////////////////////
///
/// Authors: Joshua Davis
/// Copyright 2015, DigiPen Institute of Technology
///
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "SpatialPartition.hpp"

//-----------------------------------------------------------------------------BoundingSphereSpatialPartition
// A very bad, brute force spatial partition that is used for assignment 1 (before you get to implement something better).
// Do not implement your spatial partitions this way, make sure that update and remove are O(1) (no searches).
class NSquaredSpatialPartition : public SpatialPartition
{
public:
  NSquaredSpatialPartition();

  void CreateProxy(Proxy& proxy, SpatialPartitionData& data) override;
  void UpdateProxy(Proxy& proxy, SpatialPartitionData& data) override;
  void RemoveProxy(Proxy& proxy) override;

  void DebugDraw(int level, const Math::Matrix4& transform, const Vector4& color = Vector4(1), int bitMask = 0) override;

  void CastRay(const Ray& ray, CastResults& results) override;
  void CastFrustum(const Frustum& frustum, CastResults& results) override;

  void SelfQuery(QueryResults& results) override;

  void GetDataFromProxy(const Proxy& proxy, SpatialPartitionData& data) const override;
  void FilloutData(std::vector<SpatialPartitionQueryData>& results) const override;

  std::vector<void*> mData;
};

/******Student:Assignment2******/
// Implement the n-squared sphere spatial partition
//-----------------------------------------------------------------------------BoundingSphereSpatialPartition
class BoundingSphereSpatialPartition : public SpatialPartition
{
public:
  BoundingSphereSpatialPartition();

  void CreateProxy(Proxy& proxy, SpatialPartitionData& data) override;
  void UpdateProxy(Proxy& proxy, SpatialPartitionData& data) override;
  void RemoveProxy(Proxy& proxy) override;

  void DebugDraw(int level, const Math::Matrix4& transform, const Vector4& color = Vector4(1), int bitMask = 0) override;

  void CastRay(const Ray& ray, CastResults& results) override;
  void CastFrustum(const Frustum& frustum, CastResults& results) override;

  void SelfQuery(QueryResults& results) override;

  void FilloutData(std::vector<SpatialPartitionQueryData>& results) const override;

  // Add your implementation here
};

/******Student:Assignment2******/
// Implement the n-squared aabb spatial partition
//-----------------------------------------------------------------------------BoundingAabbSpatialPartition 
class BoundingAabbSpatialPartition : public SpatialPartition
{
public:
  BoundingAabbSpatialPartition();

  void CreateProxy(Proxy& proxy, SpatialPartitionData& data) override;
  void UpdateProxy(Proxy& proxy, SpatialPartitionData& data) override;
  void RemoveProxy(Proxy& proxy) override;

  void DebugDraw(int level, const Math::Matrix4& transform, const Vector4& color = Vector4(1), int bitMask = 0) override;

  void CastRay(const Ray& ray, CastResults& results) override;
  void CastFrustum(const Frustum& frustum, CastResults& results) override;

  void SelfQuery(QueryResults& results) override;

  void FilloutData(std::vector<SpatialPartitionQueryData>& results) const override;

  // Add your implementation here
};

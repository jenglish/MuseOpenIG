﻿/*
-----------------------------------------------------------------------------
File:        AxisAlignedBoundingBox.h
Copyright:   Copyright (C) 2007-2015 Poojan Prabhu. All rights reserved.
Created:     10/20/2015
Last edit:   12/15/2015
Author:      Poojan Prabhu
E-mail:      poojanprabhu@gmail.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#pragma once

#if defined(OPENIG_SDK) 
#include <OpenIG-Graphics/OIGCudaPreamble.h>
#include <OpenIG-Graphics/Vector3.h>
#include <OpenIG-Graphics/Vector4.h>
#include <OpenIG-Graphics/Matrix4.h>
#include <OpenIG-Graphics/CommonUtils.h>
#else
#include <Library-Graphics/OIGCudaPreamble.h>
#include <Library-Graphics/Vector3.h>
#include <Library-Graphics/Vector4.h>
#include <Library-Graphics/Matrix4.h>
#include <Library-Graphics/CommonUtils.h>
#endif

#if GRAPHICS_LIBRARY_HAS_NAMESPACE
namespace OpenIG {
	namespace Library {
		namespace Graphics {
#endif

#if COMPILE_FOR_GPU
	#define EXTENT_NULL 0
	#define EXTENT_FINITE 1
	#define EXTENT_INFINITE 2
	typedef int Extent;
#else
			enum Extent
			{
				EXTENT_NULL = 0
			  , EXTENT_FINITE = 1
			  , EXTENT_INFINITE = 2
			};
#endif

			template <class T>
			class AxisAlignedBoundingBox

			{
			public:
				GPU_PREFIX AxisAlignedBoundingBox();
				GPU_PREFIX AxisAlignedBoundingBox(const Vector3<T>& vMin, const Vector3<T>& vMax);
				GPU_PREFIX ~AxisAlignedBoundingBox();

				GPU_PREFIX const Vector3<T>& GetMin(void) const;
				GPU_PREFIX const Vector3<T>& GetMax(void) const;
				GPU_PREFIX Vector3<T> GetCenter(void) const;
				GPU_PREFIX T GetBoundingSphereRadius(void) const;

				GPU_PREFIX Vector3<T> GetHalfSize(void) const;
				GPU_PREFIX Vector3<T> GetSize(void) const;
				GPU_PREFIX Extent GetExtent(void) const;

				GPU_PREFIX void SetMinMax(const Vector3<T>& vMin, const Vector3<T>& vMax);
				GPU_PREFIX void SetNull(void);
				GPU_PREFIX void SetInfinite(void);

				GPU_PREFIX void Merge(const AxisAlignedBoundingBox<T>& rhs);
				GPU_PREFIX void TransformAffine(const Matrix4<T>& m);

				GPU_PREFIX bool IsInfinite(void) const;
				GPU_PREFIX bool IsFinite(void) const;
				GPU_PREFIX bool IsNull(void) const;

				GPU_PREFIX void GetCorners(Vector3<T> corners[8]) const;

			private:
				Vector3<T> m_vMin;
				Vector3<T> m_vMax;
				Extent m_Extent;
			};

			typedef AxisAlignedBoundingBox<float32> AxisAlignedBoundingBox_32;
			typedef AxisAlignedBoundingBox<float64> AxisAlignedBoundingBox_64;

#if GRAPHICS_LIBRARY_HAS_NAMESPACE
		}
	}
}
#endif

#include "AxisAlignedBoundingBox.inl"
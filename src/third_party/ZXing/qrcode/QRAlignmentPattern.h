#pragma once
/*
* Copyright 2016 Nu-book Inc.
* Copyright 2016 ZXing authors
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "ResultPoint.h"

namespace ZXing {
namespace QRCode {

/**
* <p>Encapsulates an alignment pattern, which are the smaller square patterns found in
* all but the simplest QR Codes.</p>
*
* @author Sean Owen
*/
class AlignmentPattern : public ResultPoint
{
	float _estimatedModuleSize = 0;

public:
	AlignmentPattern() = default;
	AlignmentPattern(float posX, float posY, float estimatedModuleSize);

	float estimatedModuleSize() const {
		return _estimatedModuleSize;
	}

	bool isValid() const { return _estimatedModuleSize > 0.f; }

	/**
	* <p>Determines if this alignment pattern "about equals" an alignment pattern at the stated
	* position and size -- meaning, it is at nearly the same center with nearly the same size.</p>
	*/
	bool aboutEquals(float moduleSize, float i, float j) const;

	/**
	* Combines this object's current estimate of a finder pattern position and module size
	* with a new estimate. It returns a new {@code FinderPattern} containing an average of the two.
	*/
	AlignmentPattern combineEstimate(float i, float j, float newModuleSize) const;
};

} // QRCode
} // ZXing

#pragma once

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <memory>
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif
namespace Kaitai {

	class gen3_switch_t : public kaitai::kstruct {

	public:
		gen3_switch_t (kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, gen3_switch_t* p__root = nullptr);

	private:
		void _read ();
		void _clean_up ();

	public:
		~gen3_switch_t ();

	private:
		uint8_t m_hair_type;
		bool m_mole_enable;
		uint64_t m_body_height;
		bool m_hair_flip;
		uint64_t m_body_weight;
		uint8_t m_hair_color;
		bool m_gender;
		uint64_t m_eye_color;
		uint8_t m_eyebrow_color;
		uint8_t m_mouth_color;
		uint8_t m_facial_hair_color;
		uint8_t m_glasses_color;
		uint8_t m_eye_type;
		uint8_t m_mouth_type;
		uint64_t m_glasses_size;
		uint64_t m_eye_vertical;
		uint64_t m_facial_hair_mustache;
		uint64_t m_eyebrow_type;
		uint64_t m_facial_hair_beard;
		uint64_t m_nose_type;
		uint64_t m_mouth_stretch;
		uint64_t m_nose_vertical;
		uint64_t m_eyebrow_stretch;
		uint64_t m_mouth_vertical;
		uint64_t m_eye_rotation;
		uint64_t m_facial_hair_vertical;
		uint64_t m_eye_stretch;
		uint64_t m_glasses_vertical;
		uint64_t m_eye_size;
		uint64_t m_mole_horizontal;
		uint8_t m_mole_vertical;
		uint8_t m_glasses_type;
		uint64_t m_face_type;
		uint64_t m_favorite_color;
		uint64_t m_face_wrinkles;
		uint64_t m_face_color;
		uint64_t m_eye_horizontal;
		uint64_t m_face_makeup;
		uint64_t m_eyebrow_rotation;
		uint64_t m_eyebrow_size;
		uint64_t m_eyebrow_vertical;
		uint64_t m_eyebrow_horizontal;
		uint64_t m_mouth_size;
		uint64_t m_nose_size;
		uint64_t m_mole_size;
		uint64_t m_facial_hair_size;
		std::string m_mii_name;
		std::unique_ptr<std::vector<uint8_t>> m_unknown;
		std::unique_ptr<std::vector<uint8_t>> m_mii_id;
		gen3_switch_t* m__root;
		kaitai::kstruct* m__parent;

	public:
		/**
         * Hair type. Ranges from 0 to 131. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{hair}.
         */
		uint8_t hair_type () const {
			return m_hair_type;
		}

		/**
         * Enable mole. 0 = no, 1 = yes.
         */
		bool mole_enable () const {
			return m_mole_enable;
		}

		/**
         * Body height. Ranges from 0 to 127, short to tall. In the Mii editor, pressing right will add 1 to this value, and pressing left will subtract 1, allowing for precise editing.
         */
		uint64_t body_height () const {
			return m_body_height;
		}

		/**
         * Flip hair. 0 = no, 1 = yes.
         */
		bool hair_flip () const {
			return m_hair_flip;
		}

		/**
         * Body weight. Ranges from 0 to 127, small to large. In the Mii editor, pressing right will add 1 to this value, and pressing left will subtract 1, allowing for precise editing.
         */
		uint64_t body_weight () const {
			return m_body_weight;
		}

		/**
         * Hair color. Ranges from 0 to 99. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{hair-color} for default colors and /maps.txt/{colors} for custom colors.
         */
		uint8_t hair_color () const {
			return m_hair_color;
		}

		/**
         * Mii gender. 0 = male, 1 = female.
         */
		bool gender () const {
			return m_gender;
		}

		/**
         * Eye color. Ranges from 0 to 99. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{eye-color} for default colors and /maps.txt/{colors} for custom colors.
         */
		uint64_t eye_color () const {
			return m_eye_color;
		}

		/**
         * Eyebrow color. Ranges from 0 to 99. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{hair-color} for default colors and /maps.txt/{colors} for custom colors.
         */
		uint8_t eyebrow_color () const {
			return m_eyebrow_color;
		}

		/**
         * Mouth color. The default colors are ordered the same as visible in editor, ranging from 19 to 23. The custom colors are not and range from 0 to 99. A map of the internal values in correlation to the Mii editor is at /maps.txt/{colors} for custom colors.
         */
		uint8_t mouth_color () const {
			return m_mouth_color;
		}

		/**
         * Facial hair color. Ranges from 0 to 99. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{hair-color} for default colors and /maps.txt/{colors} for custom colors.
         */
		uint8_t facial_hair_color () const {
			return m_facial_hair_color;
		}

		/**
         * Glasses color. Ranges from 0 to 99. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{glasses-color} for default colors and /maps.txt/{colors} for custom colors.
         */
		uint8_t glasses_color () const {
			return m_glasses_color;
		}

		/**
         * Eye type. Ranges from 0 to 59. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{eyes}.
         */
		uint8_t eye_type () const {
			return m_eye_type;
		}

		/**
         * Mouth type. Ranges from 0 to 35. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{mouth}.
         */
		uint8_t mouth_type () const {
			return m_mouth_type;
		}

		/**
         * Glasses size. Ranges from 0 to 7, small to big.
         */
		uint64_t glasses_size () const {
			return m_glasses_size;
		}

		/**
         * Eye Y (vertical) position. Ranges from 24 to 0, low to high.
         */
		uint64_t eye_vertical () const {
			return m_eye_vertical;
		}

		/**
         * Mustache type. Ranges from 0 to 5.
         */
		uint64_t facial_hair_mustache () const {
			return m_facial_hair_mustache;
		}

		/**
         * Eyebrow type. Ranges from 0 to 23. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{eyebrows}.
         */
		uint64_t eyebrow_type () const {
			return m_eyebrow_type;
		}

		/**
         * Beard type. Ranges from 0 to 5.
         */
		uint64_t facial_hair_beard () const {
			return m_facial_hair_beard;
		}

		/**
         * Nose type. Ranges from 0 to 17. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{nose}.
         */
		uint64_t nose_type () const {
			return m_nose_type;
		}

		/**
         * Mouth stretch. Ranges from 0 to 6, small to big.
         */
		uint64_t mouth_stretch () const {
			return m_mouth_stretch;
		}

		/**
         * Nose Y (vertical) position. Ranges from 24 to 0, low to high.
         */
		uint64_t nose_vertical () const {
			return m_nose_vertical;
		}

		/**
         * Eyebrow stretch. Ranges from 0 to 6, small to big.
         */
		uint64_t eyebrow_stretch () const {
			return m_eyebrow_stretch;
		}

		/**
         * Mouth Y (vertical) position. Ranges from 24 to 0, low to high.
         */
		uint64_t mouth_vertical () const {
			return m_mouth_vertical;
		}

		/**
         * Eye rotation. Ranges from 0 to 7, down to up. Note that some eye types have a default rotation. You can find more specifics at /rotation.txt/{eyes}.
         */
		uint64_t eye_rotation () const {
			return m_eye_rotation;
		}

		/**
         * Mustache Y (vertical) position. Ranges from 22 to 0, low to high.
         */
		uint64_t facial_hair_vertical () const {
			return m_facial_hair_vertical;
		}

		/**
         * Eye stretch. Ranges from 0 to 6, small to big.
         */
		uint64_t eye_stretch () const {
			return m_eye_stretch;
		}

		/**
         * Glasses Y (vertical) position. Ranges from 20 to 0, low to high.
         */
		uint64_t glasses_vertical () const {
			return m_glasses_vertical;
		}

		/**
         * Eye size. Ranges from 0 to 7, small to big.
         */
		uint64_t eye_size () const {
			return m_eye_size;
		}

		/**
         * Mole X (horizontal) position. Ranges from 0 to 16, left to right.
         */
		uint64_t mole_horizontal () const {
			return m_mole_horizontal;
		}

		/**
         * Mole Y (vertical) position. Ranges from 30 to 0, low to high.
         */
		uint8_t mole_vertical () const {
			return m_mole_vertical;
		}

		/**
         * Glasses type. Ranges from 0 to 19. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{glasses}.
         */
		uint8_t glasses_type () const {
			return m_glasses_type;
		}

		/**
         * Face shape. Ranges from 0 to 11. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{face}.
         */
		uint64_t face_type () const {
			return m_face_type;
		}

		/**
         * Favorite color. Ranges from 0 to 11.
         */
		uint64_t favorite_color () const {
			return m_favorite_color;
		}

		/**
         * Face wrinkles. Ranges from 0 to 11.
         */
		uint64_t face_wrinkles () const {
			return m_face_wrinkles;
		}

		/**
         * Skin color. Ranges from 0 to 9. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{skin}.
         */
		uint64_t face_color () const {
			return m_face_color;
		}

		/**
         * Eye X (horizontal) distance. Ranges from 0 to 12, close to far.
         */
		uint64_t eye_horizontal () const {
			return m_eye_horizontal;
		}

		/**
         * Face makeup. Ranges from 0 to 11.
         */
		uint64_t face_makeup () const {
			return m_face_makeup;
		}

		/**
         * Eyebrow rotation. Ranges from 0 to 11, down to up. Note that some eye types have a default rotation. You can find more specifics at /rotation.txt/{eyebrows}.
         */
		uint64_t eyebrow_rotation () const {
			return m_eyebrow_rotation;
		}

		/**
         * Eyebrow size. Ranges from 0 to 8, small to big.
         */
		uint64_t eyebrow_size () const {
			return m_eyebrow_size;
		}

		/**
         * Eyebrow Y (vertical) position. Ranges from 15 to 0, low to high.
         */
		uint64_t eyebrow_vertical () const {
			return m_eyebrow_vertical;
		}

		/**
         * Eyebrow X (horizontal) distance. Ranges from 0 to 12, close to far.
         */
		uint64_t eyebrow_horizontal () const {
			return m_eyebrow_horizontal;
		}

		/**
         * Mouth size. Ranges from 0 to 8, small to big.
         */
		uint64_t mouth_size () const {
			return m_mouth_size;
		}

		/**
         * Nose size. Ranges from 0 to 8, small to big.
         */
		uint64_t nose_size () const {
			return m_nose_size;
		}

		/**
         * Mole size. Ranges from 0 to 8, small to big.
         */
		uint64_t mole_size () const {
			return m_mole_size;
		}

		/**
         * Mustache size. Ranges from 0 to 8, small to big.
         */
		uint64_t facial_hair_size () const {
			return m_facial_hair_size;
		}

		/**
         * Mii name. Can be up to 10 characters long.
         */
		std::string mii_name () const {
			return m_mii_name;
		}

		/**
         * Currently unknown data.
         */
		std::vector<uint8_t>* unknown () const {
			return m_unknown.get ();
		}

		/**
         * Mii ID. An identifier used to save Miis in most games.
         */
		std::vector<uint8_t>* mii_id () const {
			return m_mii_id.get ();
		}
		gen3_switch_t* _root () const {
			return m__root;
		}
		kaitai::kstruct* _parent () const {
			return m__parent;
		}
	};
}

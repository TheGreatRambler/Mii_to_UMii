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

	class gen3_switchgame_t : public kaitai::kstruct {

	public:
		gen3_switchgame_t (kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, gen3_switchgame_t* p__root = nullptr);

	private:
		void _read ();
		void _clean_up ();

	public:
		~gen3_switchgame_t ();

	private:
		std::unique_ptr<std::vector<uint8_t>> m_unknown_data;
		std::string m_mii_name;
		std::unique_ptr<std::vector<uint8_t>> m_unknown_buffer;
		uint8_t m_favorite_color;
		uint8_t m_gender;
		uint8_t m_body_height;
		uint8_t m_body_weight;
		std::unique_ptr<std::vector<uint8_t>> m_unknown_buffer2;
		uint8_t m_face_type;
		uint8_t m_face_color;
		uint8_t m_face_wrinkles;
		uint8_t m_face_makeup;
		uint8_t m_hair_type;
		uint8_t m_hair_color;
		uint8_t m_hair_flip;
		uint8_t m_eye_type;
		uint8_t m_eye_color;
		uint8_t m_eye_size;
		uint8_t m_eye_stretch;
		uint8_t m_eye_rotation;
		uint8_t m_eye_horizontal;
		uint8_t m_eye_vertical;
		uint8_t m_eyebrow_type;
		uint8_t m_eyebrow_color;
		uint8_t m_eyebrow_size;
		uint8_t m_eyebrow_stretch;
		uint8_t m_eyebrow_rotation;
		uint8_t m_eyebrow_horizontal;
		uint8_t m_eyebrow_vertical;
		uint8_t m_nose_type;
		uint8_t m_nose_size;
		uint8_t m_nose_vertical;
		uint8_t m_mouth_type;
		uint8_t m_mouth_color;
		uint8_t m_mouth_size;
		uint8_t m_mouth_stretch;
		uint8_t m_mouth_vertical;
		uint8_t m_facial_hair_color;
		uint8_t m_facial_hair_beard;
		uint8_t m_facial_hair_mustache;
		uint8_t m_facial_hair_size;
		uint8_t m_facial_hair_vertical;
		uint8_t m_glasses_type;
		uint8_t m_glasses_color;
		uint8_t m_glasses_size;
		uint8_t m_glasses_vertical;
		uint8_t m_mole_enable;
		uint8_t m_mole_size;
		uint8_t m_mole_horizontal;
		uint8_t m_mole_vertical;
		std::unique_ptr<std::vector<uint8_t>> m_unknown_buffer3;
		gen3_switchgame_t* m__root;
		kaitai::kstruct* m__parent;

	public:
		/**
         * Currently unknown data.
         */
		std::vector<uint8_t>* unknown_data () const {
			return m_unknown_data.get ();
		}

		/**
         * Mii name. Can be up to 10 characters long. Different from the Mii name that appears in Smash - in game, this is never seen.
         */
		std::string mii_name () const {
			return m_mii_name;
		}

		/**
         * Currently unknown data - likely a 00 buffer between the name and misc. info and the rest of the Mii data.
         */
		std::vector<uint8_t>* unknown_buffer () const {
			return m_unknown_buffer.get ();
		}

		/**
         * Favorite color. Ranges from 0 to 11.
         */
		uint8_t favorite_color () const {
			return m_favorite_color;
		}

		/**
         * Mii gender. 0 = male, 1 = female.
         */
		uint8_t gender () const {
			return m_gender;
		}

		/**
         * Body height. Ranges from 0 to 127, short to tall.
         */
		uint8_t body_height () const {
			return m_body_height;
		}

		/**
         * Body weight. Ranges from 0 to 127, small to large.
         */
		uint8_t body_weight () const {
			return m_body_weight;
		}

		/**
         * Currently unknown data - likely a 00 buffer between the Mii body data and the Mii face data.
         */
		std::vector<uint8_t>* unknown_buffer2 () const {
			return m_unknown_buffer2.get ();
		}

		/**
         * Face shape. Ranges from 0 to 11. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{face}.
         */
		uint8_t face_type () const {
			return m_face_type;
		}

		/**
         * Skin color. Ranges from 0 to 9. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{skin}.
         */
		uint8_t face_color () const {
			return m_face_color;
		}

		/**
         * Face wrinkles. Ranges from 0 to 11.
         */
		uint8_t face_wrinkles () const {
			return m_face_wrinkles;
		}

		/**
         * Face makeup. Ranges from 0 to 11.
         */
		uint8_t face_makeup () const {
			return m_face_makeup;
		}

		/**
         * Hair type. Ranges from 0 to 131. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{hair}.
         */
		uint8_t hair_type () const {
			return m_hair_type;
		}

		/**
         * Hair color. Ranges from 0 to 99. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{hair-color} for default colors and /maps.txt/{colors} for custom colors.
         */
		uint8_t hair_color () const {
			return m_hair_color;
		}

		/**
         * Flip hair. 0 = no, 1 = yes.
         */
		uint8_t hair_flip () const {
			return m_hair_flip;
		}

		/**
         * Eye type. Ranges from 0 to 59. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{eyes}.
         */
		uint8_t eye_type () const {
			return m_eye_type;
		}

		/**
         * Eye color. Ranges from 0 to 99. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{eye-color} for default colors and /maps.txt/{colors} for custom colors.
         */
		uint8_t eye_color () const {
			return m_eye_color;
		}

		/**
         * Eye size. Ranges from 0 to 7, small to large.
         */
		uint8_t eye_size () const {
			return m_eye_size;
		}

		/**
         * Eye stretch. Ranges from 0 to 6, small to large.
         */
		uint8_t eye_stretch () const {
			return m_eye_stretch;
		}

		/**
         * Eye rotation. Ranges from 0 to 7, down to up. Note that some eye types have a default rotation. You can find more specifics at /rotation.txt/{eyes}.
         */
		uint8_t eye_rotation () const {
			return m_eye_rotation;
		}

		/**
         * Eye X (horizontal) distance. Ranges from 0 to 12, close to far.
         */
		uint8_t eye_horizontal () const {
			return m_eye_horizontal;
		}

		/**
         * Eye Y (vertical) position. Ranges from 18 to 0, low to high.
         */
		uint8_t eye_vertical () const {
			return m_eye_vertical;
		}

		/**
         * Eyebrow type. Ranges from 0 to 23. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{eyebrows}.
         */
		uint8_t eyebrow_type () const {
			return m_eyebrow_type;
		}

		/**
         * Eyebrow color. Ranges from 0 to 99. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{hair-color} for default colors and /maps.txt/{colors} for custom colors.
         */
		uint8_t eyebrow_color () const {
			return m_eyebrow_color;
		}

		/**
         * Eyebrow size. Ranges from 0 to 8, small to large.
         */
		uint8_t eyebrow_size () const {
			return m_eyebrow_size;
		}

		/**
         * Eyebrow stretch. Ranges from 0 to 6, small to large.
         */
		uint8_t eyebrow_stretch () const {
			return m_eyebrow_stretch;
		}

		/**
         * Eyebrow rotation. Ranges from 0 to 11, down to up. Note that some eyebrow types have a default rotation. You can find more specifics at /rotation.txt/{eyebrows}.
         */
		uint8_t eyebrow_rotation () const {
			return m_eyebrow_rotation;
		}

		/**
         * Eyebrow X (horizontal) distance. Ranges from 0 to 12, close to far.
         */
		uint8_t eyebrow_horizontal () const {
			return m_eyebrow_horizontal;
		}

		/**
         * Eyebrow Y (vertical) distance. Ranges from 18 to 3, low to high.
         */
		uint8_t eyebrow_vertical () const {
			return m_eyebrow_vertical;
		}

		/**
         * Nose type. Ranges from 0 to 17. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{nose}.
         */
		uint8_t nose_type () const {
			return m_nose_type;
		}

		/**
         * Nose size. Ranges from 0 to 8, small to large.
         */
		uint8_t nose_size () const {
			return m_nose_size;
		}

		/**
         * Nose Y (vertical) position. Ranges from 18 to 0, low to high.
         */
		uint8_t nose_vertical () const {
			return m_nose_vertical;
		}

		/**
         * Mouth type. Ranges from 0 to 35. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{mouth}.
         */
		uint8_t mouth_type () const {
			return m_mouth_type;
		}

		/**
         * Mouth color. The default colors are ordered the same as visible in editor, ranging from 19 to 23. The custom colors are not and range from 0 to 99. A map of the internal values in correlation to the Mii editor is at /maps.txt/{colors} for custom colors.
         */
		uint8_t mouth_color () const {
			return m_mouth_color;
		}

		/**
         * Mouth size. Ranges from 0 to 8, small to large.
         */
		uint8_t mouth_size () const {
			return m_mouth_size;
		}

		/**
         * Mouth stretch. Ranges from 0 to 6, small to large.
         */
		uint8_t mouth_stretch () const {
			return m_mouth_stretch;
		}

		/**
         * Mouth Y (vertical) position. Ranges from 18 to 0, low to high.
         */
		uint8_t mouth_vertical () const {
			return m_mouth_vertical;
		}

		/**
         * Facial hair color. Ranges from 0 to 99. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{hair-color} for default colors and /maps.txt/{colors} for custom colors.
         */
		uint8_t facial_hair_color () const {
			return m_facial_hair_color;
		}

		/**
         * Beard type. Ranges from 0 to 5.
         */
		uint8_t facial_hair_beard () const {
			return m_facial_hair_beard;
		}

		/**
         * Mustache type. Ranges from 0 to 5.
         */
		uint8_t facial_hair_mustache () const {
			return m_facial_hair_mustache;
		}

		/**
         * Mustache size. Ranges from 0 to 8, small to large.
         */
		uint8_t facial_hair_size () const {
			return m_facial_hair_size;
		}

		/**
         * Mustache Y (vertical) position. Ranges from 16 to 0, low to high.
         */
		uint8_t facial_hair_vertical () const {
			return m_facial_hair_vertical;
		}

		/**
         * Glasses type. Ranges from 0 to 19. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{glasses}.
         */
		uint8_t glasses_type () const {
			return m_glasses_type;
		}

		/**
         * Glasses color. Ranges from 0 to 99. Not ordered the same as visible in editor. A map of the internal values in correlation to the Mii editor is at /maps.txt/{glasses-color} for default colors and /maps.txt/{colors} for custom colors.
         */
		uint8_t glasses_color () const {
			return m_glasses_color;
		}

		/**
         * Glasses size. Ranges from 0 to 7, small to large.
         */
		uint8_t glasses_size () const {
			return m_glasses_size;
		}

		/**
         * Glasses Y (vertical) position. Ranges from 20 to 0, low to high.
         */
		uint8_t glasses_vertical () const {
			return m_glasses_vertical;
		}

		/**
         * Enable mole. 0 = no, 1 = yes.
         */
		uint8_t mole_enable () const {
			return m_mole_enable;
		}

		/**
         * Mole size. Ranges from 0 to 8, small to large.
         */
		uint8_t mole_size () const {
			return m_mole_size;
		}

		/**
         * Mole X (horizontal) position. Ranges from 0 to 16, left to right.
         */
		uint8_t mole_horizontal () const {
			return m_mole_horizontal;
		}

		/**
         * Mole Y (vertical) position. Ranges from 30 to 0, low to high.
         */
		uint8_t mole_vertical () const {
			return m_mole_vertical;
		}

		/**
         * Currently unknown data - likely a 00 buffer between the Mii data and the Smash Ultimate data.
         */
		std::vector<uint8_t>* unknown_buffer3 () const {
			return m_unknown_buffer3.get ();
		}
		gen3_switchgame_t* _root () const {
			return m__root;
		}
		kaitai::kstruct* _parent () const {
			return m__parent;
		}
	};
}

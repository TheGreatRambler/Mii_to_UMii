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

	class gen2_wiiu_3ds_miitomo_t : public kaitai::kstruct {

	public:
		gen2_wiiu_3ds_miitomo_t (kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, gen2_wiiu_3ds_miitomo_t* p__root = nullptr);

	private:
		void _read ();
		void _clean_up ();

	public:
		~gen2_wiiu_3ds_miitomo_t ();

	private:
		bool f_glasses_color;
		int32_t m_glasses_color;

	public:
		int32_t glasses_color ();

	private:
		bool f_eyebrow_horizontal;
		int32_t m_eyebrow_horizontal;

	public:
		int32_t eyebrow_horizontal ();

	private:
		bool f_eye_vertical;
		int32_t m_eye_vertical;

	public:
		int32_t eye_vertical ();

	private:
		bool f_facial_hair_beard;
		int32_t m_facial_hair_beard;

	public:
		int32_t facial_hair_beard ();

	private:
		bool f_mouth_size;
		int32_t m_mouth_size;

	public:
		int32_t mouth_size ();

	private:
		bool f_eyebrow_stretch;
		int32_t m_eyebrow_stretch;

	public:
		int32_t eyebrow_stretch ();

	private:
		bool f_nose_vertical;
		int32_t m_nose_vertical;

	public:
		int32_t nose_vertical ();

	private:
		bool f_eye_color;
		int32_t m_eye_color;

	public:
		int32_t eye_color ();

	private:
		bool f_birth_month;
		int32_t m_birth_month;

	public:
		int32_t birth_month ();

	private:
		bool f_mouth_color;
		int32_t m_mouth_color;

	public:
		int32_t mouth_color ();

	private:
		bool f_mole_horizontal;
		int32_t m_mole_horizontal;

	public:
		int32_t mole_horizontal ();

	private:
		bool f_facial_hair_mustache;
		int32_t m_facial_hair_mustache;

	public:
		int32_t facial_hair_mustache ();

	private:
		bool f_eyebrow_rotation;
		int32_t m_eyebrow_rotation;

	public:
		int32_t eyebrow_rotation ();

	private:
		bool f_mole_vertical;
		int32_t m_mole_vertical;

	public:
		int32_t mole_vertical ();

	private:
		bool f_glasses_type;
		int32_t m_glasses_type;

	public:
		int32_t glasses_type ();

	private:
		bool f_eyebrow_size;
		int32_t m_eyebrow_size;

	public:
		int32_t eyebrow_size ();

	private:
		bool f_mole_size;
		int32_t m_mole_size;

	public:
		int32_t mole_size ();

	private:
		bool f_nose_size;
		int32_t m_nose_size;

	public:
		int32_t nose_size ();

	private:
		bool f_facial_hair_vertical;
		int32_t m_facial_hair_vertical;

	public:
		int32_t facial_hair_vertical ();

	private:
		bool f_eye_stretch;
		int32_t m_eye_stretch;

	public:
		int32_t eye_stretch ();

	private:
		bool f_eye_size;
		int32_t m_eye_size;

	public:
		int32_t eye_size ();

	private:
		bool f_eye_type;
		int32_t m_eye_type;

	public:
		int32_t eye_type ();

	private:
		bool f_eye_horizontal;
		int32_t m_eye_horizontal;

	public:
		int32_t eye_horizontal ();

	private:
		bool f_eyebrow_type;
		int32_t m_eyebrow_type;

	public:
		int32_t eyebrow_type ();

	private:
		bool f_mouth_vertical;
		int32_t m_mouth_vertical;

	public:
		int32_t mouth_vertical ();

	private:
		bool f_eyebrow_color;
		int32_t m_eyebrow_color;

	public:
		int32_t eyebrow_color ();

	private:
		bool f_nose_type;
		int32_t m_nose_type;

	public:
		int32_t nose_type ();

	private:
		bool f_facial_hair_color;
		int32_t m_facial_hair_color;

	public:
		int32_t facial_hair_color ();

	private:
		bool f_eyebrow_vertical;
		int32_t m_eyebrow_vertical;

	public:
		int32_t eyebrow_vertical ();

	private:
		bool f_glasses_size;
		int32_t m_glasses_size;

	public:
		int32_t glasses_size ();

	private:
		bool f_eye_rotation;
		int32_t m_eye_rotation;

	public:
		int32_t eye_rotation ();

	private:
		bool f_gender;
		int32_t m_gender;

	public:
		int32_t gender ();

	private:
		bool f_birth_day;
		int32_t m_birth_day;

	public:
		int32_t birth_day ();

	private:
		bool f_mouth_stretch;
		int32_t m_mouth_stretch;

	public:
		int32_t mouth_stretch ();

	private:
		bool f_mole_enable;
		int32_t m_mole_enable;

	public:
		int32_t mole_enable ();

	private:
		bool f_favorite;
		int32_t m_favorite;

	public:
		int32_t favorite ();

	private:
		bool f_glasses_vertical;
		int32_t m_glasses_vertical;

	public:
		int32_t glasses_vertical ();

	private:
		bool f_favorite_color;
		int32_t m_favorite_color;

	public:
		int32_t favorite_color ();

	private:
		bool f_mouth_type;
		int32_t m_mouth_type;

	public:
		int32_t mouth_type ();

	private:
		bool f_facial_hair_size;
		int32_t m_facial_hair_size;

	public:
		int32_t facial_hair_size ();

	private:
		uint8_t m_unknown_1;
		uint64_t m_character_set;
		uint64_t m_region_lock;
		bool m_profanity_flag;
		bool m_copying;
		uint64_t m_unknown_2;
		uint64_t m_mii_position_slot_index;
		uint64_t m_mii_position_page_index;
		uint64_t m_version;
		uint64_t m_unknown_3;
		std::unique_ptr<std::vector<uint8_t>> m_system_id;
		std::unique_ptr<std::vector<uint8_t>> m_avatar_id;
		std::unique_ptr<std::vector<uint8_t>> m_client_id;
		uint16_t m_padding;
		uint16_t m_data_1;
		std::string m_mii_name;
		uint8_t m_body_height;
		uint8_t m_body_weight;
		uint64_t m_face_color;
		uint64_t m_face_type;
		bool m_mingle;
		uint64_t m_face_makeup;
		uint64_t m_face_wrinkles;
		uint8_t m_hair_type;
		uint64_t m_unknown_5;
		bool m_hair_flip;
		uint64_t m_hair_color;
		uint32_t m_eye;
		uint32_t m_eyebrow;
		uint16_t m_nose;
		uint16_t m_mouth;
		uint16_t m_mouth2;
		uint16_t m_beard;
		uint16_t m_glasses;
		uint16_t m_mole;
		std::string m_creator_name;
		uint16_t m_padding2;
		uint16_t m_checksum;
		gen2_wiiu_3ds_miitomo_t* m__root;
		kaitai::kstruct* m__parent;

	public:
		/**
         * Always 3?
         */
		uint8_t unknown_1 () const {
			return m_unknown_1;
		}

		/**
         * 0=JPN+USA+EUR, 1=CHN, 2=KOR, 3=TWN
         */
		uint64_t character_set () const {
			return m_character_set;
		}

		/**
         * 0=no lock, 1=JPN, 2=USA, 3=EUR
         */
		uint64_t region_lock () const {
			return m_region_lock;
		}
		bool profanity_flag () const {
			return m_profanity_flag;
		}
		bool copying () const {
			return m_copying;
		}
		uint64_t unknown_2 () const {
			return m_unknown_2;
		}
		uint64_t mii_position_slot_index () const {
			return m_mii_position_slot_index;
		}
		uint64_t mii_position_page_index () const {
			return m_mii_position_page_index;
		}
		uint64_t version () const {
			return m_version;
		}
		uint64_t unknown_3 () const {
			return m_unknown_3;
		}
		std::vector<uint8_t>* system_id () const {
			return m_system_id.get ();
		}
		std::vector<uint8_t>* avatar_id () const {
			return m_avatar_id.get ();
		}
		std::vector<uint8_t>* client_id () const {
			return m_client_id.get ();
		}
		uint16_t padding () const {
			return m_padding;
		}
		uint16_t data_1 () const {
			return m_data_1;
		}
		std::string mii_name () const {
			return m_mii_name;
		}
		uint8_t body_height () const {
			return m_body_height;
		}
		uint8_t body_weight () const {
			return m_body_weight;
		}
		uint64_t face_color () const {
			return m_face_color;
		}
		uint64_t face_type () const {
			return m_face_type;
		}
		bool mingle () const {
			return m_mingle;
		}
		uint64_t face_makeup () const {
			return m_face_makeup;
		}
		uint64_t face_wrinkles () const {
			return m_face_wrinkles;
		}
		uint8_t hair_type () const {
			return m_hair_type;
		}
		uint64_t unknown_5 () const {
			return m_unknown_5;
		}
		bool hair_flip () const {
			return m_hair_flip;
		}
		uint64_t hair_color () const {
			return m_hair_color;
		}
		uint32_t eye () const {
			return m_eye;
		}
		uint32_t eyebrow () const {
			return m_eyebrow;
		}
		uint16_t nose () const {
			return m_nose;
		}
		uint16_t mouth () const {
			return m_mouth;
		}
		uint16_t mouth2 () const {
			return m_mouth2;
		}
		uint16_t beard () const {
			return m_beard;
		}
		uint16_t glasses () const {
			return m_glasses;
		}
		uint16_t mole () const {
			return m_mole;
		}
		std::string creator_name () const {
			return m_creator_name;
		}
		uint16_t padding2 () const {
			return m_padding2;
		}
		uint16_t checksum () const {
			return m_checksum;
		}
		gen2_wiiu_3ds_miitomo_t* _root () const {
			return m__root;
		}
		kaitai::kstruct* _parent () const {
			return m__parent;
		}
	};
}

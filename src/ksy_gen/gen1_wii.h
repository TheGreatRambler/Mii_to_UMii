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

	class gen1_wii_t : public kaitai::kstruct {

	public:
		gen1_wii_t (kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, gen1_wii_t* p__root = nullptr);

	private:
		void _read ();
		void _clean_up ();

	public:
		~gen1_wii_t ();

	private:
		bool m_invalid;
		bool m_gender;
		uint64_t m_birth_month;
		uint64_t m_birth_day;
		uint64_t m_favorite_color;
		bool m_favorite;
		std::string m_mii_name;
		uint8_t m_body_height;
		uint8_t m_body_weight;
		std::unique_ptr<std::vector<uint8_t>> m_avatar_id;
		std::unique_ptr<std::vector<uint8_t>> m_client_id;
		uint64_t m_face_type;
		uint64_t m_face_color;
		uint64_t m_facial_feature;
		uint64_t m_unknown;
		bool m_mingle;
		bool m_unknown_2;
		bool m_downloaded;
		uint64_t m_hair_type;
		uint64_t m_hair_color;
		bool m_hair_flip;
		uint64_t m_unknown_3;
		uint64_t m_eyebrow_type;
		bool m_unknown_4;
		uint64_t m_eyebrow_rotation;
		uint64_t m_unknown_5;
		uint64_t m_eyebrow_color;
		uint64_t m_eyebrow_size;
		uint64_t m_eyebrow_vertical;
		uint64_t m_eyebrow_horizontal;
		uint64_t m_eye_type;
		uint64_t m_unknown_6;
		uint64_t m_eye_rotation;
		uint64_t m_eye_vertical;
		uint64_t m_eye_color;
		bool m_unknown_7;
		uint64_t m_eye_size;
		uint64_t m_eye_horizontal;
		uint64_t m_unknown_8;
		uint64_t m_nose_type;
		uint64_t m_nose_size;
		uint64_t m_nose_vertical;
		uint64_t m_unknown_9;
		uint64_t m_mouth_type;
		uint64_t m_mouth_color;
		uint64_t m_mouth_size;
		uint64_t m_mouth_vertical;
		uint64_t m_glasses_type;
		uint64_t m_glasses_color;
		bool m_unknown_10;
		uint64_t m_glasses_size;
		uint64_t m_glasses_vertical;
		uint64_t m_facial_hair_mustache;
		uint64_t m_facial_hair_beard;
		uint64_t m_facial_hair_color;
		uint64_t m_facial_hair_size;
		uint64_t m_facial_hair_vertical;
		bool m_mole_enable;
		uint64_t m_mole_size;
		uint64_t m_mole_vertical;
		uint64_t m_mole_horizontal;
		bool m_unknown_11;
		std::string m_creator_name;
		gen1_wii_t* m__root;
		kaitai::kstruct* m__parent;

	public:
		bool invalid () const {
			return m_invalid;
		}
		bool gender () const {
			return m_gender;
		}
		uint64_t birth_month () const {
			return m_birth_month;
		}
		uint64_t birth_day () const {
			return m_birth_day;
		}
		uint64_t favorite_color () const {
			return m_favorite_color;
		}
		bool favorite () const {
			return m_favorite;
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
		std::vector<uint8_t>* avatar_id () const {
			return m_avatar_id.get ();
		}
		std::vector<uint8_t>* client_id () const {
			return m_client_id.get ();
		}
		uint64_t face_type () const {
			return m_face_type;
		}
		uint64_t face_color () const {
			return m_face_color;
		}
		uint64_t facial_feature () const {
			return m_facial_feature;
		}
		uint64_t unknown () const {
			return m_unknown;
		}
		bool mingle () const {
			return m_mingle;
		}
		bool unknown_2 () const {
			return m_unknown_2;
		}
		bool downloaded () const {
			return m_downloaded;
		}
		uint64_t hair_type () const {
			return m_hair_type;
		}
		uint64_t hair_color () const {
			return m_hair_color;
		}
		bool hair_flip () const {
			return m_hair_flip;
		}
		uint64_t unknown_3 () const {
			return m_unknown_3;
		}
		uint64_t eyebrow_type () const {
			return m_eyebrow_type;
		}
		bool unknown_4 () const {
			return m_unknown_4;
		}
		uint64_t eyebrow_rotation () const {
			return m_eyebrow_rotation;
		}
		uint64_t unknown_5 () const {
			return m_unknown_5;
		}
		uint64_t eyebrow_color () const {
			return m_eyebrow_color;
		}
		uint64_t eyebrow_size () const {
			return m_eyebrow_size;
		}
		uint64_t eyebrow_vertical () const {
			return m_eyebrow_vertical;
		}
		uint64_t eyebrow_horizontal () const {
			return m_eyebrow_horizontal;
		}
		uint64_t eye_type () const {
			return m_eye_type;
		}
		uint64_t unknown_6 () const {
			return m_unknown_6;
		}
		uint64_t eye_rotation () const {
			return m_eye_rotation;
		}
		uint64_t eye_vertical () const {
			return m_eye_vertical;
		}
		uint64_t eye_color () const {
			return m_eye_color;
		}
		bool unknown_7 () const {
			return m_unknown_7;
		}
		uint64_t eye_size () const {
			return m_eye_size;
		}
		uint64_t eye_horizontal () const {
			return m_eye_horizontal;
		}
		uint64_t unknown_8 () const {
			return m_unknown_8;
		}
		uint64_t nose_type () const {
			return m_nose_type;
		}
		uint64_t nose_size () const {
			return m_nose_size;
		}
		uint64_t nose_vertical () const {
			return m_nose_vertical;
		}
		uint64_t unknown_9 () const {
			return m_unknown_9;
		}
		uint64_t mouth_type () const {
			return m_mouth_type;
		}
		uint64_t mouth_color () const {
			return m_mouth_color;
		}
		uint64_t mouth_size () const {
			return m_mouth_size;
		}
		uint64_t mouth_vertical () const {
			return m_mouth_vertical;
		}
		uint64_t glasses_type () const {
			return m_glasses_type;
		}
		uint64_t glasses_color () const {
			return m_glasses_color;
		}
		bool unknown_10 () const {
			return m_unknown_10;
		}
		uint64_t glasses_size () const {
			return m_glasses_size;
		}
		uint64_t glasses_vertical () const {
			return m_glasses_vertical;
		}
		uint64_t facial_hair_mustache () const {
			return m_facial_hair_mustache;
		}
		uint64_t facial_hair_beard () const {
			return m_facial_hair_beard;
		}
		uint64_t facial_hair_color () const {
			return m_facial_hair_color;
		}
		uint64_t facial_hair_size () const {
			return m_facial_hair_size;
		}
		uint64_t facial_hair_vertical () const {
			return m_facial_hair_vertical;
		}
		bool mole_enable () const {
			return m_mole_enable;
		}
		uint64_t mole_size () const {
			return m_mole_size;
		}
		uint64_t mole_vertical () const {
			return m_mole_vertical;
		}
		uint64_t mole_horizontal () const {
			return m_mole_horizontal;
		}
		bool unknown_11 () const {
			return m_unknown_11;
		}
		std::string creator_name () const {
			return m_creator_name;
		}
		gen1_wii_t* _root () const {
			return m__root;
		}
		kaitai::kstruct* _parent () const {
			return m__parent;
		}
	};
}

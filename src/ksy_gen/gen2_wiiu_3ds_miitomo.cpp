// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "gen2_wiiu_3ds_miitomo.h"
namespace Kaitai {

	gen2_wiiu_3ds_miitomo_t::gen2_wiiu_3ds_miitomo_t (kaitai::kstream* p__io, kaitai::kstruct* p__parent, gen2_wiiu_3ds_miitomo_t* p__root)
		: kaitai::kstruct (p__io) {
		m__parent              = p__parent;
		m__root                = this;
		m_system_id            = nullptr;
		m_avatar_id            = nullptr;
		m_client_id            = nullptr;
		f_glasses_color        = false;
		f_eyebrow_horizontal   = false;
		f_eye_vertical         = false;
		f_facial_hair_beard    = false;
		f_mouth_size           = false;
		f_eyebrow_stretch      = false;
		f_nose_vertical        = false;
		f_eye_color            = false;
		f_birth_month          = false;
		f_mouth_color          = false;
		f_mole_horizontal      = false;
		f_facial_hair_mustache = false;
		f_eyebrow_rotation     = false;
		f_mole_vertical        = false;
		f_glasses_type         = false;
		f_eyebrow_size         = false;
		f_mole_size            = false;
		f_nose_size            = false;
		f_facial_hair_vertical = false;
		f_eye_stretch          = false;
		f_eye_size             = false;
		f_eye_type             = false;
		f_eye_horizontal       = false;
		f_eyebrow_type         = false;
		f_mouth_vertical       = false;
		f_eyebrow_color        = false;
		f_nose_type            = false;
		f_facial_hair_color    = false;
		f_eyebrow_vertical     = false;
		f_glasses_size         = false;
		f_eye_rotation         = false;
		f_gender               = false;
		f_birth_day            = false;
		f_mouth_stretch        = false;
		f_mole_enable          = false;
		f_favorite             = false;
		f_glasses_vertical     = false;
		f_favorite_color       = false;
		f_mouth_type           = false;
		f_facial_hair_size     = false;
		_read ();
	}

	void gen2_wiiu_3ds_miitomo_t::_read () {
		m_unknown_1               = m__io->read_u1 ();
		m_character_set           = m__io->read_bits_int_be (2);
		m_region_lock             = m__io->read_bits_int_be (2);
		m_profanity_flag          = m__io->read_bits_int_be (1);
		m_copying                 = m__io->read_bits_int_be (1);
		m_unknown_2               = m__io->read_bits_int_be (2);
		m_mii_position_slot_index = m__io->read_bits_int_be (4);
		m_mii_position_page_index = m__io->read_bits_int_be (4);
		m_version                 = m__io->read_bits_int_be (4);
		m_unknown_3               = m__io->read_bits_int_be (4);
		m__io->align_to_byte ();
		int l_system_id = 8;
		m_system_id     = std::unique_ptr<std::vector<uint8_t>> (new std::vector<uint8_t> ());
		m_system_id->reserve (l_system_id);
		for (int i = 0; i < l_system_id; i++) {
			m_system_id->push_back (std::move (m__io->read_u1 ()));
		}
		int l_avatar_id = 4;
		m_avatar_id     = std::unique_ptr<std::vector<uint8_t>> (new std::vector<uint8_t> ());
		m_avatar_id->reserve (l_avatar_id);
		for (int i = 0; i < l_avatar_id; i++) {
			m_avatar_id->push_back (std::move (m__io->read_u1 ()));
		}
		int l_client_id = 6;
		m_client_id     = std::unique_ptr<std::vector<uint8_t>> (new std::vector<uint8_t> ());
		m_client_id->reserve (l_client_id);
		for (int i = 0; i < l_client_id; i++) {
			m_client_id->push_back (std::move (m__io->read_u1 ()));
		}
		m_padding       = m__io->read_u2le ();
		m_data_1        = m__io->read_u2le ();
		m_mii_name      = kaitai::kstream::bytes_to_str (m__io->read_bytes (20), std::string ("utf-16le"));
		m_body_height   = m__io->read_u1 ();
		m_body_weight   = m__io->read_u1 ();
		m_face_color    = m__io->read_bits_int_be (3);
		m_face_type     = m__io->read_bits_int_be (4);
		m_mingle        = m__io->read_bits_int_be (1);
		m_face_makeup   = m__io->read_bits_int_be (4);
		m_face_wrinkles = m__io->read_bits_int_be (4);
		m__io->align_to_byte ();
		m_hair_type  = m__io->read_u1 ();
		m_unknown_5  = m__io->read_bits_int_be (4);
		m_hair_flip  = m__io->read_bits_int_be (1);
		m_hair_color = m__io->read_bits_int_be (3);
		m__io->align_to_byte ();
		m_eye          = m__io->read_u4le ();
		m_eyebrow      = m__io->read_u4le ();
		m_nose         = m__io->read_u2le ();
		m_mouth        = m__io->read_u2le ();
		m_mouth2       = m__io->read_u2le ();
		m_beard        = m__io->read_u2le ();
		m_glasses      = m__io->read_u2le ();
		m_mole         = m__io->read_u2le ();
		m_creator_name = kaitai::kstream::bytes_to_str (m__io->read_bytes (20), std::string ("utf-16le"));
		m_padding2     = m__io->read_u2le ();
		m_checksum     = m__io->read_u2le ();
	}

	gen2_wiiu_3ds_miitomo_t::~gen2_wiiu_3ds_miitomo_t () {
		_clean_up ();
	}

	void gen2_wiiu_3ds_miitomo_t::_clean_up () {
	}

	int32_t gen2_wiiu_3ds_miitomo_t::glasses_color () {
		if (f_glasses_color)
			return m_glasses_color;
		m_glasses_color = ((glasses () >> 4) & 7);
		f_glasses_color = true;
		return m_glasses_color;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::eyebrow_horizontal () {
		if (f_eyebrow_horizontal)
			return m_eyebrow_horizontal;
		m_eyebrow_horizontal = ((eyebrow () >> 21) & 15);
		f_eyebrow_horizontal = true;
		return m_eyebrow_horizontal;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::eye_vertical () {
		if (f_eye_vertical)
			return m_eye_vertical;
		m_eye_vertical = ((eye () >> 25) & 31);
		f_eye_vertical = true;
		return m_eye_vertical;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::facial_hair_beard () {
		if (f_facial_hair_beard)
			return m_facial_hair_beard;
		m_facial_hair_beard = (beard () & 7);
		f_facial_hair_beard = true;
		return m_facial_hair_beard;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::mouth_size () {
		if (f_mouth_size)
			return m_mouth_size;
		m_mouth_size = ((mouth () >> 9) & 15);
		f_mouth_size = true;
		return m_mouth_size;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::eyebrow_stretch () {
		if (f_eyebrow_stretch)
			return m_eyebrow_stretch;
		m_eyebrow_stretch = ((eyebrow () >> 12) & 7);
		f_eyebrow_stretch = true;
		return m_eyebrow_stretch;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::nose_vertical () {
		if (f_nose_vertical)
			return m_nose_vertical;
		m_nose_vertical = ((nose () >> 9) & 31);
		f_nose_vertical = true;
		return m_nose_vertical;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::eye_color () {
		if (f_eye_color)
			return m_eye_color;
		m_eye_color = ((eye () >> 6) & 7);
		f_eye_color = true;
		return m_eye_color;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::birth_month () {
		if (f_birth_month)
			return m_birth_month;
		m_birth_month = ((data_1 () >> 1) & 15);
		f_birth_month = true;
		return m_birth_month;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::mouth_color () {
		if (f_mouth_color)
			return m_mouth_color;
		m_mouth_color = ((mouth () >> 6) & 7);
		f_mouth_color = true;
		return m_mouth_color;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::mole_horizontal () {
		if (f_mole_horizontal)
			return m_mole_horizontal;
		m_mole_horizontal = ((mole () >> 5) & 31);
		f_mole_horizontal = true;
		return m_mole_horizontal;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::facial_hair_mustache () {
		if (f_facial_hair_mustache)
			return m_facial_hair_mustache;
		m_facial_hair_mustache = ((mouth2 () >> 5) & 7);
		f_facial_hair_mustache = true;
		return m_facial_hair_mustache;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::eyebrow_rotation () {
		if (f_eyebrow_rotation)
			return m_eyebrow_rotation;
		m_eyebrow_rotation = ((eyebrow () >> 16) & 15);
		f_eyebrow_rotation = true;
		return m_eyebrow_rotation;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::mole_vertical () {
		if (f_mole_vertical)
			return m_mole_vertical;
		m_mole_vertical = ((mole () >> 10) & 31);
		f_mole_vertical = true;
		return m_mole_vertical;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::glasses_type () {
		if (f_glasses_type)
			return m_glasses_type;
		m_glasses_type = (glasses () & 15);
		f_glasses_type = true;
		return m_glasses_type;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::eyebrow_size () {
		if (f_eyebrow_size)
			return m_eyebrow_size;
		m_eyebrow_size = ((eyebrow () >> 8) & 15);
		f_eyebrow_size = true;
		return m_eyebrow_size;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::mole_size () {
		if (f_mole_size)
			return m_mole_size;
		m_mole_size = ((mole () >> 1) & 15);
		f_mole_size = true;
		return m_mole_size;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::nose_size () {
		if (f_nose_size)
			return m_nose_size;
		m_nose_size = ((nose () >> 5) & 15);
		f_nose_size = true;
		return m_nose_size;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::facial_hair_vertical () {
		if (f_facial_hair_vertical)
			return m_facial_hair_vertical;
		m_facial_hair_vertical = ((beard () >> 10) & 31);
		f_facial_hair_vertical = true;
		return m_facial_hair_vertical;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::eye_stretch () {
		if (f_eye_stretch)
			return m_eye_stretch;
		m_eye_stretch = ((eye () >> 13) & 7);
		f_eye_stretch = true;
		return m_eye_stretch;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::eye_size () {
		if (f_eye_size)
			return m_eye_size;
		m_eye_size = ((eye () >> 9) & 7);
		f_eye_size = true;
		return m_eye_size;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::eye_type () {
		if (f_eye_type)
			return m_eye_type;
		m_eye_type = (eye () & 63);
		f_eye_type = true;
		return m_eye_type;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::eye_horizontal () {
		if (f_eye_horizontal)
			return m_eye_horizontal;
		m_eye_horizontal = ((eye () >> 21) & 15);
		f_eye_horizontal = true;
		return m_eye_horizontal;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::eyebrow_type () {
		if (f_eyebrow_type)
			return m_eyebrow_type;
		m_eyebrow_type = (eyebrow () & 31);
		f_eyebrow_type = true;
		return m_eyebrow_type;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::mouth_vertical () {
		if (f_mouth_vertical)
			return m_mouth_vertical;
		m_mouth_vertical = (mouth2 () & 31);
		f_mouth_vertical = true;
		return m_mouth_vertical;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::eyebrow_color () {
		if (f_eyebrow_color)
			return m_eyebrow_color;
		m_eyebrow_color = ((eyebrow () >> 5) & 7);
		f_eyebrow_color = true;
		return m_eyebrow_color;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::nose_type () {
		if (f_nose_type)
			return m_nose_type;
		m_nose_type = (nose () & 31);
		f_nose_type = true;
		return m_nose_type;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::facial_hair_color () {
		if (f_facial_hair_color)
			return m_facial_hair_color;
		m_facial_hair_color = ((beard () >> 3) & 7);
		f_facial_hair_color = true;
		return m_facial_hair_color;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::eyebrow_vertical () {
		if (f_eyebrow_vertical)
			return m_eyebrow_vertical;
		m_eyebrow_vertical = ((eyebrow () >> 25) & 31);
		f_eyebrow_vertical = true;
		return m_eyebrow_vertical;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::glasses_size () {
		if (f_glasses_size)
			return m_glasses_size;
		m_glasses_size = ((glasses () >> 7) & 15);
		f_glasses_size = true;
		return m_glasses_size;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::eye_rotation () {
		if (f_eye_rotation)
			return m_eye_rotation;
		m_eye_rotation = ((eye () >> 16) & 31);
		f_eye_rotation = true;
		return m_eye_rotation;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::gender () {
		if (f_gender)
			return m_gender;
		m_gender = (data_1 () & 1);
		f_gender = true;
		return m_gender;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::birth_day () {
		if (f_birth_day)
			return m_birth_day;
		m_birth_day = ((data_1 () >> 5) & 31);
		f_birth_day = true;
		return m_birth_day;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::mouth_stretch () {
		if (f_mouth_stretch)
			return m_mouth_stretch;
		m_mouth_stretch = ((mouth () >> 13) & 7);
		f_mouth_stretch = true;
		return m_mouth_stretch;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::mole_enable () {
		if (f_mole_enable)
			return m_mole_enable;
		m_mole_enable = (mole () >> 15);
		f_mole_enable = true;
		return m_mole_enable;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::favorite () {
		if (f_favorite)
			return m_favorite;
		m_favorite = ((data_1 () >> 14) & 1);
		f_favorite = true;
		return m_favorite;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::glasses_vertical () {
		if (f_glasses_vertical)
			return m_glasses_vertical;
		m_glasses_vertical = ((glasses () >> 11) & 15);
		f_glasses_vertical = true;
		return m_glasses_vertical;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::favorite_color () {
		if (f_favorite_color)
			return m_favorite_color;
		m_favorite_color = ((data_1 () >> 10) & 15);
		f_favorite_color = true;
		return m_favorite_color;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::mouth_type () {
		if (f_mouth_type)
			return m_mouth_type;
		m_mouth_type = (mouth () & 63);
		f_mouth_type = true;
		return m_mouth_type;
	}

	int32_t gen2_wiiu_3ds_miitomo_t::facial_hair_size () {
		if (f_facial_hair_size)
			return m_facial_hair_size;
		m_facial_hair_size = ((beard () >> 6) & 15);
		f_facial_hair_size = true;
		return m_facial_hair_size;
	}
}

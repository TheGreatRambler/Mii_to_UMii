// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "gen3_switch.h"
namespace Kaitai {

	gen3_switch_t::gen3_switch_t (kaitai::kstream* p__io, kaitai::kstruct* p__parent, gen3_switch_t* p__root)
		: kaitai::kstruct (p__io) {
		m__parent = p__parent;
		m__root   = this;
		m_unknown = nullptr;
		m_mii_id  = nullptr;
		_read ();
	}

	void gen3_switch_t::_read () {
		m_hair_type   = m__io->read_u1 ();
		m_mole_enable = m__io->read_bits_int_be (1);
		m_body_height = m__io->read_bits_int_be (7);
		m_hair_flip   = m__io->read_bits_int_be (1);
		m_body_weight = m__io->read_bits_int_be (7);
		m__io->align_to_byte ();
		m_hair_color = m__io->read_u1 ();
		m_gender     = m__io->read_bits_int_be (1);
		m_eye_color  = m__io->read_bits_int_be (7);
		m__io->align_to_byte ();
		m_eyebrow_color        = m__io->read_u1 ();
		m_mouth_color          = m__io->read_u1 ();
		m_facial_hair_color    = m__io->read_u1 ();
		m_glasses_color        = m__io->read_u1 ();
		m_eye_type             = m__io->read_u1 ();
		m_mouth_type           = m__io->read_u1 ();
		m_glasses_size         = m__io->read_bits_int_be (3);
		m_eye_vertical         = m__io->read_bits_int_be (5);
		m_facial_hair_mustache = m__io->read_bits_int_be (3);
		m_eyebrow_type         = m__io->read_bits_int_be (5);
		m_facial_hair_beard    = m__io->read_bits_int_be (3);
		m_nose_type            = m__io->read_bits_int_be (5);
		m_mouth_stretch        = m__io->read_bits_int_be (3);
		m_nose_vertical        = m__io->read_bits_int_be (5);
		m_eyebrow_stretch      = m__io->read_bits_int_be (3);
		m_mouth_vertical       = m__io->read_bits_int_be (5);
		m_eye_rotation         = m__io->read_bits_int_be (3);
		m_facial_hair_vertical = m__io->read_bits_int_be (5);
		m_eye_stretch          = m__io->read_bits_int_be (3);
		m_glasses_vertical     = m__io->read_bits_int_be (5);
		m_eye_size             = m__io->read_bits_int_be (3);
		m_mole_horizontal      = m__io->read_bits_int_be (5);
		m__io->align_to_byte ();
		m_mole_vertical      = m__io->read_u1 ();
		m_glasses_type       = m__io->read_u1 ();
		m_face_type          = m__io->read_bits_int_be (4);
		m_favorite_color     = m__io->read_bits_int_be (4);
		m_face_wrinkles      = m__io->read_bits_int_be (4);
		m_face_color         = m__io->read_bits_int_be (4);
		m_eye_horizontal     = m__io->read_bits_int_be (4);
		m_face_makeup        = m__io->read_bits_int_be (4);
		m_eyebrow_rotation   = m__io->read_bits_int_be (4);
		m_eyebrow_size       = m__io->read_bits_int_be (4);
		m_eyebrow_vertical   = m__io->read_bits_int_be (4);
		m_eyebrow_horizontal = m__io->read_bits_int_be (4);
		m_mouth_size         = m__io->read_bits_int_be (4);
		m_nose_size          = m__io->read_bits_int_be (4);
		m_mole_size          = m__io->read_bits_int_be (4);
		m_facial_hair_size   = m__io->read_bits_int_be (4);
		m__io->align_to_byte ();
		m_mii_name    = kaitai::kstream::bytes_to_str (m__io->read_bytes (20), std::string ("utf-16le"));
		int l_unknown = 16;
		m_unknown     = std::unique_ptr<std::vector<uint8_t>> (new std::vector<uint8_t> ());
		m_unknown->reserve (l_unknown);
		for (int i = 0; i < l_unknown; i++) {
			m_unknown->push_back (std::move (m__io->read_u1 ()));
		}
		int l_mii_id = 4;
		m_mii_id     = std::unique_ptr<std::vector<uint8_t>> (new std::vector<uint8_t> ());
		m_mii_id->reserve (l_mii_id);
		for (int i = 0; i < l_mii_id; i++) {
			m_mii_id->push_back (std::move (m__io->read_u1 ()));
		}
	}

	gen3_switch_t::~gen3_switch_t () {
		_clean_up ();
	}

	void gen3_switch_t::_clean_up () {
	}
}

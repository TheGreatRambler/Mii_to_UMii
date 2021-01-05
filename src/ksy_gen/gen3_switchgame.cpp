// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "gen3_switchgame.h"
namespace Kaitai {

	gen3_switchgame_t::gen3_switchgame_t (kaitai::kstream* p__io, kaitai::kstruct* p__parent, gen3_switchgame_t* p__root)
		: kaitai::kstruct (p__io) {
		m__parent         = p__parent;
		m__root           = this;
		m_unknown_data    = nullptr;
		m_unknown_buffer  = nullptr;
		m_unknown_buffer2 = nullptr;
		m_unknown_buffer3 = nullptr;
		_read ();
	}

	void gen3_switchgame_t::_read () {
		int l_unknown_data = 16;
		m_unknown_data     = std::unique_ptr<std::vector<uint8_t>> (new std::vector<uint8_t> ());
		m_unknown_data->reserve (l_unknown_data);
		for (int i = 0; i < l_unknown_data; i++) {
			m_unknown_data->push_back (std::move (m__io->read_u1 ()));
		}
		m_mii_name           = kaitai::kstream::bytes_to_str (m__io->read_bytes (20), std::string ("utf-16le"));
		int l_unknown_buffer = 3;
		m_unknown_buffer     = std::unique_ptr<std::vector<uint8_t>> (new std::vector<uint8_t> ());
		m_unknown_buffer->reserve (l_unknown_buffer);
		for (int i = 0; i < l_unknown_buffer; i++) {
			m_unknown_buffer->push_back (std::move (m__io->read_u1 ()));
		}
		m_favorite_color      = m__io->read_u1 ();
		m_gender              = m__io->read_u1 ();
		m_body_height         = m__io->read_u1 ();
		m_body_weight         = m__io->read_u1 ();
		int l_unknown_buffer2 = 2;
		m_unknown_buffer2     = std::unique_ptr<std::vector<uint8_t>> (new std::vector<uint8_t> ());
		m_unknown_buffer2->reserve (l_unknown_buffer2);
		for (int i = 0; i < l_unknown_buffer2; i++) {
			m_unknown_buffer2->push_back (std::move (m__io->read_u1 ()));
		}
		m_face_type            = m__io->read_u1 ();
		m_face_color           = m__io->read_u1 ();
		m_face_wrinkles        = m__io->read_u1 ();
		m_face_makeup          = m__io->read_u1 ();
		m_hair_type            = m__io->read_u1 ();
		m_hair_color           = m__io->read_u1 ();
		m_hair_flip            = m__io->read_u1 ();
		m_eye_type             = m__io->read_u1 ();
		m_eye_color            = m__io->read_u1 ();
		m_eye_size             = m__io->read_u1 ();
		m_eye_stretch          = m__io->read_u1 ();
		m_eye_rotation         = m__io->read_u1 ();
		m_eye_horizontal       = m__io->read_u1 ();
		m_eye_vertical         = m__io->read_u1 ();
		m_eyebrow_type         = m__io->read_u1 ();
		m_eyebrow_color        = m__io->read_u1 ();
		m_eyebrow_size         = m__io->read_u1 ();
		m_eyebrow_stretch      = m__io->read_u1 ();
		m_eyebrow_rotation     = m__io->read_u1 ();
		m_eyebrow_horizontal   = m__io->read_u1 ();
		m_eyebrow_vertical     = m__io->read_u1 ();
		m_nose_type            = m__io->read_u1 ();
		m_nose_size            = m__io->read_u1 ();
		m_nose_vertical        = m__io->read_u1 ();
		m_mouth_type           = m__io->read_u1 ();
		m_mouth_color          = m__io->read_u1 ();
		m_mouth_size           = m__io->read_u1 ();
		m_mouth_stretch        = m__io->read_u1 ();
		m_mouth_vertical       = m__io->read_u1 ();
		m_facial_hair_color    = m__io->read_u1 ();
		m_facial_hair_beard    = m__io->read_u1 ();
		m_facial_hair_mustache = m__io->read_u1 ();
		m_facial_hair_size     = m__io->read_u1 ();
		m_facial_hair_vertical = m__io->read_u1 ();
		m_glasses_type         = m__io->read_u1 ();
		m_glasses_color        = m__io->read_u1 ();
		m_glasses_size         = m__io->read_u1 ();
		m_glasses_vertical     = m__io->read_u1 ();
		m_mole_enable          = m__io->read_u1 ();
		m_mole_size            = m__io->read_u1 ();
		m_mole_horizontal      = m__io->read_u1 ();
		m_mole_vertical        = m__io->read_u1 ();
		int l_unknown_buffer3  = 1;
		m_unknown_buffer3      = std::unique_ptr<std::vector<uint8_t>> (new std::vector<uint8_t> ());
		m_unknown_buffer3->reserve (l_unknown_buffer3);
		for (int i = 0; i < l_unknown_buffer3; i++) {
			m_unknown_buffer3->push_back (std::move (m__io->read_u1 ()));
		}
	}

	gen3_switchgame_t::~gen3_switchgame_t () {
		_clean_up ();
	}

	void gen3_switchgame_t::_clean_up () {
	}
}

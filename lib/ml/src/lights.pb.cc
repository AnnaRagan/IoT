// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: lights.proto

#include "lights.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

class DetectionDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Detection> _instance;
} _Detection_default_instance_;
class ActionDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Action> _instance;
} _Action_default_instance_;
static void InitDefaultsDetection_lights_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_Detection_default_instance_;
    new (ptr) ::Detection();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Detection::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_Detection_lights_2eproto =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsDetection_lights_2eproto}, {}};

static void InitDefaultsAction_lights_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_Action_default_instance_;
    new (ptr) ::Action();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Action::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_Action_lights_2eproto =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsAction_lights_2eproto}, {}};

void InitDefaults_lights_2eproto() {
  ::google::protobuf::internal::InitSCC(&scc_info_Detection_lights_2eproto.base);
  ::google::protobuf::internal::InitSCC(&scc_info_Action_lights_2eproto.base);
}

::google::protobuf::Metadata file_level_metadata_lights_2eproto[2];
constexpr ::google::protobuf::EnumDescriptor const** file_level_enum_descriptors_lights_2eproto = nullptr;
constexpr ::google::protobuf::ServiceDescriptor const** file_level_service_descriptors_lights_2eproto = nullptr;

const ::google::protobuf::uint32 TableStruct_lights_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Detection, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Detection, light_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Action, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Action, type_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::Detection)},
  { 6, -1, sizeof(::Action)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_Detection_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::_Action_default_instance_),
};

::google::protobuf::internal::AssignDescriptorsTable assign_descriptors_table_lights_2eproto = {
  {}, AddDescriptors_lights_2eproto, "lights.proto", schemas,
  file_default_instances, TableStruct_lights_2eproto::offsets,
  file_level_metadata_lights_2eproto, 2, file_level_enum_descriptors_lights_2eproto, file_level_service_descriptors_lights_2eproto,
};

const char descriptor_table_protodef_lights_2eproto[] =
  "\n\014lights.proto\"\032\n\tDetection\022\r\n\005light\030\001 \001"
  "(\t\"\026\n\006Action\022\014\n\004type\030\001 \001(\t2.\n\006Lights\022$\n\007"
  "Connect\022\007.Action\032\n.Detection\"\000(\0010\001b\006prot"
  "o3"
  ;
::google::protobuf::internal::DescriptorTable descriptor_table_lights_2eproto = {
  false, InitDefaults_lights_2eproto, 
  descriptor_table_protodef_lights_2eproto,
  "lights.proto", &assign_descriptors_table_lights_2eproto, 122,
};

void AddDescriptors_lights_2eproto() {
  static constexpr ::google::protobuf::internal::InitFunc deps[1] =
  {
  };
 ::google::protobuf::internal::AddDescriptors(&descriptor_table_lights_2eproto, deps, 0);
}

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_lights_2eproto = []() { AddDescriptors_lights_2eproto(); return true; }();

// ===================================================================

void Detection::InitAsDefaultInstance() {
}
class Detection::HasBitSetters {
 public:
};

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Detection::kLightFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Detection::Detection()
  : ::google::protobuf::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Detection)
}
Detection::Detection(const Detection& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  light_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.light().size() > 0) {
    light_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.light_);
  }
  // @@protoc_insertion_point(copy_constructor:Detection)
}

void Detection::SharedCtor() {
  ::google::protobuf::internal::InitSCC(
      &scc_info_Detection_lights_2eproto.base);
  light_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

Detection::~Detection() {
  // @@protoc_insertion_point(destructor:Detection)
  SharedDtor();
}

void Detection::SharedDtor() {
  light_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void Detection::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Detection& Detection::default_instance() {
  ::google::protobuf::internal::InitSCC(&::scc_info_Detection_lights_2eproto.base);
  return *internal_default_instance();
}


void Detection::Clear() {
// @@protoc_insertion_point(message_clear_start:Detection)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  light_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* Detection::_InternalParse(const char* begin, const char* end, void* object,
                  ::google::protobuf::internal::ParseContext* ctx) {
  auto msg = static_cast<Detection*>(object);
  ::google::protobuf::int32 size; (void)size;
  int depth; (void)depth;
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::ParseFunc parser_till_end; (void)parser_till_end;
  auto ptr = begin;
  while (ptr < end) {
    ptr = ::google::protobuf::io::Parse32(ptr, &tag);
    GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
    switch (tag >> 3) {
      // string light = 1;
      case 1: {
        if (static_cast<::google::protobuf::uint8>(tag) != 10) goto handle_unusual;
        ptr = ::google::protobuf::io::ReadSize(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        ctx->extra_parse_data().SetFieldName("Detection.light");
        object = msg->mutable_light();
        if (size > end - ptr + ::google::protobuf::internal::ParseContext::kSlopBytes) {
          parser_till_end = ::google::protobuf::internal::GreedyStringParserUTF8;
          goto string_till_end;
        }
        GOOGLE_PROTOBUF_PARSER_ASSERT(::google::protobuf::internal::StringCheckUTF8(ptr, size, ctx));
        ::google::protobuf::internal::InlineGreedyStringParser(object, ptr, size, ctx);
        ptr += size;
        break;
      }
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->EndGroup(tag);
          return ptr;
        }
        auto res = UnknownFieldParse(tag, {_InternalParse, msg},
          ptr, end, msg->_internal_metadata_.mutable_unknown_fields(), ctx);
        ptr = res.first;
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr != nullptr);
        if (res.second) return ptr;
      }
    }  // switch
  }  // while
  return ptr;
string_till_end:
  static_cast<::std::string*>(object)->clear();
  static_cast<::std::string*>(object)->reserve(size);
  goto len_delim_till_end;
len_delim_till_end:
  return ctx->StoreAndTailCall(ptr, end, {_InternalParse, msg},
                               {parser_till_end, object}, size);
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool Detection::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Detection)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string light = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (10 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_light()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->light().data(), static_cast<int>(this->light().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "Detection.light"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Detection)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Detection)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void Detection::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Detection)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string light = 1;
  if (this->light().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->light().data(), static_cast<int>(this->light().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "Detection.light");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->light(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Detection)
}

::google::protobuf::uint8* Detection::InternalSerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Detection)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string light = 1;
  if (this->light().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->light().data(), static_cast<int>(this->light().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "Detection.light");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->light(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Detection)
  return target;
}

size_t Detection::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Detection)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string light = 1;
  if (this->light().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->light());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Detection::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Detection)
  GOOGLE_DCHECK_NE(&from, this);
  const Detection* source =
      ::google::protobuf::DynamicCastToGenerated<Detection>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Detection)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Detection)
    MergeFrom(*source);
  }
}

void Detection::MergeFrom(const Detection& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Detection)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.light().size() > 0) {

    light_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.light_);
  }
}

void Detection::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Detection)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Detection::CopyFrom(const Detection& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Detection)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Detection::IsInitialized() const {
  return true;
}

void Detection::Swap(Detection* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Detection::InternalSwap(Detection* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  light_.Swap(&other->light_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::google::protobuf::Metadata Detection::GetMetadata() const {
  ::google::protobuf::internal::AssignDescriptors(&::assign_descriptors_table_lights_2eproto);
  return ::file_level_metadata_lights_2eproto[kIndexInFileMessages];
}


// ===================================================================

void Action::InitAsDefaultInstance() {
}
class Action::HasBitSetters {
 public:
};

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Action::kTypeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Action::Action()
  : ::google::protobuf::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Action)
}
Action::Action(const Action& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  type_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.type().size() > 0) {
    type_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.type_);
  }
  // @@protoc_insertion_point(copy_constructor:Action)
}

void Action::SharedCtor() {
  ::google::protobuf::internal::InitSCC(
      &scc_info_Action_lights_2eproto.base);
  type_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

Action::~Action() {
  // @@protoc_insertion_point(destructor:Action)
  SharedDtor();
}

void Action::SharedDtor() {
  type_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void Action::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Action& Action::default_instance() {
  ::google::protobuf::internal::InitSCC(&::scc_info_Action_lights_2eproto.base);
  return *internal_default_instance();
}


void Action::Clear() {
// @@protoc_insertion_point(message_clear_start:Action)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  type_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* Action::_InternalParse(const char* begin, const char* end, void* object,
                  ::google::protobuf::internal::ParseContext* ctx) {
  auto msg = static_cast<Action*>(object);
  ::google::protobuf::int32 size; (void)size;
  int depth; (void)depth;
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::ParseFunc parser_till_end; (void)parser_till_end;
  auto ptr = begin;
  while (ptr < end) {
    ptr = ::google::protobuf::io::Parse32(ptr, &tag);
    GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
    switch (tag >> 3) {
      // string type = 1;
      case 1: {
        if (static_cast<::google::protobuf::uint8>(tag) != 10) goto handle_unusual;
        ptr = ::google::protobuf::io::ReadSize(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        ctx->extra_parse_data().SetFieldName("Action.type");
        object = msg->mutable_type();
        if (size > end - ptr + ::google::protobuf::internal::ParseContext::kSlopBytes) {
          parser_till_end = ::google::protobuf::internal::GreedyStringParserUTF8;
          goto string_till_end;
        }
        GOOGLE_PROTOBUF_PARSER_ASSERT(::google::protobuf::internal::StringCheckUTF8(ptr, size, ctx));
        ::google::protobuf::internal::InlineGreedyStringParser(object, ptr, size, ctx);
        ptr += size;
        break;
      }
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->EndGroup(tag);
          return ptr;
        }
        auto res = UnknownFieldParse(tag, {_InternalParse, msg},
          ptr, end, msg->_internal_metadata_.mutable_unknown_fields(), ctx);
        ptr = res.first;
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr != nullptr);
        if (res.second) return ptr;
      }
    }  // switch
  }  // while
  return ptr;
string_till_end:
  static_cast<::std::string*>(object)->clear();
  static_cast<::std::string*>(object)->reserve(size);
  goto len_delim_till_end;
len_delim_till_end:
  return ctx->StoreAndTailCall(ptr, end, {_InternalParse, msg},
                               {parser_till_end, object}, size);
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool Action::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Action)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string type = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (10 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_type()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->type().data(), static_cast<int>(this->type().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "Action.type"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Action)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Action)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void Action::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Action)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string type = 1;
  if (this->type().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->type().data(), static_cast<int>(this->type().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "Action.type");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->type(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Action)
}

::google::protobuf::uint8* Action::InternalSerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Action)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string type = 1;
  if (this->type().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->type().data(), static_cast<int>(this->type().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "Action.type");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->type(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Action)
  return target;
}

size_t Action::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Action)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string type = 1;
  if (this->type().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->type());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Action::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Action)
  GOOGLE_DCHECK_NE(&from, this);
  const Action* source =
      ::google::protobuf::DynamicCastToGenerated<Action>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Action)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Action)
    MergeFrom(*source);
  }
}

void Action::MergeFrom(const Action& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Action)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.type().size() > 0) {

    type_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.type_);
  }
}

void Action::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Action)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Action::CopyFrom(const Action& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Action)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Action::IsInitialized() const {
  return true;
}

void Action::Swap(Action* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Action::InternalSwap(Action* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  type_.Swap(&other->type_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::google::protobuf::Metadata Action::GetMetadata() const {
  ::google::protobuf::internal::AssignDescriptors(&::assign_descriptors_table_lights_2eproto);
  return ::file_level_metadata_lights_2eproto[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
template<> PROTOBUF_NOINLINE ::Detection* Arena::CreateMaybeMessage< ::Detection >(Arena* arena) {
  return Arena::CreateInternal< ::Detection >(arena);
}
template<> PROTOBUF_NOINLINE ::Action* Arena::CreateMaybeMessage< ::Action >(Arena* arena) {
  return Arena::CreateInternal< ::Action >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>

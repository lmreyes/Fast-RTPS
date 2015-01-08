/*************************************************************************
 * Copyright (c) 2014 eProsima. All rights reserved.
 *
 * This copy of eProsima Fast RTPS is licensed to you under the terms described in the
 * FASTRTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/**
 * @file ReaderProxyData.h
 *
 */

#ifndef READERPROXYDATA_H_
#define READERPROXYDATA_H_
#ifndef DOXYGEN_SHOULD_SKIP_THIS_PUBLIC

#include "fastrtps/attributes/TopicAttributes.h"
#include "fastrtps/qos/ParameterList.h"
#include "fastrtps/qos/ReaderQos.h"

#include "fastrtps/rtps/attributes/WriterAttributes.h"

using namespace eprosima::fastrtps;

namespace eprosima {
namespace fastrtps{
namespace rtps {

struct CDRMessage_t;

/**
 * Class ReaderProxyData, used to represent all the information on a Reader (both local and remote) with the purpose of
 * implementing the discovery.
 * *@ingroup BUILTIN_MODULE
 */
class ReaderProxyData {
public:
	ReaderProxyData();
	virtual ~ReaderProxyData();
	/**
	 * Convert the data to a parameter list to send this information as a RTPS message.
	 * @return true if correct.
	 */
	bool toParameterList();
	/**
	 *  Read the information from a CDRMessage_t. The position of hte message must be in the beggining on the parameter list.
	 * @param msg Pointer to the message.
	 * @return true on success
	 */
	bool readFromCDRMessage(CDRMessage_t* msg);

	//!GUID
	GUID_t m_guid;
	//!
	bool m_expectsInlineQos;
	//!Unicast locator list
	LocatorList_t m_unicastLocatorList;
	//!Multicast locator list
	LocatorList_t m_multicastLocatorList;
	//!GUID_t of the Reader converted to InstanceHandle_t
	InstanceHandle_t m_key;
	//!GUID_t of the participant converted to InstanceHandle
	InstanceHandle_t m_RTPSParticipantKey;
	//!Type name
	std::string m_typeName;
	//!Topic name
	std::string m_topicName;
	//!User defined ID
	uint16_t m_userDefinedId;
	//!Reader Qos	
	ReaderQos m_qos;
	//!Field to indicate if the Reader is Alive.
	bool m_isAlive;
	//!Topic kind
	TopicKind_t m_topicKind;
	//!Parameter list
	ParameterList_t m_parameterList;
	/**
	 * Clear (put to default) the information.
	 */
	void clear();
	/**
	 * Update the information (only certain fields can be updated).
	 * @param rdata Poitner to the object from which we are going to update.
	 */
	void update(ReaderProxyData* rdata);
	/**
	 * Copy ALL the information from another object.
	 * @param rdata Pointer to the object from where the information must be copied.
	 */
	void copy(ReaderProxyData* rdata);

	/**
	* Convert the ProxyData information to RemoteReaderAttributes object. 
	* @return Reference to the RemoteReaderAttributes object.
	*/
	RemoteReaderAttributes& toRemoteReaderAttributes();

	//!Remote Attributes associated with this proxy data.
	RemoteReaderAttributes m_remoteAtt;
};

}
} /* namespace rtps */
} /* namespace eprosima */

#endif
#endif /* READERPROXYDATA_H_ */
